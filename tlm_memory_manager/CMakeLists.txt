add_executable(tlm_memory_manager
    main.cpp
    memory_manager.cpp
    memory_manager.h
)

target_link_libraries(tlm_memory_manager
    SystemC::systemc
)
