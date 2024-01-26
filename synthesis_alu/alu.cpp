#include <iostream>
#include <systemc.h>

using namespace std;

SC_MODULE(alu) {
    sc_in<sc_bv<4>> a;
    sc_in<sc_bv<4>> b;
    sc_in<sc_bv<3>> opcode;

    sc_out<sc_bv<4>> z;

    enum OPCODES {
        ADD = 0b000, // a + b
        MUL = 0b001, // a * b
        AND = 0b010, // a & b
        SLL = 0b011, // a << b
        SRA = 0b100, // a >> b
        SLT = 0b101  // (a < b) ? 1 : 0
    };

    void process() {
        switch (opcode.read().to_uint()) {
        case ADD:
            z.write(a.read().to_int() + b.read().to_int());
            break;

        case MUL:
            z.write(a.read().to_int() * b.read().to_int());
            break;

        case AND:
            z.write(a.read().to_int() & b.read().to_int());
            break;

        case SLL:
            z.write(a.read().to_int() << b.read().to_uint());
            break;

        case SRA:
            z.write(a.read().to_int() >> b.read().to_uint());
            break;

        case SLT:
            z.write((a.read().to_int() < b.read().to_int()) ? 1 : 0);
            break;

        default:
            z.write(0);
        }
    }

    SC_CTOR(alu) : a("a"), b("b"), opcode("opcode"), z("z") {

        SC_METHOD(process);
        sensitive << a << b << opcode;
    }
};
