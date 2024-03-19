cmake_minimum_required(VERSION 3.8)

add_executable(Elves main.cpp
				${MY_INCLUDE_DIR}/Elves.h Elves.cpp)

target_include_directories(Elves PUBLIC ${MY_INCLUDE_DIR})