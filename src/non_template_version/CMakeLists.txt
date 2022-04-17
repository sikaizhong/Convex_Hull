#SOURCE_GROUP (curvemesh REGULAR_EXPRESSION curvemesh/.*)
file(GLOB_RECURSE SRCS *.cpp *.c *.h *.cu ) # all cpp/c/h files will be represented as a macro called SRCS
add_executable(non_template_version  ${SRCS}) # all files is represented as ${SRCS}
target_include_directories(non_template_version PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )