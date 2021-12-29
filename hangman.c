#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char word[20];
int arraySize;
int rNum;
char guess;
char letter;
int wordSize;
int guessCorrect;
char lineHint[20];
int guessedLetterIndex;
int win = 0;
int wrongGuesses = 0;
int playerLost = 0;

void drawHangman()
{
    switch (wrongGuesses)
    {
        case 0:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "       |\n"
                 "       |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 1:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "       |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 2:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "   |   |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 3:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|   |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 4:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|\\  |\n"
                 "       |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 5:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|\\  |\n"
                 "  /    |\n"
                 "       |\n"
                 " =========\n");
            break;
        case 6:
            puts("\n\n   +---+\n"
                 "   |   |\n"
                 "   0   |\n"
                 "  /|\\  |\n"
                 "  / \\  |\n"
                 "       |\n"
                 " =========\n");
            sleep(1);
            system("clear");
            puts("\n"
" __     ______  _    _   _      ____   _____ ______ \n"
" \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|\n"
"  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   \n"
"   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  \n"
"    | | | |__| | |__| | | |___| |__| |____) | |____ \n"
"    |_|  \\____/ \\____/  |______\\____/|_____/|______|\n"
"                                                    \n");
            playerLost = 1;
            break;


    }

}

int winScreen()
{
    system("clear");
    printf("you win. happy now?\n\n");
}

int checker()
{
    for (int i = 0; i <= wordSize && win == 0; i++)
    {
        letter = tolower(word[i]); //the letter which will be compared with the user's guess
       
        if (strcmp(lineHint, word) == 0)
        {
            system("clear");
            printf("\n\nYou guessed the word!\n\n");
            winScreen();
            win = 1;
            return 0;     
        }

        else if (letter == guess)
        {
            guessedLetterIndex = i;
            lineHint[guessedLetterIndex] = guess;
            
            if (guessCorrect == 0 && win == 0)
            {
                system("clear");
                if (win != 1)
                {
                    printf("You guessed a correct letter!");
                }
                guessCorrect = 1;
            }
        }
    }

    if (guessCorrect == 0) //condition to only print if the player has guessed an incorrect character
    {
        system("clear");
        printf("You guessed wrong!");
        wrongGuesses++;
    }
}

void initBlankLine()
{
    char underscore = '_';

    for (int i = 0; i < wordSize; i++)
    {
        strncat(lineHint, &underscore, 1);
    }
}

int startGame()
{
    system("clear");
    printf("The word you need to guess is: %s \n\n", word);
    printf("Welcome to Hangman!\n\n\nPress 'Enter' to start.\n\n");
    getchar();
    initBlankLine();
    system("clear");
    drawHangman();
    
    for (int i = 0; i < wordSize + 10 && win != 1 && playerLost != 1;  i++)
    {
        guessCorrect = 0;
        printf("Completed Guesses: %d\n\n", i);
        printf("%s", lineHint);
        printf("\n\nGuess a letter: ");
        scanf(" %c", &guess);

        if (checker() == 0)
        {
            return 0;
        }

        drawHangman();
        printf("\n\n");
    }

}


int main()
{
    srand(time(NULL));
    char wordList[5][30] =  {"animal", "among", "microphone", "amount", "british"};

    arraySize = sizeof wordList / sizeof wordList[0];  //calculates the number of elements within the wordList array
 
    rNum = (rand() % arraySize);  //limits random number to just index values in the array 

    strcpy(word, wordList[rNum]);   //assign a random word from the list

    wordSize = strlen(word);  //calculates the number of characters within the selected word
    startGame();

    return 0;
}