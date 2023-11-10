add_executable(event_finder
    main.cpp
    ../custom_signal/signal.h
)

target_link_libraries(event_finder
    SystemC::systemc
)
