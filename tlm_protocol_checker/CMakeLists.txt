add_executable(tlm_protocol_checker
    main.cpp
    tlm2_base_protocol_checker.h
)

target_link_libraries(tlm_protocol_checker
    SystemC::systemc
)
