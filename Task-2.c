#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main(void) {
    int mode;
    
    printf("Choose a game mode:\n1 — the program thinks of a number, you guess it\n2 — you think of a number, the program guesses it\n");
    scanf("%d", &mode);
    getchar(); 

    if (mode != 1 && mode != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    if (mode == 1) {
        int number = rand() % 1000 + 1;
        int guess;
        int attempts = 0;
        
        printf("Try to guess\n");

        while (1) {
            printf("Your assumption: ");
            if (scanf("%d", &guess) != 1) {
                printf("Incorrect input\n");
                getchar();
                continue;
            }
           getchar();
            
            attempts++;

            if (guess < number) {
                printf("The guessed number is greater\n");
            } else if (guess > number) {
                printf("The guessed number is smaller\n");
            } else {
                printf("You guessed it!\n");
                break;
            }
        }
        printf("Number of attempts: %d\n", attempts);

    } else if (mode == 2) {
        int low = 1, high = 1000;
        int guess;
        int attempts = 0;

        printf("Think of a number from 1 to 1000. \n> if the number you are thinking of is greater than the one provided\n< if the number you are thinking of is less than the one provided\n= if the program guessed correctly\n");


        while (low <= high) {
            guess = low + (high - low) / 2;
            attempts++;
            printf("My guess is: %d. Your answer (> < =): ", guess);
            if (attempts>1){ clear_input_buffer();}
            char response = getchar();
            if (response == '=') {
                printf("I guessed right!\n");
                break;
            } else if (response == '<') {
                high = guess - 1;
            } else if (response == '>') {
                low = guess + 1;
            } else {
                printf("Incorrect input, use only >, < или =\n");
                attempts--;
            }

        }

        if (low > high) {
            printf("Incorrect input\n");
        } else {
            printf("Number of program attempts: %d\n", attempts);
        }
    }

    return 0;
}