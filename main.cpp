/* ****************************************************************
 *  File Name:      main.h
 *  Author:         Nishan Subba
 *  GitHub:         @nisSubba2024
 *  Date Created:   01/08/2025
 *  Description:    Header file for Word Search function declaration
 * ****************************************************************/

/**
 * @file main.cpp
 * @brief This file contains entry point to run the game
 *
 * A Main file to combine all the game logics and run the game.
 * Load the game grid
 * Ask the user for coordinates
 * Calling specific transversal function based on set of conditions about a pair of coordinates
 * Validating the words
 * Ending the game state
 *
 *
 * @author Nishan Subba
 * @github https://github.com/nisSubba2024
 * @date 01/08/2025
 */


#include <iostream>
#include <vector>
#include <fstream>
#include "wordSearch.h"

int main()
{
    char gridArray[GRID_SIZE][GRID_SIZE];
    std::ifstream outputFile;
    std::string fileName = "proj1_p1.txt";
    std::vector<std::string> wordsBank;
    std::vector<char> potentialWord;
    std::vector<std::string> foundWordsArray;

    int posStartX,
        posStartY,
        posEndX,
        posEndY;

    loadFile(outputFile, fileName, gridArray, wordsBank);

    while (!wordsBank.empty())
    {
        displayGrid(gridArray);
        displayWordBank(wordsBank);
        askCoordinates(posStartX, posStartY, posEndX, posEndY);

        if (posStartY <= posEndY && posStartX == posEndX) // horizontal ->
        {
            horizontalSearchForward(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartY >= posEndY && posStartX == posEndX) // horizontal <-
        {
            horizontalSearchReverse(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartY == posEndY && posStartX <= posEndX) // vertical up to down
        {
            verticalSearchForward(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartY == posEndY && posStartX >= posEndX) // vertical reverse
        {
            verticalSearchReverse(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartX <= posEndX && posStartY <= posEndY) // diagonal down forward
        {
            diagonalSearchDownForward(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartX >= posEndX && posStartY >= posEndY) // diagonal down reverse
        {
            diagonalSearchDownReverse(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartX >= posEndX && posStartY <= posEndY) // diagonal up forward
        {
            diagonalSearchUpForward(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else if (posStartX <= posEndX && posStartY >= posEndY) // diagonal up reverse
        {
            diagonalSearchUpReverse(posStartX, posStartY, posEndX, posEndY, gridArray, potentialWord);
        }
        else
        {
            std::cout << "Invalid coordinates!!" << std::endl;
        }

        if (validateWord(wordsBank, potentialWord))
        {
            printWord(potentialWord);
            foundWords(foundWordsArray, potentialWord, wordsBank);
            displayFoundWords(foundWordsArray);
            clearWordArray(potentialWord);
        }
        else
        {
            std::cout << "\nWord Not Found!" << std::endl;
        }
    }

    if (wordsBank.empty())
    {
        std::cout << "######################################################" << std::endl;
        std::cout << "Congratulation! You have found all the words and beaten Word Search" << std::endl;
        std::cout << "I hope you enjoyed it. Thank You for playing." << std::endl;
    }
}
