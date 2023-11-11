add_executable(ams-lsf2
    ltf_nd_filter.cpp
    ltf_pid.cpp
    pid_controller.cpp
    sc_main.cpp
)

target_include_directories(ams-lsf2
    PUBLIC ${systemc_ams_SOURCE_DIR}/src
)

target_link_libraries(ams-lsf2
    SystemC::systemc
    systemc-ams
)
