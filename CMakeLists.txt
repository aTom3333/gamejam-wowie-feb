cmake_minimum_required(VERSION 3.8)
project(gamejam-wowie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


file(GLOB_RECURSE SOURCE_FILES src/*)

message(STATUS ${SOURCE_FILES})

add_executable(jeu ${SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/${CMAKE_BUILD_TYPE})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(SFML 2 COMPONENTS audio graphics window system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(jeu ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
