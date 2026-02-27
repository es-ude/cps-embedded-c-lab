add_executable(test_echo test_echo.c)
target_include_directories(test_echo PUBLIC .)
target_link_libraries(test_echo pico_stdlib)

pico_enable_stdio_usb(test_echo 1)
pico_enable_stdio_uart(test_echo 0)
pico_add_extra_outputs(test_echo)
