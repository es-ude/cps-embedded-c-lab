### Delay Based ###

add_executable(delay_based)

target_sources(delay_based PRIVATE delay_based.c)
target_include_directories(delay_based PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(delay_based pico_stdlib prime_test)

pico_enable_stdio_usb(delay_based 1)
pico_enable_stdio_uart(delay_based 0)
pico_add_extra_outputs(delay_based)

### Timer Based ###

add_executable(timer_based)

target_sources(timer_based PRIVATE timer_based.c)
target_include_directories(timer_based PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(timer_based pico_stdlib prime_test)

pico_enable_stdio_usb(timer_based 1)
pico_enable_stdio_uart(timer_based 0)
pico_add_extra_outputs(timer_based)

### PWM Based ###

add_executable(pwm_based)

target_sources(pwm_based PRIVATE pwm_based.c)
target_include_directories(pwm_based PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(pwm_based pico_stdlib prime_test hardware_pwm hardware_clocks)

pico_enable_stdio_usb(pwm_based 1)
pico_enable_stdio_uart(pwm_based 0)
pico_add_extra_outputs(pwm_based)