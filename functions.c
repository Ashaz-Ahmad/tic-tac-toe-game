#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char gameBoard[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void resetGameBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = ' ';
        }       
    }
}

void printGameBoard()
{
    printf(" %c | %c | %c ", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] != ' ')
            {
                freeSpaces--;
            }
            
        }
        
    }
    return freeSpaces;
}

void player1move()
{
    int x, y;
    int player1_input_result;

    do
    {
        printf("Player 1: Enter a row #(1-3) that you would like to place an X on: ");
        player1_input_result = scanf("%d", &x);

        if (player1_input_result != 1 || x < 1 || x > 3)
        {
            printf("Invalid input! Row must be an integer between 1 and 3.\n");
            while (getchar() != '\n'); 
            continue;
        }
        x--;

        printf("Player 1: Enter a column #(1-3) that you would like to place an X on: ");
        player1_input_result = scanf("%d", &y);

        if (player1_input_result != 1 || y < 1 || y > 3)
        {
            printf("Invalid input! Column must be an integer between 1 and 3.\n");
            while (getchar() != '\n');  
            continue;
        }
        y--;

        if (gameBoard[x][y] != ' ')
        {
            printf("That spot is taken!\n");
        }
        else
        {
            gameBoard[x][y] = PLAYER1;
            break;
        }

    } while (1); 
}

void player2move()
{
    int x, y;
    int player2_input_result;

    do
    {
        printf("Player 2: Enter a row #(1-3) that you would like to place an O on: ");
        player2_input_result = scanf("%d", &x);

        if (player2_input_result != 1 || x < 1 || x > 3)
        {
            printf("Invalid input! Row must be an integer between 1 and 3.\n");
            while (getchar() != '\n'); 
            continue;
        }
        x--;

        printf("Player 2: Enter a column #(1-3) that you would like to place an O on: ");
        player2_input_result = scanf("%d", &y);

        if (player2_input_result != 1 || y < 1 || y > 3)
        {
            printf("Invalid input! Column must be an integer between 1 and 3.\n");
            while (getchar() != '\n'); 
            continue;
        }
        y--;

        if (gameBoard[x][y] != ' ')
        {
            printf("That spot is taken!\n");
        }
        else
        {
            gameBoard[x][y] = PLAYER2;
            break;
        }

    } while (1);  
}

void computerMove()
{
    srand(time(NULL));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (gameBoard[x][y] != ' ');

        gameBoard[x][y] = COMPUTER;    
    }
    else
    {
        printWinner(' ');
    }
    
}

char checkWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2])
        {
            return gameBoard[i][0];
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i])
        {
            return gameBoard[0][i];
        }
        
    }

    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2])
    {
        return gameBoard[0][0];
    }

    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])
    {
        return gameBoard[0][2];
    }
    
    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER1)
    {
        printf("Player 1 wins!");
    } else if (winner == PLAYER2)
    {
        printf("Player 2 wins!");
    } else if (winner == COMPUTER)
    {
        printf("You lose!");
    }
    
}