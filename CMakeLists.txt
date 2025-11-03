cmake_minimum_required(VERSION 3.20)
project(task_cli)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(nlohmann_json 3.12.0 REQUIRED)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${MY_SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    nlohmann_json::nlohmann_json
)
