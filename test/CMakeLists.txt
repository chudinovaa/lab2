add_executable(test_sort test_sort.cpp)
target_include_directories(test_sort PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(test_sort sort gtest gtest_main Threads::Threads)
add_test(test_sort test_sort)
add_custom_command(TARGET test_sort POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_BINARY_DIR}/src/libsort.dll"
        $<TARGET_FILE_DIR:test_sort>)
