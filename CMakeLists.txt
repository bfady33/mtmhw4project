cmake_minimum_required(VERSION 3.7)
project(hw4project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Enigma.cpp Enigma.h EscapeRoomWrapper.cpp EscapeRoomWrapper.h EscapeRoom.c EscapeRoom.h Exceptions.cpp mtmtest.h tests/EscapeRoomWrapper_test.cpp)
add_executable(hw4project ${SOURCE_FILES})