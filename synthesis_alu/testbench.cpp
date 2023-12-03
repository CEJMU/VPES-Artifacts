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
    sc_in<bool> clk;
    sc_signal<bool> reset;
    sc_signal<sc_bv<32>> rs1;
    sc_signal<sc_bv<32>> rs2;
    sc_signal<sc_bv<12>> imm;
    sc_signal<sc_bv<17>> instruction;

    sc_signal<sc_bv<32>> rd;

    alu dut_inst{"dut_inst"};

    SC_CTOR(Tb) {
        dut_inst.clk(clk);
        dut_inst.reset(reset);
        dut_inst.rs1(rs1);
        dut_inst.rs2(rs2);
        dut_inst.imm(imm);
        dut_inst.instruction(instruction);
        dut_inst.rd(rd);

        SC_THREAD(test);
    }

    void test() {
        const unsigned int OP_ADD = 0b00000000000110011;
        const unsigned int OP_AND = 0b00000001110110011;
        const unsigned int OP_MUL = 0b00000010000110011;
        const unsigned int OP_SLL = 0b00000000010110011;
        const unsigned int OP_SRA = 0b01000001010110011;
        const unsigned int OP_ADDI = 0b00000000000010011;
        const unsigned int OP_LW = 0b00000000000000011;
        const unsigned int OP_SW = 0b00000000000100011;
        const unsigned int OP_BNE = 0b00000000001100011;

        reset.write(false);

        // ============================ MUL ============================
        rs1.write(20);
        rs2.write(2);
        imm.write(0xFFF);
        instruction.write(OP_MUL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " * " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(20);
        rs2.write(-100);
        imm.write(0xFFF);
        instruction.write(OP_MUL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " * " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(65535); // overflow after MUL
        rs2.write(65536);
        imm.write(0xFFF);
        instruction.write(OP_MUL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " * " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(65536); // overflow after MUL
        rs2.write(65536);
        imm.write(0xFFF);
        instruction.write(OP_MUL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " * " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        // ============================ ADD ============================
        rs1.write(100);
        rs2.write(27);
        imm.write(0xFFF);
        instruction.write(OP_ADD);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " + " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(110);
        rs2.write(-27);
        imm.write(0xFFF);
        instruction.write(OP_ADD);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " + " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(0);
        rs2.write(-2);
        imm.write(0xFFF);
        instruction.write(OP_ADD);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " + " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(-2147483648);
        rs2.write(-1);
        imm.write(0xFFF);
        instruction.write(OP_ADD);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " + " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        // ============================ RESET ============================
        reset.write(true);
        cout << sc_time_stamp() << ": Performing reset" << endl;
        wait(SC_ZERO_TIME);
        cout << sc_time_stamp() << ": reset done" << endl;
        reset.write(false);
        wait(SC_ZERO_TIME);

        // ============================ SLL ============================
        rs1.write(20);
        rs2.write(2);
        imm.write(0xFFF);
        instruction.write(OP_SLL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " << " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(1);
        rs2.write(30);
        imm.write(0xFFF);
        instruction.write(OP_SLL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " << " << rs2.read().to_uint() << " = "
             << rd.read().to_int() << endl;

        rs1.write(1);
        rs2.write(31);
        imm.write(0xFFF);
        instruction.write(OP_SLL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " << " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(1);
        rs2.write(32);
        imm.write(0xFFF);
        instruction.write(OP_SLL);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " << " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        // ============================ SRA ============================
        rs1.write(-17);
        rs2.write(1);
        imm.write(0xFFF);
        instruction.write(OP_SRA);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " >> " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(40);
        rs2.write(2);
        imm.write(0xFFF);
        instruction.write(OP_SRA);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " >> " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        rs1.write(65536);
        rs2.write(10);
        imm.write(0xFFF);
        instruction.write(OP_SRA);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " >> " << rs2.read().to_int() << " = "
             << rd.read().to_int() << endl;

        // ============================ AND ============================
        rs1.write(20);
        rs2.write(17);
        imm.write(0xFFF);
        instruction.write(OP_AND);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read() << " & " << rs2.read() << " = " << rd.read() << endl;

        rs1.write(0b10101010101010101010101010101010);
        rs2.write(0b01010101010101010101010101010101);
        imm.write(0xFFF);
        instruction.write(OP_AND);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read() << " & " << rs2.read() << " = " << rd.read() << endl;

        rs1.write(0xABCDEF01);
        rs2.write(0xABCDEF01);
        imm.write(0xFFF);
        instruction.write(OP_AND);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read() << " & " << rs2.read() << " = " << rd.read() << endl;

        // ============================ BNE ============================
        rs1.write(10);
        rs2.write(10);
        imm.write(0xFFF);
        instruction.write(OP_BNE);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " == " << rs2.read().to_int() << ": "
             << (bool)rd.read().to_int() << endl;

        rs1.write(10);
        rs2.write(11);
        imm.write(0xFFF);
        instruction.write(OP_BNE);
        wait(sc_time(20, SC_NS));
        cout << sc_time_stamp() << ": ";
        cout << rs1.read().to_int() << " == " << rs2.read().to_int() << ": "
             << (bool)rd.read().to_int() << endl;

        sc_stop();
    }
};

int sc_main(int argc, char **argv) {
    Tb tb("tb");
    sc_clock my_clock("clock", 10, SC_NS, 0.5, 0, SC_NS, false);
    tb.clk(my_clock);
    sc_start();

    return 0;
}
