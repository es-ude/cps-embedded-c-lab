### Simple ###

add_executable(simple)

target_sources(simple PRIVATE simple.c)
target_include_directories(simple PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(simple pico_stdlib)

pico_enable_stdio_usb(simple 1)
pico_enable_stdio_uart(simple 0)
pico_add_extra_outputs(simple)

### Advanced ###

add_executable(advanced)

target_sources(advanced PRIVATE advanced.c)
target_include_directories(advanced PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(advanced pico_stdlib)

pico_enable_stdio_usb(advanced 1)
pico_enable_stdio_uart(advanced 0)
pico_add_extra_outputs(advanced)