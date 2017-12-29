cmake_minimum_required(VERSION 2.6)
project(kdeapp)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(kdeapp_SRCS kdeapp.cpp main.cpp)

qt4_automoc(${kdeapp_SRCS})
add_executable(kdeapp ${kdeapp_SRCS})
target_link_libraries(kdeapp ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS kdeapp RUNTIME DESTINATION bin)
