cmake_minimum_required(VERSION 2.8)
project(mainpro) 
add_definitions("-O2")
add_subdirectory(md5)
add_executable(mainpro main.c)
target_link_libraries(mainpro md5lib) 
