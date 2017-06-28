cmake_minimum_required(VERSION 3.7)
project(hw4project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Enigma.cpp Enigma.h EscapeRoomWrapper.cpp EscapeRoomWrapper.h EscapeRoom.c EscapeRoom.h mtmtest.h tests/EscapeRoomWrapper_test.cpp tests/Enigma_test.cpp list.h Node.h tests/list_test.cpp ScaryRoom.cpp ScaryRoom.h)
add_executable(hw4project ${SOURCE_FILES})