#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define LPCSTR

int Finalscore;
char userName[50];
int choice;
int c;
void gotoxy(int x, int y);
void load();
void boundary();
void move(int *x, int *y, char *l, char c, int len);
int check(int px, int py, int *x, int *y, int len);
void recordScore(int score, char *userName);
void displayMenu();
void displayScore(int score);
void displayMenuAgain();
void displayGameScore();
void playGame();
void over(int x, int y, int len, char *userName);

void playSound(const char *soundName)
{
    PlaySound(LPCSTR(soundName), NULL, SND_FILENAME | SND_ASYNC);
}

void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Set cursor visibility to false
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void gotoxy(int x, int y)
{
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void setConsoleColor(int r, int g, int b)
{
    int index = 0;
    if (r < 128)
        index |= FOREGROUND_RED;
    if (g < 128)
        index |= FOREGROUND_GREEN;
    if (b < 128)
        index |= FOREGROUND_BLUE;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, index);
}

void load()
{
    int row, col, r, c, q;
    gotoxy(45, 13);
    printf("\t  loading...");
    gotoxy(45, 14);
    setConsoleColor(255, 255, 0);
    for (r = 1; r <= 20; r++)
    {
        for (q = 0; q <= 100000000; q++)
            ; // to display the character slowly
        printf("%c", 177);
    }
    setConsoleColor(0, 0, 0);
    printf("\n\n\t\t\t\t\tPress any key to continue...");
    getch();
    system("cls");
}

void boundary()
{
    setConsoleColor(0, 128, 128);
    printf("%c", 218);
    for (int i = 1; i < 118; i++)
    {
        printf("%c", 196);
    }
    printf("%c", 191);
    for (int i = 1; i < 24; i++)
    {
        gotoxy(118, i);
        printf("%c", 179);
        gotoxy(0, i);
        printf("%c", 179);
    }
    printf("\n%c", 192);
    for (int i = 1; i < 118; i++)
    {
        printf("%c", 196);
    }
    printf("%c", 217);
    gotoxy(0, 0);
    setConsoleColor(0, 0, 0);
}

void move(int *x, int *y, char *l, char c, int len)
{
    gotoxy(x[len - 1], y[len - 1]);
    printf(" ");
    for (int i = len; i > 0; i--)
    {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    *l = c;
    if (len > 1)
    {
        gotoxy(x[1], y[1]);
        printf("%c", 254);
    }
}

int check(int px, int py, int *x, int *y, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (px == x[i] && py == y[i])
        {
            return 1;
        }
    }
    return 0;
}

void recordScore(int score, char *userName)
{
    FILE *file = fopen("Game_Records.txt", "a");
    if (file == NULL)
    {
        printf("Error opening the file.");
        return;
    }
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);
    fprintf(file, "Player Name: %s | Score: %d | Date: %d-%02d-%02d %02d:%02d:%02d\n", userName, score,
            tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday,
            tm_info.tm_hour, tm_info.tm_min, tm_info.tm_sec);
    fclose(file);
}

void displayMenu()
{
    
    system("cls");
    boundary();
    gotoxy(50, 6);
    setConsoleColor(128, 0, 0);
    printf("\n\t\t\t\t\t   Snake Game Menu\n");
    printf("\t\t\t\t\t-------------------\n");
    printf("\t\t\t\t\t1. New Game\n");
    printf("\t\t\t\t\t2. Game Score\n");
    printf("\t\t\t\t\t3. Exit\n");
    printf("\t\t\t\t\t-------------------\n");
    printf("\t\t\t\t\tEnter your choice: ");
}

void displayScore(int score)
{
    gotoxy(2, 25);
    printf("Score: %d", score);
    Finalscore = score;
}

void displayMenuAgain()
{
    system("cls");
    boundary();
    gotoxy(50, 6);
    setConsoleColor(128, 0, 0);
    printf("\n\t\t\t\t\t   Snake Game Menu\n");
    printf("\t\t\t\t\t-------------------\n");
    printf("\t\t\t\t\t1. New Game\n");
    printf("\t\t\t\t\t2. Game Score\n");
    printf("\t\t\t\t\t3. Exit\n");
    printf("\t\t\t\t\t-------------------\n");
    printf("\t\t\t\t\tEnter your choice: ");

    int c;
    scanf("%d", &c);

    if (c == 1)
    {
        printf("\n\t\t\t\t\tEnter your name: ");
        scanf("%s", userName);
    }

    setConsoleColor(0, 0, 0);

    if (c == 3)
    {
        system("cls");
        boundary();
    }

    switch (c)
    {
    case 1:
        PlaySound(NULL, NULL, SND_FILENAME);
        system("cls");
        boundary();
        playGame();
        break;
    case 2:
        displayGameScore();
        break;
    case 3:
        printf("\n\t\t\t\t\tExiting the game.\n");
        exit(0);
        break;
    default:
        printf("\n\t\t\t\t\tInvalid choice. Exiting the game.\n");
        exit(0);
        break;
    }
}

