#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

bool userExists(const std::string& username, const std::string& filename) {
    std::ifstream usernameFile(filename);
    if (!usernameFile) {
        std::cerr << "Error: Unable to open the username file." << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(usernameFile, line)) {
        if (line == username) {
            return true;
        }
    }

    return false;
}

int main() {
    std::cout << "Enter your username: ";
    std::string enteredUsername;
    std::cin >> enteredUsername;

    if (userExists(enteredUsername, "usernames.txt")) {
        std::cout << "Login successful. Welcome, " << enteredUsername << "!" << std::endl;
    } else {
        std::cout << "Login failed. User does not exist." << std::endl;
    }

    return 0;
}
