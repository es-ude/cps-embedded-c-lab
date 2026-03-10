add_executable(naive_button)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(naive_button PRIVATE ${SRC})
target_include_directories(naive_button PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(naive_button pico_stdlib)

pico_enable_stdio_usb(naive_button 1)
pico_enable_stdio_uart(naive_button 0)
pico_add_extra_outputs(naive_button)