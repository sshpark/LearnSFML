cmake_minimum_required(VERSION 3.2)

set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCROOT})

project(blog6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

set(FILES_HEADER
    ${INCROOT}/Animator.hpp
    ${INCROOT}/AssetManager.hpp
    )
    
set(FILES_SRC 
    ${SRCROOT}/main.cpp
    ${SRCROOT}/Animator.cpp
    ${SRCROOT}/AssetManager.cpp
    )

add_executable(blog6 ${FILES_HEADER} ${FILES_SRC})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(blog6 ${SFML_LIBRARIES})
endif()