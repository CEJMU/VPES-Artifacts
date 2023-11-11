add_executable(ams-lsf2
    ltf_nd_filter.cpp
    ltf_pid.cpp
    pid_controller.cpp
    sc_main.cpp
)

find_library(SYSTEMC_AMS_LIBRARY 
    NAMES systemc-ams
    PATHS ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/lib/
)

find_library(SYSTEMC_AMS_LIBRARY 
    NAMES systemc-ams
    PATHS ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/lib/
)

target_include_directories(ams-lsf2
    PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/include
)

target_link_libraries(ams-lsf2
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
