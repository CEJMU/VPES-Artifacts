add_executable(tlm_at_backpressure
    main.cpp
    initiator.h
    target.h
    ../tlm_memory_manager/memory_manager.cpp
    ../tlm_memory_manager/memory_manager.h
    ../tlm_protocol_checker/tlm2_base_protocol_checker.h
    ../tlm_at_1/util.h
)

target_link_libraries(tlm_at_backpressure
    SystemC::systemc
)
