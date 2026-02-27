add_executable(test_sht31 test_sht31.c)
target_include_directories(test_sht31 PUBLIC .)
target_link_libraries(test_sht31 pico_stdlib hardware_setup sensor_lib)

pico_enable_stdio_usb(test_sht31 1)
pico_enable_stdio_uart(test_sht31 0)
pico_add_extra_outputs(test_sht31)
