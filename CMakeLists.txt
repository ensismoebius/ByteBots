cmake_minimum_required(VERSION 3.5)

project(ByteBots LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ByteBots main.cpp)

include(GNUInstallDirs)
install(TARGETS ByteBots
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
