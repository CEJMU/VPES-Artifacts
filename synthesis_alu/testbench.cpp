/******************************************************************************
 * Copyright (c) 2020, Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception.
 *
 *****************************************************************************/

// Design template

#include "alu.cpp"
#include <systemc.h>

// ICSC requires DUT top should be instantiated inside wrapper (typically TB)
// and all DUT ports are bound.
struct Tb : sc_module {
    sc_signal<sc_bv<4>> a;
    sc_signal<sc_bv<4>> b;
    sc_signal<sc_bv<3>> opcode;

    sc_signal<sc_bv<4>> z;

    alu dut_inst{"dut_inst"};

    SC_CTOR(Tb) {
        dut_inst.a(a);
        dut_inst.b(b);
        dut_inst.opcode(opcode);
        dut_inst.z(z);

        SC_THREAD(test);
    }

    void test() {
        // ============================ ADD ============================
        a.write(4);
        b.write(-3);
        opcode.write(alu::ADD);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " + " << b.read().to_int() << " = "
             << z.read().to_int() << endl;

        a.write(1);
        b.write(5);
        opcode.write(alu::ADD);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " + " << b.read().to_int() << " = "
             << z.read().to_int() << endl;

        // ============================ MUL ============================
        a.write(3);
        b.write(2);
        opcode.write(alu::MUL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " * " << b.read().to_int() << " = "
             << z.read().to_int() << endl;

        a.write(-1);
        b.write(6);
        opcode.write(alu::MUL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " * " << b.read().to_int() << " = "
             << z.read().to_int() << endl;

        // ============================ SLL ============================
        a.write(1);
        b.write(2);
        opcode.write(alu::SLL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " << " << b.read().to_int() << " = "
             << z.read().to_int() << endl;

        // ============================ SRA ============================
        a.write(-8);
        b.write(1);
        opcode.write(alu::SRA);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " >> " << b.read().to_int() << " = "
             << z.read().to_int() << endl;

        // ============================ AND ============================
        a.write(0b1010);
        b.write(0b0110);
        opcode.write(alu::AND);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read() << " & " << b.read() << " = " << z.read() << endl;

        // ============================ SLT ============================
        a.write(4);
        b.write(5);
        opcode.write(alu::SLT);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " < " << b.read().to_int() << ": "
             << (bool)z.read().to_int() << endl;

        a.write(5);
        b.write(5);
        opcode.write(alu::SLT);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << a.read().to_int() << " < " << b.read().to_int() << ": "
             << (bool)z.read().to_int() << endl;

        sc_stop();
    }
};

int sc_main(int argc, char **argv) {
    Tb tb("tb");
    sc_start();

    return 0;
}
