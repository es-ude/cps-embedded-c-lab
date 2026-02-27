add_executable(i2c_bus_scan i2c_bus_scan.c)
target_include_directories(i2c_bus_scan PUBLIC .)
target_link_libraries(i2c_bus_scan pico_stdlib hardware_i2c sensor_lib)

pico_enable_stdio_usb(i2c_bus_scan 1)
pico_enable_stdio_uart(i2c_bus_scan 0)
pico_add_extra_outputs(i2c_bus_scan)
