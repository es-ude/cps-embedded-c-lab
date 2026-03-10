add_library(prime_test STATIC)

target_sources(prime_test PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/prime_test.c
)
target_include_directories(prime_test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(prime_test pico_stdlib)
