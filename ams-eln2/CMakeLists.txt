add_executable(ams-eln2
    eln.cpp
)

target_include_directories(ams-eln2
    PUBLIC ${systemc_ams_SOURCE_DIR}/src
)

target_link_libraries(ams-eln2
    SystemC::systemc
    systemc-ams
)
