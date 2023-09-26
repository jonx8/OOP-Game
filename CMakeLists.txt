cmake_minimum_required(VERSION 3.12)

project (OOP_GAME)

set(CMAKE_CXX_STANDARD 20)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")

set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE ${INCLUDE_DIRS})