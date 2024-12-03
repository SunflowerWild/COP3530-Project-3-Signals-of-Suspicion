cmake_minimum_required(VERSION 3.27)
project(COP3530_Project_3_Signals_of_Suspicion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(COP3530_Project_3_Signals_of_Suspicion
        main.cpp
        quicksort.h
        quicksort.cpp
        heapsort.h
        heapsort.cpp)
