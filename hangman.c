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

void checker()
{
    for (int i = 0; i < wordSize; i++)
    {
        //the letter which will be compared with the user's guess

        letter = word[i];
  
        if (letter == guess)
        {
            printf("You guessed a correct character!");
        }

        printf("%c", letter);
    }
}

void startGame()
{
    printf("Welcome to Hangman!\n\nPress 'Enter' to start.\n\n");
    getchar();
    printf("Guess a letter: ");
    scanf("%c", &guess);
    checker();
    printf("\n\n");
    printf("Your guess: %c\n\n", guess);
}

int main()
{
    srand(time(NULL));
    char wordList[5][30] =  {"ANIMAL", "AMONG", "MICROPHONE", "AMOUNT", "BRITISH"};

    //calculates the number of elements within the wordList array

    arraySize = sizeof wordList / sizeof wordList[0];

    //limits random number to just index values in the array 

    rNum = (rand() % arraySize);

    //assign a random word from the list

    strcpy(word, wordList[rNum]);
    printf("The word you need to guess is: %s \n", word);

    //calculates the number of characters within the selected word's array

    wordSize = strlen(word);
    startGame();

    return 0;
}

