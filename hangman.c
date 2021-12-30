#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char word[16];
int arraySize;
int rNum;
char guess;
char letter;
int wordSize;
int guessCorrect;
char lineHint[16];
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
    char space = ' ';

    for (int i = 0; i < wordSize; i++)
    {
        if (word[i] != ' ')
        {
            strncat(lineHint, &underscore, 1);
        }
        else
        {
            strncat(lineHint, &space, 1);
        }
    }
}

int chooseDifficulty()
{
    int difficulty;

    system("clear");

    printf("Please pick a difficulty level:\n\n");
    printf("1 - Easy (single word, 5 characters or under)\n");
    printf("2 - Medium (single word, 10 characters or under)\n");
    printf("3 - Hard (two words, 10 characters or under)\n\n");
    printf("Difficulty number: ");
    scanf(" %d", &difficulty);

    return difficulty;
}

int chooseTheme()
{
    int theme;

    system("clear");

    printf("Now it's time to choose a theme:\n\n");
    printf("1 - Animals\n");
    printf("2 - Food\n");
    printf("3 - Computing\n\n");
    printf("Theme number: ");
    scanf(" %d", &theme);

    return theme;
}

int assignWordlist(int difficulty, int theme)
{
    srand(time(NULL));
    
    switch(theme)
    {
        case 1:
            if (difficulty == 1)
            {
                char wordlist[5][6] = {"frog", "snake", "mouse", "bird", "zebra"};
            
                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
            else if (difficulty == 2)
            {
                char wordlist[5][11] = {"chimpanzee", "rhinoceros", "crocodile", "alligator", "butterfly"};

                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
            else
            {
                char wordlist[5][20] = {"tiger shark", "gentoo penguin", "red squirrel", "hammerhead shark", "arctic fox"};
        
                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
        break;

        case 2:
            if (difficulty == 1)
            {
                char wordlist[5][6] = {"apple", "bacon", "beans", "curry", "pizza"};
         
                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
            else if (difficulty == 2)
            {
                char wordlist[5][11] = {"chocolate", "blackberry", "asparagus", "cornflakes", "cheesecake"};
        
                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
            else
            {
                char wordlist[5][20] = {"kidney beans", "peanut butter", "iceberg lettuce", "mandarin orange", "french fries"};

                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
        break;

        case 3:
            if (difficulty == 1)
            {
                char wordlist[5][6] = {"blog", "cyber", "linux", "print", "mouse"};
            
                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
            else if (difficulty == 2)
            {
                char wordlist[5][11] = {"bandwidth", "algorithm", "hypertext", "mainframe", "resolution"};
                
                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 
            }
            else
            {
                char wordlist[5][20] = {"search engine", "virtual machine", "domain name", "hard drive", "social media"};

                arraySize = 5; 
 
                rNum = (rand() % arraySize); 

                strcpy(word, wordlist[rNum]);   

                wordSize = strlen(word); 

            }
        break;
    }    
    return 0;
}

int startGame()
{
    system("clear");
    printf("Welcome to Hangman!\n\nPress any key to start.\n\n");
    getchar();
    int difficulty = chooseDifficulty();
    int theme = chooseTheme();
    assignWordlist(difficulty, theme);
    getchar();
    initBlankLine();
    system("clear");
    drawHangman();
    printf("The word you need to guess is: %s \n\n", word);
    
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
    startGame();

    return 0;
}