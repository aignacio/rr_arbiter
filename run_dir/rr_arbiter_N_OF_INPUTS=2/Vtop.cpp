// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/rr_arb/rtl/rr_arbiter.sv", 25, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/rr_arb/rtl/rr_arbiter.sv", 25, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rr_arbiter__DOT__clk = vlTOPp->clk;
    vlTOPp->rr_arbiter__DOT__arst = vlTOPp->arst;
    vlTOPp->rr_arbiter__DOT__update_i = vlTOPp->update_i;
    vlTOPp->rr_arbiter__DOT__req_i = vlTOPp->req_i;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->arst) {
        vlTOPp->rr_arbiter__DOT__grant_ff = 0U;
        vlTOPp->rr_arbiter__DOT__mask_ff = 3U;
    } else {
        vlTOPp->rr_arbiter__DOT__grant_ff = vlTOPp->rr_arbiter__DOT__next_grant;
        vlTOPp->rr_arbiter__DOT__mask_ff = vlTOPp->rr_arbiter__DOT__next_mask;
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    if ((((IData)(vlTOPp->arst) & (~ (IData)(vlTOPp->__Vclklast__TOP__arst))) 
         | ((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__arst = vlTOPp->arst;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((arst & 0xfeU))) {
        Verilated::overWidthError("arst");}
    if (VL_UNLIKELY((update_i & 0xfeU))) {
        Verilated::overWidthError("update_i");}
    if (VL_UNLIKELY((req_i & 0xfcU))) {
        Verilated::overWidthError("req_i");}
}
#endif  // VL_DEBUG
