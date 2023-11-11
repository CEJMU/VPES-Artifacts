add_executable(ams-tdf
    tdf.cpp
)

target_include_directories(ams-tdf
    PRIVATE ${SYSTEMC_AMS_INCLUDE}
)

target_link_libraries(ams-tdf
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
