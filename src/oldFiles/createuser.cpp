#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> validUsernames;
    std::ifstream usernameFile("usernames.txt");

    if (!usernameFile)
    {
        std::cerr << "Error: Unable to open the username file." << std::endl;
        return 1;
    }

    std::string username;
    while (std::getline(usernameFile, username))
    {
        validUsernames.push_back(username);
    }

    usernameFile.close();

    // Step 2: Prompt the user to enter a new username.
    std::cout << "Enter a new username: ";
    std::string newUsername;
    std::cin >> newUsername;

    // Step 3: Check if the entered username is unique.
    bool isUnique = true;
    for (const std::string &existingUsername : validUsernames)
    {
        if (newUsername == existingUsername)
        {
            isUnique = false;
            break;
        }
    }

    // Step 4: If the username is unique, append it to the list of valid usernames.
    if (isUnique)
    {
        validUsernames.push_back(newUsername);

        // Step 5: Write the updated list of usernames back to the username file, appending the new username.
        std::ofstream outFile("usernames.txt", std::ios::app); // Open in append mode.

        if (!outFile)
        {
            std::cerr << "Error: Unable to open the username file for writing." << std::endl;
            return 1;
        }
        std::ofstream userFile(username + ".txt");
        if (!userFile)
        {
            std::cerr << "Error: Unable to create the user's file." << std::endl;
            return 1;
        }
        userFile.close();
        outFile << newUsername << std::endl;
        outFile.close();
    }
    else
    {
        std::cout << "Username already exists. Please choose a different username." << std::endl;
    }

    return 0;
}
