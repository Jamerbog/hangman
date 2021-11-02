#include <stdio.h>
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

void checker()
{
    for (int i = 0; i <= wordSize; i++)
    {
        letter = tolower(word[i]); //the letter which will be compared with the user's guess
  
        if (letter == guess)
        {
            guessedLetterIndex = i;
            lineHint[guessedLetterIndex] = guess;
            if (guessCorrect == 0)
            {
                printf("\n\nYou guessed a correct letter!");
                guessCorrect = 1;
            }
        }
    }

    if (guessCorrect == 0) //condition to only print if the player has guessed an incorrect character
    {
        printf("\n\nYou guessed wrong!");
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

void startGame()
{
    printf("\n\nWelcome to Hangman!\n\n\nPress 'Enter' to start.\n\n");
    getchar();
    initBlankLine();
    for (int i = 0; i < wordSize + 10; i++)
    {
        guessCorrect = 0;
        system("clear");
        printf("Completed Guesses: %d\n\n", i);
        printf(lineHint);
        printf("\n\nGuess a letter: ");
        scanf(" %c", &guess);
        checker();
        printf("\n\n");
    }
}

int main()
{
    srand(time(NULL));
    char wordList[5][30] =  {"ANIMAL", "AMONG", "MICROPHONE", "AMOUNT", "BRITISH"};

    arraySize = sizeof wordList / sizeof wordList[0];  //calculates the number of elements within the wordList array
 
    rNum = (rand() % arraySize);  //limits random number to just index values in the array 

    strcpy(word, wordList[rNum]);   //assign a random word from the list
    printf("\n\nThe word you need to guess is: %s \n", word);

    wordSize = strlen(word);  //calculates the number of characters within the selected word's array
    startGame();

    return 0;
}