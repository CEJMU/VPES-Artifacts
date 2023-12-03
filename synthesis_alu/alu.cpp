#include <iostream>
#include <systemc.h>

using namespace std;

SC_MODULE(alu) {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_bv<32>> rs1;
    sc_in<sc_bv<32>> rs2;
    sc_in<sc_bv<12>> imm;
    sc_in<sc_bv<17>> instruction;

    sc_out<sc_bv<32>> rd;

    void do_alu() {
        while (true) {
            wait();
            if (reset) {
                rd.write(0);
            } else {
                sc_bv<7> opcode = instruction.read().range(6, 0);
                sc_bv<10> funct73 = instruction.read().range(16, 7);
                if (opcode == 0b0110011) {         // R-Type
                    if (funct73 == 0b0000000000) { // ADD
                        rd.write(rs1.read().to_int() + rs2.read().to_int());

                    } else if (funct73 == 0b0000000111) { // AND
                        rd.write(rs1.read().to_uint() & rs2.read().to_uint());

                    } else if (funct73 == 0b0000001000) { // MUL
                        rd.write(rs1.read().to_int() * rs2.read().to_int());

                    } else if (funct73 == 0b0000000001) { // SLL
                        rd.write(rs1.read().to_int()
                                 << rs2.read().range(4, 0).to_uint());

                    } else if (funct73 == 0b0100000101) { // SRA
                        rd.write(rs1.read().to_int() >>
                                 rs2.read().range(4, 0).to_uint());

                    } else {
                        rd.write(0);
                    }
                } else if (opcode == 0b0010011) { // ADDI
                    rd.write(rs1.read().to_int() + imm.read().to_int());
                } else if (opcode == 0b0000011) { // LW
                    rd.write(rs1.read().to_int() + imm.read().to_int());
                } else if (opcode == 0b0100011) { // SW
                    rd.write(rs1.read().to_int() + imm.read().to_int());
                } else if (opcode == 0b1100011) { // BNE
                    sc_bv<32> temp;
                    temp.range(31, 2) = 0;

                    if (rs1.read() == rs2.read()) {
                        temp.range(1, 0) = 0b10;
                    } else {
                        temp.range(1, 0) = 0b00;
                    }

                    rd.write(temp);
                } else {
                    rd.write(0);
                }
            }
        }
    }

    SC_CTOR(alu)
        : clk("clk"), reset("reset"), rs1("rs1"), rs2("rs2"), imm("imm"),
          instruction("instruction"), rd("rd") {

        // We are using a SC_CTHREAD here. According to the SystemC synthesis
        // specification SC_METHOD should be okay too. The Intel compiler seems
        // to always infer combinational logic from SC_METHOD however. This is
        // also stated in their user manual
        SC_CTHREAD(do_alu, clk.pos());
        async_reset_signal_is(reset, true);
    }
};
