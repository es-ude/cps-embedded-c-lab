add_executable(custom_effect)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(custom_effect PRIVATE ${SRC})
target_include_directories(custom_effect PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(custom_effect pico_stdlib)

pico_enable_stdio_usb(custom_effect 1)
pico_enable_stdio_uart(custom_effect 0)
pico_add_extra_outputs(custom_effect)