add_executable(nb_fifo_example
    main.cpp
    consumer.cpp
    consumer.h
    producer.cpp
    producer.h
)

target_link_libraries(nb_fifo_example
    SystemC::systemc
)
