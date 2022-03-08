// INCLUDING ALL HEADER FILES

// TIC TAC TOE--> THIS IS THE MAIN C PROGRAMME WHICH EXECUTES ALL FUNCTIONS.

// STANDARD INPUT AND OUTPUT FILE TO HANDLE INPUT - OUPUT
#include <stdio.h>
// STANDARD LIBRARY TO HANDLE MEMOERY ALLOCATION FOR 2D MATRIX
#include <stdlib.h>

// PROTOTYPES
void cleanBoard(char **);
void createBoard(char **);
int blankLeft(char **);
void playerMove(char **, char);
void computerMove(char **, char);
char winnerState(char **);
void showResult(char **, char, char, char);

// MAIN FUNCTION
int main()
{
  int C_SCORE = 0;
  int P_SCORE = 0;
  char PLAYER;
  char COMPUTER = '#';
  char winner = ' ';
  printf("\n--WELCOME TO THE WORLD OF TIC TAC TOE--\n");
  printf("\nWAIT\nSTARTING...\nSETTING UP....\n\n");
  printf("Enter your symbol(except #) : ");
  scanf("%c", &PLAYER);
  printf("\n\nPLAYER--> %c\t\t\tCOMPUTER--> %c\n\n", PLAYER, COMPUTER);
  char res;
  char **grid = (char **)malloc(sizeof(char *) * 3);
  for (int i = 0; i < 3; i++)
    *(grid + i) = (char *)malloc(sizeof(char) * 3);
  do
  {
    winner = ' ';
    cleanBoard(grid);
    while (winner == ' ' && blankLeft(grid) != 0)
    {
      createBoard(grid);
      playerMove(grid, PLAYER);
      winner = winnerState(grid);
      if (winner != ' ' || blankLeft(grid) == 0)
        break;

      createBoard(grid);
      computerMove(grid, COMPUTER);
      winner = winnerState(grid);
      if (winner != ' ' || blankLeft(grid) == 0)
        break;
    }
    createBoard(grid);
    showResult(grid, winner, PLAYER, COMPUTER);
    if (winner == PLAYER)
      P_SCORE += 10;
    else if (winner == COMPUTER)
      C_SCORE += 10;
    printf("\n\n\n----SESSION SCORE CHART----\n\n\n");
    printf("PLAYER -> %d\t\t\tCOMPUTER ->%d", P_SCORE, C_SCORE);
    printf("\nDo you wanna play again? (y/n) : ");
    getchar();
    scanf("%c", &res);
  } while (res == 'y');
  printf("\n--ADIOS YOU ARE OUT OF THE GAME--\n");
  return 0;
}
