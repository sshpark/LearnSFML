cmake_minimum_required(VERSION 3.2)

set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCROOT})

project(blog5_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES repeatedTex.cpp)

set(FILES_SRC ${SRCROOT}/repeatedTex.cpp)

add_executable(blog5_1 ${FILES_SRC})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(blog5_1 ${SFML_LIBRARIES})
endif()