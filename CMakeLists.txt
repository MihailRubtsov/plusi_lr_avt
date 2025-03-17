cmake_minimum_required(VERSION 3.14)
project(plusi_lr_avt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(plusi_lr_avt main.cpp)

target_link_libraries(plusi_lr_avt PRIVATE Qt6::Widgets)