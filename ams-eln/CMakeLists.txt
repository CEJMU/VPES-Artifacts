add_executable(ams-eln
    eln.cpp
)

find_library(SYSTEMC_AMS_LIBRARY 
    NAMES systemc-ams
    CMakeLists.txt install_ams.sh   PATHS ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/lib/
)

target_include_directories(ams-eln
    PRIVATE ${CMAKE_SOURCE_DIR}/build/_deps/systemc-ams/include
)

target_link_libraries(ams-eln
    PRIVATE ${SYSTEMC_AMS_LIBRARY}
    SystemC::systemc
)
