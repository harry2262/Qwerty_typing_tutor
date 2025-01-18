
# Terminal-Based Typing Game and User Management

This project is a terminal-based typing game with a user management system. Users can log in, track their best typing speeds, and manage data such as scores and accuracy. The application provides a game to test typing speed, accuracy, and other metrics.

## Features

- **Typing Game**: Measures words per minute (WPM) and accuracy.
- **User Management**: Login, create, and manage user profiles with encrypted passwords.
- **Leaderboard and Scores**: Track and display users' best performances.
- **Customizable Options**: Adjust passage length and input files.
- **NCurses-based UI**: Provides an interactive terminal interface.

## Technologies Used

- **C++**: Core application logic
- **OpenSSL**: SHA-256 encryption for password security
- **NCurses**: Text-based UI
- **File I/O**: Persistent data storage for user profiles and scores

## Directory Structure

```
/
├── .git/                   # Git configuration files
├── src/                    # Source code
│   ├── Application.cpp     # Main application logic and UI
│   ├── Engine.cpp          # Typing speed and accuracy calculations
│   ├── TextGenerator.cpp   # Generates passages for the typing game
│   ├── Timer.cpp           # Timer for tracking game duration
│   ├── UserNew.cpp         # User management (login, data updates)
│   ├── oldFiles/           # Legacy code and experiments
├── .gitignore              # Ignored files
```

## Getting Started

### Prerequisites

1. **Linux or macOS**: For compatibility with NCurses.
2. **G++ Compiler**: For building the C++ code.
3. **NCurses Library**: Install using your package manager.
   ```bash
   sudo apt-get install libncurses5-dev libncursesw5-dev
   ```
4. **OpenSSL Library**: For password encryption.

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo-url.git
   cd your-repo-name
   ```

2. Compile the code:
   ```bash
   g++ src/Application.cpp -lncurses -o TypingGame
   ```

3. Run the application:
   ```bash
   ./TypingGame
   ```

### Usage

1. **Start the Game**: Choose "Start" from the menu to begin.
2. **Switch Users**: Log in as an existing user or create a new account.
3. **Adjust Settings**: Customize passage length and input files.
4. **View Scores**: Check your best WPM and accuracy.
5. **Exit**: Save progress and quit the application.

### Key Controls

- **Arrow Keys**: Navigate the menu.
- **Enter**: Select a menu option.
- **Backspace**: Correct mistakes during typing.

## File Details

- **`Application.cpp`**: Manages the main menu, UI, and game logic.
- **`Engine.cpp`**: Provides core logic for typing speed (WPM) and accuracy calculations.
- **`TextGenerator.cpp`**: Randomly generates passages for the game.
- **`UserNew.cpp`**: Handles user authentication, password encryption, and profile management.
- **`Timer.cpp`**: Tracks elapsed time during the game.
