cmake_minimum_required(VERSION 3.27)
project(sha1 C)

set(CMAKE_C_STANDARD 11)

add_library(sha1 STATIC sha1.c
        message.c
        message.h)
