#include <systemc.h>

SC_MODULE(alu) {
  sc_in<bool> clk;
  sc_in<bool> reset;
  sc_in<sc_bv<32>> rs1;
  sc_in<sc_bv<32>> rs2;
  sc_in<sc_bv<12>> imm;
  // HACK: 17 ist blöde Größe
  sc_in<sc_bv<17>> instruction;
  sc_in<sc_bv<32>> rd;

  void do_alu() {}

  SC_CTOR(alu)
      : clk("clk"), reset("reset"), rs1("rs1"), rs2("rs2"), imm("imm"),
        instruction("instruction"), rd("rd") {
    SC_METHOD(do_alu);
    sensitive << clk << reset;
  }
};
