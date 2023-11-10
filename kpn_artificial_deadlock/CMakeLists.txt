add_executable(kpn_artificial_deadlock
    main.cpp
    kpn.cpp
    kpn.h
    utils.h
)

target_link_libraries(kpn_artificial_deadlock
    SystemC::systemc
)
