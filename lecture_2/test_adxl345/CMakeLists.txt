add_executable(test_adxl345 test_adxl345.c)
target_include_directories(test_adxl345 PUBLIC .)
target_link_libraries(test_adxl345 pico_stdlib hardware_setup sensor_lib)

pico_enable_stdio_usb(test_adxl345 1)
pico_enable_stdio_uart(test_adxl345 0)
pico_add_extra_outputs(test_adxl345)
