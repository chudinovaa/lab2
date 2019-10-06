add_library(file_io STATIC file_io.cpp)
set_target_properties(file_io PROPERTIES LINKER_LANGUAGE CXX)
add_library(sort SHARED sort.cpp)
set_target_properties(sort PROPERTIES LINKER_LANGUAGE CXX)

add_executable(lab2 main.cpp)
target_link_libraries(lab2 file_io sort)
add_custom_command(TARGET lab2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/etc/abc.txt"
        $<TARGET_FILE_DIR:lab2>/abc.txt)
