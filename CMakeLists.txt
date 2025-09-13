cmake_minimum_required(VERSION 3.10)
project(ProjectCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjectCpp
        main.cpp
        menu.cpp
        stop.cpp
        stop_manager.cpp
        transport.cpp
        transport_manager.cpp
        route.cpp
        route_manager.cpp
        schedule.cpp
        schedule_manager.cpp
        file_io.cpp
        reports.cpp
        utils.cpp
)

target_include_directories(ProjectCpp PRIVATE .)