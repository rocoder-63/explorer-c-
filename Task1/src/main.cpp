#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::cout << "Hello from Project_Conquer <>>> - Task #1\n";
    if (argc > 1) {
        std::cout << "Received argument: " << argv[1] << "\n";
    } else {
        std::cout << "Run with an optional argument to echo.\n";
    }
    return 0;
}
