#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>


void mainmenu();
void quizgame();

int main() {
    mainmenu();
    return 0;
}

 void mainmenu() {

    int ch;
    FILE *high_score;
    // Temporary until no 1 is created
    high_score = fopen("high_score.txt", "w");
    if (high_score == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(high_score, "prabin   20");
    fclose(high_score);

    printf("PRESS 1 To start the game.\n");
    printf("PRESS 2 To check the high score.\n");
    printf("PRESS 3 To update the question database.\n");
    printf("PRESS 4 To exit the game (ps. by exiting the game you lose your chance to become smart)\n");

    while (1) {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        while (getchar() != '\n');  // Clear the newline character left by scanf

        switch (ch) {
            case 1:
                quizgame();
                printf("............welcome to the game...............\n");
                printf("the game is under construction\n\n");
                printf("Press enter to go to main menu\n\n");
                getch();
                mainmenu();
                return;

            case 2:
                high_score = fopen("high_score.txt", "r");
                if (high_score == NULL) {
                    printf("file error\n\n");
                    printf("Press enter to go to main menu\n\n");
                    getch();
                    mainmenu();
                    return;
                } 
                else {
                    char score[100];
                    fgets(score, sizeof(score), high_score);
                    printf("%s\n\n", score);
                    fclose(high_score);
                    printf("Press enter to go to main menu\n\n");
                    getch();
                    mainmenu();
                    return;
                
                }
                case 3:
                {
                 FILE *f;
                 char question[200];
                 f = fopen("questionbase.txt", "a");
                 if (f == NULL) {
                    perror("Error opening file");
                    printf("Press enter to go to the main menu\n\n");
                    getch();
                    mainmenu();
                    return;
                 } else {
                    printf("Enter the question that you want to store\n");
                    // getchar();
                    // scanf("%[^\n]", question);
                    fgets(question,200,stdin);
                    fprintf(f, "%s", question);
                    fclose(f);
                    printf("String stored in file successfully!\n");
                    printf("enter to go back to the main menu\n\n");
                    getch();
                    mainmenu();
                    return;
                 }
                }                

            case 4: {
                char oi;
                printf("Are you sure you want to exit (y for yes, any other key for no)?\n");
                scanf(" %c", &oi);
                while (getchar() != '\n');  // Clear the newline character left by scanf
                if (oi == 'y' || oi == 'Y') {
                    exit(0);
                } else {
                    mainmenu();
                    return;
                }
            }

            default:
                printf("Please choose among 1, 2, 3, 4\n\n");
                printf("Press enter to go to main menu\n\n");
                getch();
                mainmenu();
                return;
        }
    }
}
void quizgame()
{
    int cg;
    printf("1.General Konwledge\n");
    printf("2.Computer Science\n");
    printf("Please enter among any of this choices: ");
    scanf("%d", &cg);
    switch (cg)
    {
        case 1:
        printf("General Knowledge\n");
        break;
        case 2:
        printf("Computer Science\n");
        break;
        default:
        printf("Invalid Choice");
        break;
    }
}