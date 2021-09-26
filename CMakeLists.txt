cmake_minimum_required(VERSION 3.20)
project(Apps_multifil_basiques C)

set(CMAKE_C_STANDARD 99)

add_executable(Apps_multifil_basiques thread_identification.c digits.c sumatori.c)
add_executable(Print_digits digits.c)
add_executable(Sumatori sumatori.c)