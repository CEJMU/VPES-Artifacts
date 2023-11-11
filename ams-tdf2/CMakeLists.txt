add_executable(ams-tdf2
    tdf2.cpp
)

target_include_directories(ams-tdf2
    PUBLIC ${systemc_ams_SOURCE_DIR}/src
)

target_link_libraries(ams-tdf2
    SystemC::systemc
    systemc-ams
)
