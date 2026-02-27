add_library(hardware_setup STATIC)

target_sources(hardware_setup PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/hardware_setup.c
)
target_include_directories(hardware_setup PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(
	hardware_setup
	hardware_adc
	hardware_dma
	pico_stdlib
	hardware_i2c
	sensor_lib
)
