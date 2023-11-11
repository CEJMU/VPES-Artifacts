add_executable(ams-eln
    eln.cpp
)

target_include_directories(ams-eln
    PRIVATE ${SYSTEMC_AMS_INCLUDE}
)

target_link_libraries(ams-eln
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
