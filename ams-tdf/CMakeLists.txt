add_executable(ams-tdf
    tdf.cpp
)

find_library(SYSTEMC_AMS_LIBRARY 
    NAMES systemc-ams
    PATHS ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/lib/
)

target_include_directories(ams-tdf
    PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/include
)

target_link_libraries(ams-tdf
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
