add_executable(test_pac193x test_pac193x.c)
target_include_directories(test_pac193x PUBLIC .)
target_link_libraries(test_pac193x pico_stdlib hardware_setup sensor_lib)

pico_enable_stdio_usb(test_pac193x 1)
pico_enable_stdio_uart(test_pac193x 0)
pico_add_extra_outputs(test_pac193x)
