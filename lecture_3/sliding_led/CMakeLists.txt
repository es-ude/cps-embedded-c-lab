add_executable(sliding_led)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(sliding_led PRIVATE ${SRC})
target_include_directories(sliding_led PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(sliding_led pico_stdlib)

pico_enable_stdio_usb(sliding_led 1)
pico_enable_stdio_uart(sliding_led 0)
pico_add_extra_outputs(sliding_led)