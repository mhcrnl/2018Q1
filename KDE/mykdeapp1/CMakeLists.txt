cmake_minimum_required(VERSION 2.6)
project(mykdeapp1)

add_executable(mykdeapp1 main.cpp)

install(TARGETS mykdeapp1 RUNTIME DESTINATION bin)
