add_executable(ams-eln2
    eln.cpp
)

find_library(SYSTEMC_AMS_LIBRARY 
    NAMES systemc-ams
    PATHS ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/lib/
)

target_include_directories(ams-eln2
    PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/include
)

target_link_libraries(ams-eln2
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
