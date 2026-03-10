add_executable(button_denoising)

file(GLOB_RECURSE SRC 
    ${CMAKE_CURRENT_LIST_DIR}/*.c
    ${CMAKE_CURRENT_LIST_DIR}/*.h
)
target_sources(button_denoising PRIVATE ${SRC})
target_include_directories(button_denoising PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(button_denoising pico_stdlib)

pico_enable_stdio_usb(button_denoising 1)
pico_enable_stdio_uart(button_denoising 0)
pico_add_extra_outputs(button_denoising)