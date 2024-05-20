cmake_minimum_required(VERSION 3.12...3.27.4)

project(CompileTests)

FILE(GLOB BOT_SOURCE_FILES
    src/*.cpp
    src/*.h
)

add_library(CompileTests STATIC ${BOT_SOURCE_FILES})
target_compile_options(CompileTests PRIVATE -std=gnu++17)

include_directories(src)

