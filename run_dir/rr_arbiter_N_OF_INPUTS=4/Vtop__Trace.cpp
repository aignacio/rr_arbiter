// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedFst* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->arst));
        tracep->chgBit(oldp+2,(vlTOPp->update_i));
        tracep->chgCData(oldp+3,(vlTOPp->req_i),4);
        tracep->chgCData(oldp+4,(vlTOPp->grant_o),4);
        tracep->chgBit(oldp+5,(vlTOPp->rr_arbiter__DOT__clk));
        tracep->chgBit(oldp+6,(vlTOPp->rr_arbiter__DOT__arst));
        tracep->chgBit(oldp+7,(vlTOPp->rr_arbiter__DOT__update_i));
        tracep->chgCData(oldp+8,(vlTOPp->rr_arbiter__DOT__req_i),4);
        tracep->chgCData(oldp+9,(vlTOPp->rr_arbiter__DOT__grant_o),4);
        tracep->chgCData(oldp+10,(vlTOPp->rr_arbiter__DOT__mask_ff),4);
        tracep->chgCData(oldp+11,(vlTOPp->rr_arbiter__DOT__next_mask),4);
        tracep->chgCData(oldp+12,(vlTOPp->rr_arbiter__DOT__grant_ff),4);
        tracep->chgCData(oldp+13,(vlTOPp->rr_arbiter__DOT__next_grant),4);
        tracep->chgIData(oldp+14,(vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i),32);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedFst* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
