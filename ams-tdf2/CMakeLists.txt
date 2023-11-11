add_executable(ams-tdf2
    tdf2.cpp
)

find_library(SYSTEMC_AMS_LIBRARY 
    NAMES systemc-ams
    PATHS ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/lib/
)

target_include_directories(ams-tdf2
    PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/include
)

target_link_libraries(ams-tdf2
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
