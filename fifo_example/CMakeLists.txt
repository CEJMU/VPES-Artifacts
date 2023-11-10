add_executable(fifo_example
    main.cpp
    consumer.cpp
    consumer.h
    producer.cpp
    producer.h
)

target_link_libraries(fifo_example
    SystemC::systemc
)
