add_library(sensor_lib STATIC)

target_sources(sensor_lib PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/adxl345.c
    ${CMAKE_CURRENT_LIST_DIR}/pac193x.c
    ${CMAKE_CURRENT_LIST_DIR}/sht31.c
)
target_include_directories(sensor_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(sensor_lib pico_stdlib hardware_i2c)