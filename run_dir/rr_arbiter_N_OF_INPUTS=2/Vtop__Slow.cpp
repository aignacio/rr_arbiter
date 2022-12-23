// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rr_arbiter__DOT__clk = vlTOPp->clk;
    vlTOPp->rr_arbiter__DOT__arst = vlTOPp->arst;
    vlTOPp->rr_arbiter__DOT__update_i = vlTOPp->update_i;
    vlTOPp->rr_arbiter__DOT__req_i = vlTOPp->req_i;
    vlTOPp->rr_arbiter__DOT__next_mask = vlTOPp->rr_arbiter__DOT__mask_ff;
    vlTOPp->rr_arbiter__DOT__next_grant = vlTOPp->rr_arbiter__DOT__grant_ff;
    vlTOPp->rr_arbiter__DOT__grant_o = vlTOPp->rr_arbiter__DOT__grant_ff;
    if (vlTOPp->update_i) {
        vlTOPp->rr_arbiter__DOT__next_grant = 0U;
        vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i = 0U;
        {
            while (VL_GTS_III(1,32,32, 2U, vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i)) {
                if ((1U & ((IData)(vlTOPp->req_i) >> 
                           (1U & vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i)))) {
                    if ((1U & ((IData)(vlTOPp->rr_arbiter__DOT__mask_ff) 
                               >> (1U & vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i)))) {
                        vlTOPp->rr_arbiter__DOT__next_grant 
                            = ((IData)(vlTOPp->rr_arbiter__DOT__next_grant) 
                               | ((IData)(1U) << (1U 
                                                  & vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i)));
                        vlTOPp->rr_arbiter__DOT__next_mask 
                            = ((~ ((IData)(1U) << (1U 
                                                   & vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i))) 
                               & (IData)(vlTOPp->rr_arbiter__DOT__next_mask));
                        goto __Vlabel1;
                    } else {
                        vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__ones = 0U;
                        vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__ones 
                            = (vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__ones 
                               + (1U & (IData)(vlTOPp->req_i)));
                        vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__ones 
                            = (vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__ones 
                               + (1U & ((IData)(vlTOPp->req_i) 
                                        >> 1U)));
                        vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__Vfuncout 
                            = vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__ones;
                        if ((1U == vlTOPp->__Vfunc_rr_arbiter__DOT__count_ones__0__Vfuncout)) {
                            vlTOPp->rr_arbiter__DOT__next_grant 
                                = ((IData)(vlTOPp->rr_arbiter__DOT__next_grant) 
                                   | ((IData)(1U) << 
                                      (1U & vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i)));
                        }
                    }
                } else {
                    vlTOPp->rr_arbiter__DOT__next_mask 
                        = ((IData)(vlTOPp->rr_arbiter__DOT__next_mask) 
                           | ((IData)(1U) << (1U & vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i)));
                }
                vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i 
                    = ((IData)(1U) + vlTOPp->rr_arbiter__DOT__unnamedblk2__DOT__i);
            }
            __Vlabel1: ;
        }
        if ((0U == (IData)(vlTOPp->rr_arbiter__DOT__next_mask))) {
            vlTOPp->rr_arbiter__DOT__next_mask = 3U;
        }
    }
    vlTOPp->grant_o = vlTOPp->rr_arbiter__DOT__grant_o;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__arst = vlTOPp->arst;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    arst = VL_RAND_RESET_I(1);
    update_i = VL_RAND_RESET_I(1);
    req_i = VL_RAND_RESET_I(2);
    grant_o = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__clk = VL_RAND_RESET_I(1);
    rr_arbiter__DOT__arst = VL_RAND_RESET_I(1);
    rr_arbiter__DOT__update_i = VL_RAND_RESET_I(1);
    rr_arbiter__DOT__req_i = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__grant_o = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__mask_ff = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__next_mask = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__grant_ff = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__next_grant = VL_RAND_RESET_I(2);
    rr_arbiter__DOT__unnamedblk2__DOT__i = 0;
    __Vfunc_rr_arbiter__DOT__count_ones__0__Vfuncout = 0;
    __Vfunc_rr_arbiter__DOT__count_ones__0__ones = 0;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
