add_executable(tlm_cpu_example
    main.cpp
    cpu.h
    memory.h
)

#assembler.pl
#test.asm

target_link_libraries(tlm_cpu_example
    SystemC::systemc
)
