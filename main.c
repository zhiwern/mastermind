#include "gamemodeone.h"
#include "gamemodetwo.h"

int main()
{
    int gamemode;
    printf("Welcome to the game of mastermind. Your target is guessing the correct colors.\n");
    printf("The colors in the game : R(Red), G(Green), B(Blue), Y(Yellow), P(Purple), O(Orange) \n");
    printf("You can choose to play with another player or with the computer\n");
    printf("Select the following gamemode by pressing 1 or 2:\n");
    printf("1. Singleplayer\n2. Play with a friend\nYour choice: ");
    scanf("%d", &gamemode);
    for(; gamemode < 1 || gamemode > 2;)
    {
        printf("Please enter a valid number: ");
        fflush(stdin);
        scanf("%d", &gamemode);
    }
    if(gamemode == 1)
    {
        gamemodeOne();
    }
    if(gamemode == 2)
    {
        gamemodeTwo();
    }
    return 0;
}