void displayGameScore()
{   
    const char *intro = "C:\\Users\\ASUS\\OneDrive\\Desktop\\Snake_Game_Project\\mainmenu.wav";
    playSound(intro);
    system("cls");
    boundary();
    setConsoleColor(0, 0, 255);
    printf("\n\t\t\t\t\t\t     Best Score\n");
    printf("\t\t\t\t\t\t -------------------\n");
    setConsoleColor(0, 0, 0);
    FILE *file = fopen("Game_Records.txt", "r");
    if (file == NULL)
    {
        printf("No Game records available.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("\t\t\t  %s", line);
    }

    fclose(file);

    printf("\n\t\t\tPress 'B' to go back to the main menu or 'P' to play a new game...");

    char choice;
    do
    {
        choice = getch();
    } while (choice != 'B' && choice != 'b' && choice != 'P' && choice != 'p');

    if (choice == 'B' || choice == 'b')
    {
        displayMenuAgain(); // Call the main menu again
    }
    else if (choice == 'P' || choice == 'p')
    {
        system("cls");
        boundary();
        playGame();
    }
}

void playGame()
{

    gotoxy(1, 1);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SNAKES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    gotoxy(1, 2);
    printf("\n\t-> Use arrow keys to move the snake and for boost up the snake press and hold arrow keys\n");
    gotoxy(1, 3);
    printf("\t-> Backward movement is not allowed\n");
    gotoxy(1, 4);
    printf("\t-> Don't maximize the window\n");
    gotoxy(1, 5);
    printf("\t-> Press any key to continue");
    
    getch();
    system("cls");
    boundary();
    load();
    boundary();

    gotoxy(2, 2);
    printf("Use arrow key for the movement of snake head...");
    gotoxy(2, 3);
    printf("press space key to pause and arrow keys to resume the game   ");
    gotoxy(2, 4);
    printf("Now press any arrow key Start the Game...");
    getch();
    gotoxy(2, 2);
    printf("                                               ");
    gotoxy(2, 3);
    printf("                                                                ");
    gotoxy(2, 4);
    printf("                                               ");

    srand(time(NULL));
    int *x, *y, px = ((rand() % 57) * 2) + 3, py = (rand() % 23) + 1, len = 1;
    char c, l;
    clock_t t;

    x = (int *)malloc(sizeof(int) * (len + 1));
    y = (int *)malloc(sizeof(int) * (len + 1));
    x[0] = 25;
    y[0] = 20;

    gotoxy(px, py);
    setConsoleColor(255, 0, 255);
    printf("%c", 2);
    setConsoleColor(0, 0, 0);

    gotoxy(x[0], y[0]);
    printf("@");

    int score = 0;
    gotoxy(2, 25);
    setConsoleColor(255, 0, 0);
    printf("Score: %d", score);

    int lifelines = 3;
    gotoxy(50, 25);
    setConsoleColor(255, 0, 255);
    printf("Lifelines: %d", lifelines);
    setConsoleColor(0, 0, 0);

    while (1)
    {
        do
        {
            t = clock();
            while (clock() < t + 250 && !kbhit())
                ;
            if (clock() < t + 250)
            {
                c = getch();
                if (c == 75 && l == 77)
                    c = 77;
                else if (c == 77 && l == 75)
                    c = 75;
                else if (c == 80 && l == 72)
                    c = 72;
                else if (c == 72 && l == 80)
                    c = 80;
            }

            switch (c)
            {
            case 0:
                break;

            case 80: //down
                move(x, y, &l, c, len);
                gotoxy(x[0], ++y[0]);
                printf("%c", 31);
                break;

            case 72: //up
                move(x, y, &l, c, len);
                gotoxy(x[0], --y[0]);
                printf("%c", 30);
                break;

            case 75: //left
                move(x, y, &l, c, len);
                gotoxy(x[0] = x[0] - 2, y[0]);
                printf("%c", 17);
                break;

            case 77: //right
                move(x, y, &l, c, len);
                gotoxy(x[0] = x[0] + 2, y[0]);
                printf("%c", 16);
                break;

            default:
                break;
            }
            // Check if snake bites itself or touches the border
            int bitten = 0;
            for (int i = 4; i < len; i++)
            {
                if (x[0] == x[i] && y[0] == y[i])
                {
                    bitten = 1;
                    break;
                }
            }

            if (x[0] <= 0 || x[0] >= 117 || y[0] <= 0 || y[0] >= 24 || bitten)
            {
                const char *hiss = "C:\\Users\\ASUS\\OneDrive\\Desktop\\Snake_Game_Project\\bite.wav";
                playSound(hiss);
                if (lifelines > 0)
                {
                    // Clear the previous positions of the snake's body on the screen
                    for (int i = 1; i < len; i++)
                    {
                        gotoxy(x[i], y[i]);
                        printf(" "); // Print a space to clear the previous position
                    }

                    lifelines--;
                    len -= 3; // Reduce snake length when using lifeline
                    if (len < 1)
                    {
                        len = 1; // Ensure snake length is at least 1
                    }
                    // Update display for lifelines
                    gotoxy(50, 25);
                    setConsoleColor(255, 0, 255);
                    printf("Lifelines: %d", lifelines);
                    setConsoleColor(0, 0, 0);
                    // Print part of the border at the border position
                    setConsoleColor(0, 255, 255);
                    if (x[0] <= 0)
                    {
                        // Print a part of the border at the left border position
                        gotoxy(0, y[0]);
                        printf("%c", 179); // Print a vertical line
                        gotoxy(2, y[0]);
                        printf(" ");
                    }
                    else if (x[0] >= 117)
                    {
                        // Print a part of the border at the right border position
                        gotoxy(118, y[0]);
                        printf("%c", 179); // Print a vertical line
                        gotoxy(117, y[0]);
                        printf(" ");
                    }
                    else if (y[0] <= 0)
                    {
                        // Print a part of the border at the top border position
                        gotoxy(x[0], 0);
                        printf("%c", 196); // Print a horizontal line
                    }
                    else if (y[0] >= 24)
                    {
                        // Print a part of the border at the bottom border position
                        gotoxy(x[0], 24);
                        printf("%c", 196); // Print a horizontal line
                    }
                    setConsoleColor(0, 0, 0);
                    // Reset snake to the center space of the border
                    x[0] = 25;
                    y[0] = 12;

                    // Move the snake to the new position
                    for (int i = 1; i < len; i++)
                    {
                        x[i] = x[0] + 2 * i;
                        y[i] = y[0];
                    }
                }
                else
                {
                    PlaySound(NULL, NULL, SND_FILENAME); // Stop playing the BackGround Sound
                    const char *out = "C:\\Users\\ASUS\\OneDrive\\Desktop\\Snake_Game_Project\\over.wav";
                    playSound(out);
                    over(x[0], y[0], len, userName);
                }
            }

        } while (x[0] != px || y[0] != py);

        if (x[0] == px && y[0] == py)
        {
            const char *eatSound = "C:\\Users\\ASUS\\OneDrive\\Desktop\\Snake_Game_Project\\eat.wav";
            playSound(eatSound);
        }
        gotoxy(x[len], y[len]);
        setConsoleColor(128, 128, 128);
        printf("%c", 254);
        len++;
        setConsoleColor(0, 0, 0);
        displayScore(len - 1);

        x = (int *)realloc(x, sizeof(int) * (len + 1));
        y = (int *)realloc(y, sizeof(int) * (len + 1));

        do
        {
            py = (rand() % 23) + 1;
            px = ((rand() % 57) * 2) + 3;
        } while (check(px, py, x, y, len));

        gotoxy(px, py);
        setConsoleColor(255, 0, 255);
        printf("%c", 2);
        setConsoleColor(0, 0, 0);
    }
}

void over(int x, int y, int len, char *userName)
{
    gotoxy(x, y);
    printf("%c", 254);
    recordScore(Finalscore, userName);
    gotoxy(1, 1);
    setConsoleColor(0, 128, 0);
    printf("Game Over!!!\n");
    printf("%cPlayer: %s\n", 179, userName);
    printf("%cScore: %d   ", 179, Finalscore);
    setConsoleColor(0, 0, 128);
    printf("\n%cDo you want to play again? (Y/N): ", 179);
    setConsoleColor(0, 0, 0);

    char choice;
    do
    {
        choice = getch();
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    if (choice == 'Y' || choice == 'y')
    {
        system("cls");
        boundary();
        playGame();
    }

    else
    {
        printf("\n%cPress press Enter key to go main menu...", 179);
        getch();

        const char *intro = "C:\\Users\\ASUS\\OneDrive\\Desktop\\Snake_Game_Project\\mainmenu.wav";
        playSound(intro);

        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PlaySound(NULL, NULL, SND_FILENAME);
            system("cls");
            boundary();
            playGame();
            break;
        case 2:
            displayGameScore();
            break;
        case 3:
            printf("\n\t\t\t\t\tExiting the game.\n");
            exit(0);
            break;
        default:
            printf("\n\t\t\t\t\tInvalid choice. Exiting the game.\n");
            exit(0);
            break;
        }
    }
}

int main()
{
    hideCursor();
    boundary();
    const char *intro = "C:\\Users\\ASUS\\OneDrive\\Desktop\\Snake_Game_Project\\mainmenu.wav";
    playSound(intro);
    displayMenu();

    scanf("%d", &choice);

    if (choice == 1)
    {
        gotoxy(50, 14);
        printf("\n\t\t\t\t\tEnter your name: ");
        scanf("%s", userName);
        setConsoleColor(0, 0, 0);
    }

    // Once the game starts, stop playing the intro music and proceed to the game
    PlaySound(NULL, NULL, SND_FILENAME); // Stop playing the sound
    system("cls");
    boundary();

    switch (choice)
    {
    case 1:
        playGame();
        break;
    case 2:
        displayGameScore();
        break;
    case 3:
        printf("\n\t\t\t\t\tExiting the game.\n");
        exit(0);
        break;
    default:
        printf("\n\t\t\t\t\tInvalid choice. Exiting the game.\n");
        exit(0);
        break;
    }
    return 0;
}
