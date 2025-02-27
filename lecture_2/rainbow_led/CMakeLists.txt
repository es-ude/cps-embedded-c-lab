add_executable(rainbow_led)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(rainbow_led PRIVATE ${SRC})
target_include_directories(rainbow_led PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(rainbow_led pico_stdlib hardware_pwm pico_float)

pico_enable_stdio_usb(rainbow_led 1)
pico_enable_stdio_uart(rainbow_led 0)
pico_add_extra_outputs(rainbow_led)