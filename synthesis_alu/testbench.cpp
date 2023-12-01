/******************************************************************************
 * Copyright (c) 2020, Intel Corporation. All rights reserved.
 * 
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception.
 * 
 *****************************************************************************/

// Design template

#include <systemc.h>
#include "alu.cpp"
 
// ICSC requires DUT top should be instantiated inside wrapper (typically TB) 
// and all DUT ports are bound.
struct Tb : sc_module 
{
    sc_signal<bool> a{"a"};
    
    sc_signal<bool> b{"b"};
    sc_signal<bool> z{"z"};
 
    alu dut_inst{"dut_inst"};

    SC_CTOR(Tb) 
    {
        dut_inst.A(a);
        dut_inst.B(b);
        dut_inst.Z(z);
    }
};
 
int sc_main (int argc, char **argv)
{
     Tb tb("tb");
     sc_start();
     return 0;
}
