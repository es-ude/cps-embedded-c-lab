add_executable(increasing_led)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(increasing_led PRIVATE ${SRC})
target_include_directories(increasing_led PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(increasing_led pico_stdlib)

pico_enable_stdio_usb(increasing_led 1)
pico_enable_stdio_uart(increasing_led 0)
pico_add_extra_outputs(increasing_led)