// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"



// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_rr_arbiter.configure(this, name(), "rr_arbiter", "rr_arbiter", -12, VerilatedScope::SCOPE_MODULE);
    __Vscope_rr_arbiter__unnamedblk2.configure(this, name(), "rr_arbiter.unnamedblk2", "unnamedblk2", -12, VerilatedScope::SCOPE_OTHER);
    
    // Setup scope hierarchy
    __Vhier.add(0, &__Vscope_rr_arbiter);
    
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"arst", &(TOPp->arst), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOPp->clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"grant_o", &(TOPp->grant_o), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"req_i", &(TOPp->req_i), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,1 ,7,0);
        __Vscope_TOP.varInsert(__Vfinal,"update_i", &(TOPp->update_i), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"arst", &(TOPp->rr_arbiter__DOT__arst), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"clk", &(TOPp->rr_arbiter__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"grant_ff", &(TOPp->rr_arbiter__DOT__grant_ff), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"grant_o", &(TOPp->rr_arbiter__DOT__grant_o), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"mask_ff", &(TOPp->rr_arbiter__DOT__mask_ff), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"next_grant", &(TOPp->rr_arbiter__DOT__next_grant), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"next_mask", &(TOPp->rr_arbiter__DOT__next_mask), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"req_i", &(TOPp->rr_arbiter__DOT__req_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,7,0);
        __Vscope_rr_arbiter.varInsert(__Vfinal,"update_i", &(TOPp->rr_arbiter__DOT__update_i), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0);
        __Vscope_rr_arbiter__unnamedblk2.varInsert(__Vfinal,"i", &(TOPp->rr_arbiter__DOT__unnamedblk2__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY,1 ,31,0);
    }
}
