#ifndef NAND_GATE_H
#define NAND_GATE_H

#include <systemc.h>

SC_MODULE(nand_gate){
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    void do_nand() {
        Z.write(!(A.read() && B.read()));
    }

    SC_CTOR(nand_gate): A("A"), B("B"), Z("Z") {
        SC_METHOD(do_nand);
        sensitive << A << B;
    }
};

#endif
