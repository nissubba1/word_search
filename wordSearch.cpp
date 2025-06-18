/* ****************************************************************
 *  File Name:      wordSearch.h
 *  Author:         Nishan Subba
 *  GitHub:         @nisSubba2024
 *  Date Created:   01/08/2025
 *  Description:    Header file for Word Search function declaration
 * ****************************************************************/

/**
 * @file wordSearch.cpp
 * @brief This file contains function definition for Word Search game.
 *
 * Provides a function definition for all the game logics including loading files, getting inputs, transfusing 2D arrays, and validating words.
 *
 * @author Nishan Subba
 * @github https://github.com/nisSubba2024
 * @date 01/08/2025
 */


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "wordSearch.h"

void loadFile(std::ifstream& fileObj, std::string& file, char grid[][GRID_SIZE], std::vector<std::string>& wordsArray)
{
    fileObj.open(file);

    if (fileObj)
    {
        std::cout << "File opened successfully." << std::endl;

        for (int row = 0; row < GRID_SIZE; row++)
        {
            for (int col = 0; col < GRID_SIZE; col++)
            {
                fileObj >> grid[row][col];
            }
        }

        std::string readLine;
        while (fileObj >> readLine)
        {
            wordsArray.push_back(readLine);
        }

        fileObj.close();
    }
    else
    {
        std::cout << "File could not be opened." << std::endl;
    }
}

void displayGrid(char grid[][GRID_SIZE])
{
    std::cout << "\n-------- GAME GRID ---------\n" << std::endl;
    std::cout << "   ";
    for (int col = 0; col < GRID_SIZE; col++)
    {
        std::cout << std::setw(2) << col << " ";
    }
    std::cout << std::endl;
    for (int row = 0; row < GRID_SIZE; row++)
    {
        std::cout << std::setw(2) << row << " ";
        for (int col = 0; col < GRID_SIZE; col++)
        {
            std::cout << std::setw(2) << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void displayWordBank(const std::vector<std::string>& wordsArray)
{
    int wordCounter = 1;
    std::cout << "\n-------- WORD BANK --------" << std::endl;
    std::cout << "--------- Remaining Words----------" << std::endl;
    for (const auto& word : wordsArray)
    {
        std::cout << std::setw(2) << wordCounter << ": " << word << std::endl;
        wordCounter++;
    }
    std::cout << "-------- Remaining Words: " << wordsArray.size() << " --------" << std::endl;
}

void displayFoundWords(const std::vector<std::string>& foundWords)
{
    int wordCounter = 1;
    std::cout << "\n-------- FOUND WORDS --------" << std::endl;
    for (const auto& word : foundWords)
    {
        std::cout << std::setw(2) << wordCounter << ": " << word << std::endl;
        wordCounter++;
    }
}

void horizontalSearchForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row <= rowEnd; row++)
    {
        for (int col = colStart; col <= colEnd; col++)
        {
            checkWord.push_back(grid[row][col]);
            indexCounter++;
        }
    }
}

void horizontalSearchReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row <= rowEnd; row++)
    {
        for (int col = colStart; col >= colEnd; col--)
        {
            checkWord.push_back(grid[row][col]);
            indexCounter++;
        }
    }
}

void verticalSearchForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                           std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row <= rowEnd; row++)
    {
        for (int col = colStart; col <= colEnd; col++)
        {
            checkWord.push_back(grid[row][col]);
            indexCounter++;
        }
    }
}

void verticalSearchReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                           std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row >= rowEnd; row--)
    {
        for (int col = colStart; col <= colEnd; col++)
        {
            checkWord.push_back(grid[row][col]);
            indexCounter++;
        }
    }
}

void diagonalSearchDownForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                               std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row <= rowEnd; row++)
    {
        if (colStart <= colEnd)
        {
            checkWord.push_back(grid[row][colStart]);
            indexCounter++;
            colStart++;
        }
    }
}

void diagonalSearchDownReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                               std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row >= rowEnd; row--)
    {
        if (colStart >= colEnd)
        {
            checkWord.push_back(grid[row][colStart]);
            indexCounter++;
            colStart--;
        }
    }
}

void diagonalSearchUpForward(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row >= rowEnd; row--)
    {
        if (colStart <= colEnd)
        {
            checkWord.push_back(grid[row][colStart]);
            indexCounter++;
            colStart++;
        }
    }
}

void diagonalSearchUpReverse(int rowStart, int colStart, int rowEnd, int colEnd, char grid[][GRID_SIZE],
                             std::vector<char>& checkWord)
{
    int indexCounter = 0;
    for (int row = rowStart; row <= rowEnd; row++)
    {
        if (colStart >= colEnd)
        {
            checkWord.push_back(grid[row][colStart]);
            indexCounter++;
            colStart--;
        }
    }
}

void askCoordinates(int& rowStart, int& colStart, int& rowEnd, int& colEnd)
{
    do
    {
        std::cout << "\nWhat is the starting X Y (separated by a space)? ";
        std::cin >> rowStart >> colStart;

        std::cout << "What is the ending X Y (separated by a space)? ";
        std::cin >> rowEnd >> colEnd;

        if (rowStart > 14 || rowStart < 0 || colStart > 14 || colStart < 0 || rowEnd > 14 || rowEnd < 0 || colEnd
            > 14 || colEnd < 0)
        {
            std::cout << "\nInvalid coordinates, please try again." << std::endl;
            std::cout << "Coordinates must be between 0 - 14 Inclusive." << std::endl;
        }
        else
        {
            std::cout << "\n*********** You Picked ***************" << std::endl;
            std::cout << "Start Coordinates: " << "(" << rowStart << ", " << colStart << ")" << std::endl;
            std::cout << "End Coordinates: " << "(" << rowEnd << ", " << colEnd << ")" << std::endl;
            std::cout << "**************************************" << std::endl;
        }
    }
    while (rowStart > 14 || rowStart < 0 || colStart > 14 || colStart < 0 || rowEnd > 14 || rowEnd < 0 || colEnd
        > 14 || colEnd < 0);
}

void clearWordArray(std::vector<char>& checkWord)
{
    if (!checkWord.empty())
    {
        checkWord.clear();
    }
}

bool validateWord(const std::vector<std::string>& wordsArray, const std::vector<char>& checkWord)
{
    std::string word = concatChars(checkWord);

    for (const auto& words : wordsArray)
    {
        if (words == word)
        {
            return true;
        }
    }

    return false;
}

void foundWords(std::vector<std::string>& wordFoundArray, const std::vector<char>& checkWord,
                std::vector<std::string>& wordsArray)
{
    std::vector<std::string> tempWords;
    if (validateWord(wordsArray, checkWord))
    {
        wordFoundArray.push_back(concatChars(checkWord));
        for (auto word : wordsArray)
        {
            if (word != concatChars(checkWord))
            {
                tempWords.push_back(word);
            }
        }
        wordsArray = tempWords;
    }
}

std::string concatChars(const std::vector<char>& checkWord)
{
    std::string word;

    for (auto letter : checkWord)
    {
        word += letter;
    }

    return word;
}

void printWord(const std::vector<char>& checkWord)
{
    std::cout << "Word Found: ";
    for (auto letter : checkWord)
    {
        std::cout << letter;
    }
}



