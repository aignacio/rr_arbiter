#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File              : test_rr_arbiter.py
# License           : MIT license <Check LICENSE>
# Author            : Anderson Ignacio da Silva (aignacio) <anderson@aignacio.com>
# Date              : 12.05.2021
# Last Modified Date: 24.12.2022
# Last Modified By  : Anderson Ignacio da Silva (aignacio) <anderson@aignacio.com>
import random
import cocotb
import os
import logging
import pytest

from logging.handlers import RotatingFileHandler
from cocotb.log import SimColourLogFormatter, SimLog, SimTimeContextFilter
from cocotb.regression import TestFactory
from cocotb_test.simulator import run
from cocotb.regression import TestFactory
from cocotb.clock import Clock
from cocotb_bus.drivers import Driver
from cocotb.triggers import ClockCycles, FallingEdge, RisingEdge, Timer
from collections import namedtuple

CLK_100MHz = (10, "ns")
RST_CYCLES = 2

async def setup_dut(dut):
    dut._log.info("Configuring clock")
    dut._log.info("100MHz - clk")
    cocotb.fork(Clock(dut.clk, *CLK_100MHz).start())

async def reset_dut(dut):
    dut._log.info("Reseting DUT")
    dut.arst.setimmediatevalue(1)
    await ClockCycles(dut.clk, RST_CYCLES)
    dut.arst.setimmediatevalue(0)

def onehot(val, max_int):
    print("Val=%d"%val)
    for i in range(0, 2**(max_int-1)+1):
        if (val == i):
            return True
    return False

async def run_test(dut):
    inputs = int(os.environ['PARAM_N_OF_INPUTS'])
    runs   = int(os.environ['TEST_RUNS'])

    dut.update_i.setimmediatevalue(0)
    dut.req_i.setimmediatevalue(0)

    await setup_dut(dut)
    await reset_dut(dut)

    for i in range((2**inputs)):
        # Start testing
        await ClockCycles(dut.clk, 1)
        dut.req_i.setimmediatevalue(i)

        for i in range(5*inputs):
            dut.update_i.setimmediatevalue(1)
            await ClockCycles(dut.clk, 1)
            dut.update_i.setimmediatevalue(0)
            await ClockCycles(dut.clk, 2)
            assert onehot(dut.grant_o, inputs), "Grant is not one-hot encoding"

if cocotb.SIM_NAME:
    factory = TestFactory(run_test)
    factory.generate_tests()

@pytest.mark.parametrize("n_of_inputs",[2,4,8])
def test_2ff(n_of_inputs):
    tests_dir = os.path.dirname(os.path.abspath(__file__))
    rtl_dir   = tests_dir
    dut = "rr_arbiter"
    module = os.path.splitext(os.path.basename(__file__))[0]
    toplevel = dut
    verilog_sources = [
        os.path.join(rtl_dir, f"../rtl/{dut}.sv"),
    ]
    parameters = {}
    parameters['N_OF_INPUTS'] = n_of_inputs

    extra_env = {f'PARAM_{k}': str(v) for k, v in parameters.items()}
    extra_env['TEST_RUNS'] = str(random.randint(5,10))
    extra_env['COCOTB_HDL_TIMEUNIT'] = "1ns"
    extra_env['COCOTB_HDL_TIMEPRECISION'] = "1ps"

    sim_build = os.path.join(tests_dir, "../run_dir/rr_arbiter_"+"_".join(("{}={}".format(*i) for i in parameters.items())))

    run(
        python_search=[tests_dir],
        verilog_sources=verilog_sources,
        toplevel=toplevel,
        module=module,
        parameters=parameters,
        sim_build=sim_build,
        extra_env=extra_env,
        extra_args=["--trace-fst","--trace-structs"]
    )
