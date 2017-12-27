cmake_minimum_required(VERSION 2.6)
project(mykdeapp)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(mykdeapp_SRCS mykdeapp.cpp main.cpp)

qt4_automoc(${mykdeapp_SRCS})
add_executable(mykdeapp ${mykdeapp_SRCS})
target_link_libraries(mykdeapp ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS mykdeapp RUNTIME DESTINATION bin)
