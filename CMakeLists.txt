cmake_minimum_required(VERSION 3.20)
project(HttpServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(HttpServer main.cpp HttpProcessor.cpp HttpProcessor.h)
