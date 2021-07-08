#ifndef _GAMEMODEONE_H_
#define _GAMEMODEONE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "variables.h"

int gamemodeOne()
{
    //Homepage of the app for vs computer
    printf("Select difficulty by entering either 1, 2 or 3:\n1. Easy (You are given 10 tries)\n2. Medium (You are given 5 tries)\n3. Hard (You are given 3 tries)\n");
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

    //Random sequence generator
    srand(time(0));
    for (int i = 0; i < 4; i++) 
    {
        randIndex = rand() % 6;
        colorsRandom[i] = colors[randIndex];
    }
    //printf("%s", colorsRandom);//<--You can uncomment this part for debugging purposes to check validity of answer

    //Where the game begins
    printf("Now you can guess the colors. \n");
    fflush(stdin);
    printf("\n");
    for (int i = 0; i < tries; i++) 
    {
        posCounter = 0, status = 1;
        printf("Guess %d : ", i + 1);
        fgets(colorsGuess, 4 , stdin);
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
                if (colorsGuess[k] == colorsRandom[k]) 
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
                puts(colorsRandom);
                printf("\n You won the game.");
                break;
            } 
        }
    }
    //lose screen output
    if(posCounter != 4)
    {
        printf("You lose\nThe correct answer is: ");
        puts(colorsRandom);
    }
}
#endif


