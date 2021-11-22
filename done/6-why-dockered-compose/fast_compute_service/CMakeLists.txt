cmake_minimum_required (VERSION 3.14)
project(fast_compute_service)

find_package(Poco REQUIRED Net Util)

add_executable(fast_compute_service main.cpp)

target_link_libraries(fast_compute_service Poco::Net Poco::Util)
