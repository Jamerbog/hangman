#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

char word[20];
int arraySize;
int rNum;
char guess;
char letter;
int wordSize;
int guessCorrect;
char blankLine[20];

void checker()
{
    for (int i = 0; i < wordSize; i++)
    {
        //the letter which will be compared with the user's guess

        letter = tolower(word[i]);
  
        if (letter == guess && guessCorrect == 0)
        {
            printf("\n\nYou guessed a correct character!");
            guessCorrect = 1;
        }

    }
    if (guessCorrect == 0) //condition to only print if the player has guessed a correct character
    {
        printf("\n\nYou guessed wrong!");
        guessCorrect = 1;
    }
}

void initBlankLine()
{
    char underscore = '_';

    for (int i = 0; i < wordSize; i++)
    {
        strncat(blankLine, &underscore, 1);
    }
}

void startGame()
{
    printf("\n\nWelcome to Hangman!\n\nPress 'Enter' to start.\n\n");
    getchar();
    initBlankLine();
    printf(blankLine);
    printf("\n\nGuess a letter: ");
    scanf("%c", &guess);
    checker();
    printf("\n\n");
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

