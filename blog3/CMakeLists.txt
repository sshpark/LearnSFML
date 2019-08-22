cmake_minimum_required(VERSION 3.2)

set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCROOT})

project(blog3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(FILES_HEADER
        ${INCROOT}/Game.hpp
        ${INCROOT}/Player.hpp
        ${INCROOT}/Action.hpp
        ${INCROOT}/ActionMap.hpp
        ${INCROOT}/ActionTarget.hpp
        )

set(FILES_SRC
        ${SRCROOT}/main.cpp
        ${SRCROOT}/Game.cpp
        ${SRCROOT}/Player.cpp
        ${SRCROOT}/Action.cpp
        ${SRCROOT}/ActionMap.cpp
        ${SRCROOT}/ActionTarget.cpp
        )

add_executable(blog3 ${FILES_HEADER} ${FILES_SRC})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(blog3 ${SFML_LIBRARIES})
endif()