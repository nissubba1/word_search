/* ****************************************************************
 *  File Name:      wordSearch.h
 *  Author:         Nishan Subba
 *  GitHub:         @nisSubba2024
 *  Date Created:   01/08/2025
 *  Description:    Header file for Word Search function declaration
 * ****************************************************************/

/**
 * @file wordSearch.h
 * @brief This file contains function declarations for Word Search game.
 *
 * Provides a function prototype for all the game logics including loading files, getting inputs, transfusing 2D arrays, and validating words.
 *
 * @author Nishan Subba
 * @github https://github.com/nisSubba2024
 * @date 01/08/2025
 */

#ifndef WORDSEARCH_H
#define WORDSEARCH_H

// Header preprocess
#include <iostream>
#include <string>
#include <vector>

/**
 * The MAX size of the 2D Array to display grid.
 */
const int GRID_SIZE = 15;

/**
 * Load the file into the 2D Array and vector of word list
 * Loop until the max size of the grid and insert set of characters.
 * Once loop reaches MAX grid size, reach each line for words which user is supposed to search for in the grid
 * Insert the words line by line into vector
 * @param fileObj File object
 * @param file Name of the file
 * @param grid 2D grid to hold array
 * @param wordsArray Vector to contain the list of words
 */
void loadFile(std::ifstream& fileObj, std::string& file, char grid[][GRID_SIZE], std::vector<std::string>& wordsArray);


/**
 * Display the 2D array of char
 * @param grid 2D array grid
 */
void displayGrid(char grid[][GRID_SIZE]);

/**
 * Display the words user are supposed to find
 * Count how many words are currently in the word bank
 * @param wordsArray List of words to find
 */
void displayWordBank(const std::vector<std::string>& wordsArray);

// Transversing Grid
// Horizontal Search - Forward ->
/**
 *  Transverse 2D Grid Array Horizontally moving from LEFT TO RIGHT
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void horizontalSearchForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord);

// Horizontal Search - Reverse <-
/**
 *  Transverse 2D Grid Array Horizontally moving in reverse from RIGHT TO LEFT
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void horizontalSearchReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord);

// Vertical Search - Forward ->
/**
 *  Transverse 2D Grid Array Vertically moving from TOP TO BOTTOM
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void verticalSearchForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                           std::vector<char>& checkWord);

// Vertical Search - Reverse <-
/**
 *  Transverse 2D Grid Array Vertically moving in reverse from BOTTOM TO TOP
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void verticalSearchReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                           std::vector<char>& checkWord);

// Diagonal Search - Going Down - Forward \>
/**
 *  Transverse 2D Grid Array Diagonally moving from TOP TO BOTTOM in negative direction, or decreasing slope
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void diagonalSearchDownForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                               std::vector<char>& checkWord);

// Diagonal Search - Going Down - Reverse
/**
 *  Transverse 2D Grid Array Diagonally moving from BOTTOM TO TOP in negative direction, or decreasing slope
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void diagonalSearchDownReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                               std::vector<char>& checkWord);

// Diagonal Search - Going Up - Forward />
/**
 *  Transverse 2D Grid Array Diagonally moving from BOTTOM TO TOP in positive direction, or increasing slope
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void diagonalSearchUpForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord);

// Diagonal Search - Going Up - Reverse </
/**
 *  Transverse 2D Grid Array Diagonally moving from TOP TO BOTTOM in positive direction, or increasing slope
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 * @param grid 2D Grid user are traversing
 * @param checkWord A list of characters from starting (X, Y) and ending (X, Y) coordinate, which is also a word user think is from the word bank
 */
void diagonalSearchUpReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord);

// User input
/**
 * Ask the user for coordinates of starting and ending positions
 * Since C-Style array do not have bound check, we have to make sure user does not enter out of bound coordinates
 * Using loop, continue to as ask user to enter valid coordinate
 * @param rowStart X coordinate of the starting position,which is a Row Number
 * @param colStart Y coordinate of the starting position,which is a Column Number
 * @param rowEnd X coordinate of the ending position,which is a Row Number
 * @param colEnd Y coordinate of the ending position,which is a Column Number
 */
void askCoordinates(int& rowStart, int& colStart, int& rowEnd, int& colEnd);

// clear the vector
/**
 * Clear the vector which contains characters from user inputted coordinates.
 * We want to make sure that everytime a user picks a pair of coordinates, old vector is clear so
 * a new set of characters can be inserted into it.
 * @param checkWord Vector that holds char of characters from user picked coordinates
 */
void clearWordArray(std::vector<char>& checkWord);

// validate the word
/**
 * Take a characters from user entered X,Y coordinates and match it against words in the wordsArray.
 * @param wordsArray Words user are looking for in the Grid
 * @param checkWord A set of characters from starting and ending coordinates
 * @return Return True if checkWord is found in wordsArray or False if it's not there
 */
bool validateWord(const std::vector<std::string>& wordsArray, const std::vector<char>& checkWord);

// take the found word and add to found word array
/**
 * If a word is found, add it to the found array vector to keep track of which words are found
 * @param wordFoundArray Vector to hold all the words user have already found
 * @param checkWord A set of characters from starting and ending coordinates
 * @param wordsArray Words user are looking for in the Grid
 */
void foundWords(std::vector<std::string>& wordFoundArray, const std::vector<char>& checkWord,
                std::vector<std::string>& wordsArray);

// take a char of letters and return a concat word
/**
 * Concatenate the set of characters from 2D Grid into a single string
 * @param checkWord A set of characters from starting and ending coordinates
 * @return Concatenated string of characters
 */
std::string concatChars(const std::vector<char>& checkWord);

// display coordinate word
/**
 * Display characters in the checkWord vector
 * @param checkWord A set of characters from starting and ending coordinates
 */
void printWord(const std::vector<char>& checkWord);

// display words found
/**
 * Display words user found
 * @param foundWords Vector to hold words user found
 */
void displayFoundWords(const std::vector<std::string>& foundWords);


#endif //WORDSEARCH_H
