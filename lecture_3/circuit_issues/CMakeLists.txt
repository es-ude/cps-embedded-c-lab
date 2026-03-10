add_executable(circuit_issues)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(circuit_issues PRIVATE ${SRC})
target_include_directories(circuit_issues PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(circuit_issues pico_stdlib)

pico_enable_stdio_usb(circuit_issues 1)
pico_enable_stdio_uart(circuit_issues 0)
pico_add_extra_outputs(circuit_issues)