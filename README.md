# Tic-Tac-Toe Game

This is a simple command-line Tic-Tac-Toe game written in C. The game offers both single-player mode (against the computer) and multiplayer mode (against a friend). The game is built with input validation to prevent invalid moves and ensure a smooth gaming experience.

## Features

- **Singleplayer Mode**: Play against a basic AI that randomly selects moves.
- **Multiplayer Mode**: Play with a friend locally.
- **Input Validation**: Ensures that users provide valid input for game mode selection, row and column numbers, and handles invalid input gracefully.
- **Makefile Included**: A Makefile is provided to simplify the compilation process.

## How to Play

### Game Modes:
1. **Singleplayer**: You play as Player 1 (X), and the computer plays as Player 2 (O).
2. **Multiplayer**: Player 1 and Player 2 take turns playing as X and O, respectively.

### Rules:
- Players take turns placing their symbol (X or O) on the 3x3 grid.
- The first player to align three of their symbols horizontally, vertically, or diagonally wins the game.
- If all spots on the grid are filled and no player has won, the game results in a draw.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Ashaz-Ahmad/tic-tac-toe-game.git
   cd tic-tac-toe
   ```

2. Compile the project using `make`:

    ```bash
    make
    ```
    
    This will compile the program and generate the executable.

## Usage

You can start playing the game by executing the following command-line argument:

```bash
./main
```
