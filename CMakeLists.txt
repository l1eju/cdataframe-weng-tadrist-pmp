cmake_minimum_required(VERSION 3.27)
project(cdataframe_weng_tadrist_pmp C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cdataframe_weng_tadrist_pmp
        main.c
        cdataframe.c
        cdataframe.h
        column.c
        column.h)
