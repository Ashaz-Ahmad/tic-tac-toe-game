#include "functions.h"
#include <stdio.h>
#include <ctype.h>

int main()
{
    char winner = ' ';
    char replay_response;
    int gamemode = 0;
    int gamemode_input_result;

    do
    {
        do
        {
            printf("Would you like to play Tic Tac Toe against the computer or with a friend?");
            printf("\nEnter 1 for singleplayer mode and enter 2 for multiplayer mode: ");
            
            gamemode_input_result = scanf("%d", &gamemode);

           if (gamemode_input_result != 1) 
            {
                printf("Invalid input! Please enter a number (1 for singleplayer, 2 for multiplayer).\n");
                while (getchar() != '\n'); 
            }
            else if (gamemode != 1 && gamemode != 2)
            {
                printf("Invalid option! Please enter 1 for singleplayer mode or 2 for multiplayer mode.\n");
            }


        } while (gamemode_input_result != 1 || (gamemode != 1 && gamemode != 2));

        if (gamemode == 1)
        {
            winner = ' ';
            replay_response = ' ';
            
            printf("You are Player 1.\n");

            resetGameBoard();
        
            while (winner == ' ' && checkFreeSpaces() != 0)
            {
                printGameBoard();

                player1move();
                winner = checkWinner();
                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }

                computerMove();
                winner = checkWinner();
                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }
                
            }

            printGameBoard();
            printWinner(winner);

        }
        else if (gamemode == 2)
        {
            winner = ' ';
            replay_response = ' ';
            
            printf("Decide who is Player 1 and who is Player 2. Player 1 moves first.\n");

            resetGameBoard();
        
            while (winner == ' ' && checkFreeSpaces() != 0)
            {
                printGameBoard();

                player1move();
                winner = checkWinner();
                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }

                printGameBoard();

                player2move();
                winner = checkWinner();
                if (winner != ' ' || checkFreeSpaces() == 0)
                {
                    break;
                }
                
            }

            printGameBoard();
            printWinner(winner);
        }
        
        printf("\nWould you like to play the game again? (Y/N): ");
        scanf(" %c", &replay_response);
        replay_response = toupper(replay_response);
    } while (replay_response == 'Y');

    printf("Thanks for playing!\n");
    
    return 0;
    
}
