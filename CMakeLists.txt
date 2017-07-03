cmake_minimum_required(VERSION 3.7)
project(hw4project)

set(CMAKE_CXX_STANDARD 11)

<<<<<<< HEAD
set(SOURCE_FILES main.cpp Enigma.cpp Enigma.h EscapeRoomWrapper.cpp EscapeRoomWrapper.h EscapeRoom.c EscapeRoom.h mtmtest.h tests/EscapeRoomWrapper_test.cpp tests/Enigma_test.cpp list.h Node.h tests/list_test.cpp ScaryRoom.cpp ScaryRoom.h KidsRoom.cpp KidsRoom.h Company.cpp Company.h)
=======
set(SOURCE_FILES main.cpp Enigma.cpp Enigma.h EscapeRoomWrapper.cpp EscapeRoomWrapper.h EscapeRoom.c EscapeRoom.h tests/mtmtest.h tests/EscapeRoomWrapper_test.cpp tests/Enigma_test.cpp list.h Node.h tests/list_test.cpp ScaryRoom.cpp ScaryRoom.h KidsRoom.cpp KidsRoom.h tests/list_test_out.cpp)
>>>>>>> 5e15048c2ecdc60a90065d902f23bcb9e01f8959
add_executable(hw4project ${SOURCE_FILES})