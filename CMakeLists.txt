cmake_minimum_required(VERSION 3.12...3.27.4)

project(CompileTests)

include_directories(src)

FILE(GLOB BOT_SOURCE_FILES
    src/bots/*.cpp
    src/bots/*.h
)

FILE(GLOB SERVER_SOURCE_FILES
    src/server/*.cpp
    src/server/*.h
    src/bots/*.cpp
    src/bots/*.h
)

add_library(bot SHARED ${BOT_SOURCE_FILES})
add_executable(server ${SERVER_SOURCE_FILES})

target_compile_options(server PRIVATE -rdynamic)


