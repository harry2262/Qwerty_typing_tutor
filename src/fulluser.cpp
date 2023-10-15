#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>  // For using std::pair

struct UserData {
    int bestWPM = 0;
    double accuracy = 0.0;
};

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

    UserData userData;  // Initialize user data with default values.
    userFile << "Welcome, " << username << "!" << std::endl;
    userFile << "Best WPM: " << userData.bestWPM << std::endl;
    userFile << "Accuracy: " << userData.accuracy << std::endl;
    userFile.close();
}

std::pair<int, int> getUserData(const std::string& username) {
    std::ifstream userFile(username + ".txt");

    if (!userFile) {
        std::cerr << "Error: Unable to open the user's file for reading." << std::endl;
        return {0, 0}; // Return default values if the file doesn't exist.
    }

    std::pair<int, int> userData = {0, 0}; // Initialize with default values.

    std::string line;
    while (std::getline(userFile, line)) {
        if (line.find("Best WPM: ") == 0) {
            userData.first = std::stoi(line.substr(10));
        } else if (line.find("Accuracy: ") == 0) {
            userData.second = std::stod(line.substr(10));
        }
    }

    userFile.close();
    return userData;
}

void updateUserData(const std::string& username, int newBestWPM, double newAccuracy) {
    std::ifstream usernameFile("usernames.txt");
    if (!usernameFile) {
        std::cerr << "Error: Unable to open the username file for reading." << std::endl;
        return;
    }

    std::string existingUsername;
    bool usernameExists = false;

    while (usernameFile >> existingUsername) {
        if (existingUsername == username) {
            usernameExists = true;
            break;
        }
    }

    usernameFile.close();

    if (!usernameExists) {
        std::cerr << "Username not found. Cannot update user data." << std::endl;
        return;
    }

    std::string filename = username + ".txt";
    std::ifstream userFile(filename);
    if (!userFile) {
        std::cerr << "Error: Unable to open the user's file for reading." << std::endl;
        return;
    }

    std::vector<std::string> fileData;
    std::string line;

    while (std::getline(userFile, line)) {
        if (line.find("Best WPM: ") == 0) {
            fileData.push_back("Best WPM: " + std::to_string(newBestWPM));
        } else if (line.find("Accuracy: ") == 0) {
            fileData.push_back("Accuracy: " + std::to_string(newAccuracy));
        } else {
            fileData.push_back(line);
        }
    }

    userFile.close();

    std::ofstream updatedUserFile(filename);

    if (!updatedUserFile) {
        std::cerr << "Error: Unable to open the user's file for writing." << std::endl;
        return;
    }

    for (const std::string& data : fileData) {
        updatedUserFile << data << std::endl;
    }

    updatedUserFile.close();
}

void login(const std::string& username) {
    std::pair<int, int> userData = getUserData(username);
    std::cout << "Welcome, " << username << "!" << std::endl;
    std::cout << "Best WPM: " << userData.first << std::endl;
    std::cout << "Accuracy: " << userData.second << std::endl;
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
    // std::cout << "Enter a new username: ";
    // std::string newUsername;
    // std::cin >> newUsername;

    if (usernameExists) {
        login(newUsername);
    } else {
        addUserToFile(newUsername);
        std::cout << "New user created successfully." << std::endl;
        login(newUsername);
    }

    // Example of how to update user data:
    /* updateUserData("sampleUser", 70, 96.5); */ // Update the user's data

    return 0;
}

