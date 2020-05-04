cmake_minimum_required(VERSION 3.16)
project(MinimumSpanTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(MinimumSpanTree main.cpp Edge.h LazyPrimMST.h PrimMST.h KruskalMST.h)