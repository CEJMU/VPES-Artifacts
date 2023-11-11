add_executable(ams-lsf
    lsf.cpp
)

target_include_directories(ams-lsf
    PUBLIC ${systemc_ams_SOURCE_DIR}/src
)

target_link_libraries(ams-lsf
    SystemC::systemc
    systemc-ams
)
