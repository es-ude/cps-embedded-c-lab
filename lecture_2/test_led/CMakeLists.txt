add_executable(test_led test_led.c)
target_include_directories(test_led PUBLIC .)
target_link_libraries(test_led pico_stdlib)

pico_enable_stdio_usb(test_led 1)
pico_enable_stdio_uart(test_led 0)
pico_add_extra_outputs(test_led)
