cmake_minimum_required(VERSION 3.14)
project(Qt6App)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Qt6App main.cpp)

target_link_libraries(Qt6App PRIVATE Qt6::Widgets)