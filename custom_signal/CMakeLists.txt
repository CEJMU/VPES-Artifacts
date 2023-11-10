add_executable(custom_signal
    main.cpp
    signal.h
)

target_link_libraries(custom_signal
    SystemC::systemc
)
