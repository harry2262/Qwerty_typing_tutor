#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void addUserToFile(const std::string& username) {
    // Add the username to the "usernames.txt" file.
    std::ofstream usernameFile("usernames.txt", std::ios::app);

    if (!usernameFile) {
        std::cerr << "Error: Unable to open the username file for writing." << std::endl;
        return;
    }

    usernameFile << username << std::endl;
    usernameFile.close();

    // Create a separate file for each user if it does not exist.
    std::ofstream userFile(username + ".txt");
    if (!userFile) {
        std::cerr << "Error: Unable to create the user's file." << std::endl;
        return;
    }

    userFile << "Welcome, " << username << "!" << std::endl;
    userFile.close();
}

int main() {
    std::cout << "Enter a new username: ";
    std::string newUsername;
    std::cin >> newUsername;

    // Check if the username already exists in "usernames.txt".
    std::ifstream usernameFile("usernames.txt");
    if (!usernameFile) {
        std::cerr << "Error: Unable to open the username file for reading." << std::endl;
        return 1;
    }

    std::string existingUsername;
    bool usernameExists = false;

    while (usernameFile >> existingUsername) {
        if (existingUsername == newUsername) {
            usernameExists = true;
            break;
        }
    }

    usernameFile.close();

    if (usernameExists) {
        std::cout << "Username already exists. Please choose a different username." << std::endl;
    } else {
        addUserToFile(newUsername);
        std::cout << "New user created successfully. Welcome, " << newUsername << "!" << std::endl;
    }

    return 0;
}
