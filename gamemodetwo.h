#ifndef _GAMEMODETWO_H_
#define _GAMEMODETWO_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int gamemodeTwo()
{   
    //Homepage of the app for vs computer
    printf("Select difficulty by entering either 1, 2 or 3:\n1. Easy (You are given 10 tries)\n2. Medium (You are given 5 tries)\n3. Hard (You are given 3 tries)\n");
    printf("Either player 1 or player 2 decides difficulty");
    for(; difficulty < 1 || difficulty > 3; )   
    {
        printf("Please enter a valid number: ");
        fflush(stdin);
        scanf("%d", &difficulty);
    }
    //difficulty selector
    if (difficulty == 1)
    {
        printf("You have selected easy\n");
        tries = 10;
    }
    if (difficulty == 2)
    {
        printf("You have selected medium\n");
        tries = 5;
    }
    if (difficulty == 3)
    {
        printf("You have selected hard\n");
        tries = 3;
    }

    //Choose colour Player 1
    printf("Ask player 2 to look away while you input your colours.\nEnter you colours. Example: BBBB. All capital without spacing.\n");
    fflush(stdin);
    do{
    status = 0;
    printf("Colours : ");
    fgets(colorsPlayer,4,stdin);
    for (length = 0; colorsPlayer[length] != '\0'; length++) {};
    for (; length < 4 || length > 4;) 
    {
        printf("Wrong input you must select 4 colors. Try again. \n");
        break;
    }
    //even if input has 4 characters, need to check whether the characters are valid
    if (length == 4) 
    {
        for (int j = 0; colorsPlayer[j] != 0; j++) 
        {
            if (colorsPlayer[j] != 'R' && colorsPlayer[j] != 'G' && colorsPlayer[j] != 'B' && colorsPlayer[j] != 'Y' && colorsPlayer[j] != 'P' && colorsPlayer[j] != 'O') 
            {
                printf("Wrong input use the given colors. \n");
                break;
            }
            else
            {
                status = 1;
                break;
            }
        }
    }
    }while(status == 0);
    //printf("%s", colorsRandom);//<--You can uncomment this part for debugging purposes to check validity of answer

    //Where the game begins
    printf("Now you can guess the colors choosen by player 1. \n");
    fflush(stdin);
    printf("\n");
    for (int i = 0; i < tries; i++) 
    {
        posCounter = 0, status = 1;
        printf("\nGuess %d : ", i + 1);
        gets(colorsGuess);
        //checking for valid input
        for (length = 0; colorsGuess[length] != '\0'; length++) {};
        for (; length < 4 || length > 4;) 
        {
            printf("Wrong input you must guess 4 colors. Try again. \n");
            break;
        }
        //even if input has 4 characters, need to check whether the characters are valid
        if (length == 4) {
            for (int j = 0; colorsGuess[j] != 0; j++) {
                if (colorsGuess[j] != 'R' && colorsGuess[j] != 'G' && colorsGuess[j] != 'B' && colorsGuess[j] != 'Y' && colorsGuess[j] != 'P' && colorsGuess[j] != 'O') {
                    printf("Wrong input use the given colors. \n");
                    status = 0;
                    break;
                }
            }
        }
        // If the input is correct, begin checking for the right answer
        if(length == 4 && status == 1)
        {
            for (int k = 0; k < 4; k++) 
            {
                if (colorsGuess[k] == colorsPlayer[k]) 
                {
                    posCounter++;
                    // To count the number of correct characters
                }
            }
            //If no correct characters
            if (posCounter == 0) 
            {
                printf("No correct guess\n");
            } 
            //If afew characters are correct and how many of them
            else if (posCounter > 0) 
            {
            printf("%d color has right position. \n", posCounter);
            }
            //If posCounter == 4 then all are correct because the counter has reached max value
            if (posCounter == 4) 
            {
                printf("Selected colors by computer : ");
                puts(colorsPlayer);
                printf("\n You won the game.");
                break;
            } 
        }
    }
    //Lose screen output
    if(posCounter != 4)
    {
        printf("You lose\nThe correct answer is: ");
        puts(colorsPlayer);
    }
}
#endif