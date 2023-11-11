add_executable(ams-eln
    eln.cpp
)

target_include_directories(ams-eln 
    PUBLIC ${systemc_ams_SOURCE_DIR}/src
)

target_link_libraries(ams-eln
    SystemC::systemc
    systemc-ams
)
