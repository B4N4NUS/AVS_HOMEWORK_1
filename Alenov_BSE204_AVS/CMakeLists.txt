cmake_minimum_required(VERSION 3.20)
project(Alenov_BSE204_AVS)

set(CMAKE_CXX_STANDARD 14)

add_executable(Alenov_BSE204_AVS main.cpp rnd.h text.h container.h container.cpp text.cpp charecterReplacement.h cyclicShift.h charecterToNumber.h charecterReplacement.cpp charecterToNumber.cpp cyclicShift.cpp)
