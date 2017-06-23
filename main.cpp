#include <iostream>

#include "tests/EscapeRoomWrapper_test.cpp"

int main() {
    std::cout << "Hello, running tests!" << std::endl;
    std::cout << "running escaperoomwrapper test:" << std::endl;
    escapeRoomWrapperTest();
    std::cout << "finished escaperoomwrapper test:" << std::endl;

    std::cout << "finished testing successfuly" << std::endl;
    return 0;
}
