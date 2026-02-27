add_executable(test_hello test_hello.c)
target_include_directories(test_hello PUBLIC .)
target_link_libraries(test_hello pico_stdlib)

pico_enable_stdio_usb(test_hello 1)
pico_enable_stdio_uart(test_hello 0)
pico_add_extra_outputs(test_hello)
