add_executable(ams-tdf
    tdf.cpp
)

target_include_directories(ams-tdf 
    PUBLIC ${systemc_ams_SOURCE_DIR}/src
)

target_link_libraries(ams-tdf
    SystemC::systemc
    systemc-ams
)
