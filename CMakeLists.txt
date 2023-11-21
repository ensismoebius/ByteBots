cmake_minimum_required(VERSION 3.5)

project(ByteBots LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Lua REQUIRED)

add_executable(ByteBots
    src/main.cpp
)

target_include_directories(ByteBots PRIVATE headers)
target_include_directories(ByteBots PRIVATE include ${LUA_INCLUDE_DIR})

target_link_libraries(ByteBots PRIVATE ${LUA_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS ByteBots
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY resources/ DESTINATION ${CMAKE_INSTALL_DATADIR}/ByteBots)
