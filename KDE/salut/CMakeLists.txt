cmake_minimum_required(VERSION 2.6)
project(salut)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(salut_SRCS salut.cpp main.cpp)

qt4_automoc(${salut_SRCS})
add_executable(salut ${salut_SRCS})
target_link_libraries(salut ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS salut RUNTIME DESTINATION bin)
