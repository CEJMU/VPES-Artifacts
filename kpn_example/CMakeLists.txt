add_executable(kpn_example
    main.cpp
    kpn.cpp
    kpn.h
)

target_link_libraries(kpn_example
    SystemC::systemc
)
