# Word Search Game

## Overview
This repository contains the implementation of a Word Search game. The game displays a 15x15 grid of letters where the user must find hidden words. The words to search for are provided in a file and can be placed in various directions (horizontal, vertical, and diagonal).
## Documentation
You can access the detailed documentation for the project [here](https://nissubba2024.github.io/word_search/files.html).

## Technologies Used
- C++
- Clion
- Doxygen

## Features
- Load a grid and word list from a file.
- Display the grid and word bank to the user.
- Search words in multiple directions (horizontal, vertical, diagonal).
- Track and display found words.
- Interactive user input for coordinates to search within the grid.
- Documentation generated using Doxygen for detailed code description.
- Test file included to test the coordinates within the game.

## Files
- `wordSearch.h`: Contains function declarations for the Word Search game.
- `wordSearch.cpp`: Implements the game logic and functionality.
- `main.cpp`: Main entry point for the game.

## Functionality

### Key Functions
- **loadFile()**: Loads the grid and list of words from a file.
- **displayGrid()**: Displays the 15x15 letter grid.
- **displayWordBank()**: Shows the list of words the user needs to find.
- **search()**: Searches for words in different directions (horizontal, vertical, diagonal).
- **askCoordinates()**: Prompts the user to enter the start and end coordinates of the word to search.
- **validateWord()**: Checks if the word formed by the coordinates matches any word in the list.
- **foundWords()**: Adds found words to the list of words already found.

### Directional Search Functions:
- **horizontalSearchForward()**: Search from left to right horizontally.
- **horizontalSearchReverse()**: Search from right to left horizontally.
- **verticalSearchForward()**: Search from top to bottom vertically.
- **verticalSearchReverse()**: Search from bottom to top vertically.
- **diagonalSearchDownForward()**: Search diagonally downwards from top-left to bottom-right.
- **diagonalSearchDownReverse()**: Search diagonally downwards from bottom-left to top-right.
- **diagonalSearchUpForward()**: Search diagonally upwards from bottom-left to top-right.
- **diagonalSearchUpReverse()**: Search diagonally upwards from top-left to bottom-right.

## Usage

### Cloning the Repository
First, clone the repository to your local machine:

```bash
git clone https://github.com/nissubba1/word_search.git
cd word-search
```
Building the cmake:
```bash
mkdir build
cd build
```
Run cmake:
```bash
cmake ..
```
Build executable:
```bash
cmake --build .
```
Go back to root directory, and run:
```bash
./build/word_search
```
