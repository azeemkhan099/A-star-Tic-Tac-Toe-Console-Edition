# Tic-Tac-Toe

This is a command-line implementation of the classic game Tic-Tac-Toe in C++. The code allows users to play against the computer or with another human player.

## Code Explanation

The code is structured into a class called `TicTacToe` and a nested struct called `Board`. Here's a breakdown of the main components and their functionalities:

- `TicTacToe` class:
  - `playGame()`: Allows users to choose between the single-player and two-player modes and initiates the game accordingly.
  - `playSinglePlayer()`: Implements the logic for playing against the computer in single-player mode. It utilizes the `Board` struct and the minimax algorithm to make the computer's moves.
  - `playTwoPlayers()`: Implements the logic for playing against another human player in two-player mode. It uses the `Board` struct to keep track of the game state.
  
- `Board` struct:
  - `reset()`: Resets the game board to its initial state with all cells empty.
  - `isFull()`: Checks if the game board is full, indicating a draw.
  - `isTerminal()`: Determines if the game has reached a terminal state (win, loss, or draw).
  - `evaluate()`: Evaluates the current game board and returns a score (-10, 0, or 10) based on the outcome.
  - `printBoard()`: Prints the current state of the game board to the console.

Additionally, the code includes the `minimax` function, which is used to implement the AI opponent in the single-player mode. The `minimax` function recursively explores the game tree, evaluating each possible move and determining the best score for the maximizing (computer) and minimizing (human) players.

The code utilizes standard C++ libraries such as `<iostream>` for input/output operations and `<cstdlib>` for general-purpose operations. It also includes the `<conio.h>` library, specific to certain compilers, to access console input/output functions.

## Features

- Single-player mode: Play against the computer with an AI opponent using the minimax algorithm.
- Two-player mode: Play with a friend locally.
- Visually represented game board.
- Determination of winner or draw based on the game rules.

## How to Play

1. Clone the repository or download the source code files.

2. Compile the code using a C++ compiler.

3. Run the compiled executable.

4. Select the game mode: one player (against the computer) or two players.

5. Follow the prompts to make moves on the game board.

6. The game will continue until there is a winner or a draw.

7. Enjoy a game of Tic-Tac-Toe!

## Technologies Used

- C++ programming language

## Contributions

Contributions to the project are welcome! If you find any issues or have suggestions for improvements, feel free to submit a pull request or open an issue.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use and modify the code according to the terms of the license.

## Acknowledgments

- The minimax algorithm for the single-player AI opponent is based on [OpenAI's GPT-3.5](https://openai.com/research/gpt-3-5), a powerful language model developed by OpenAI.

- Inspiration for the project was drawn from various Tic-Tac-Toe implementations available online.

## Enjoy the Game!

Thank you for checking out this Tic-Tac-Toe project! Have fun playing the game and feel free to contribute or provide feedback.
