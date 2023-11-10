add_executable(clock_generator
    main.cpp
)

target_link_libraries(clock_generator
    SystemC::systemc
)
