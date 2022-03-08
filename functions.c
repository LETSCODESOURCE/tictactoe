// INCLUDING HEADER FILES
// STANDARD INPUT AND OUTPUT FILE TO HANDLE INPUT - OUPUT
#include <stdio.h>
// STANDARD LIBRARY TO HANDLE MEMOERY ALLOCATION FOR 2D MATRIX
#include <stdlib.h>
// HEADER FILE TO ACCESS TIME FOR SEEDING THE RANDOM FUNCTION(RAND())
#include <time.h>

// FUCNTIONS DEFINITIONS

// FUNCTION TO CREATE THE BOARD GRID
void createBoard(char **grid)
{
  printf(" %c   | %c  | %c ", grid[0][0], grid[0][1], grid[0][2]);
  printf("\n-----|----|-----\n");
  printf(" %c   | %c  | %c ", grid[1][0], grid[1][1], grid[1][2]);
  printf("\n-----|----|-----\n");
  printf(" %c   | %c  | %c ", grid[2][0], grid[2][1], grid[2][2]);
  printf("\n");
}

// FUNCTION TO CHECK FOR ANY BLANK SPACES
int blankLeft(char **grid)
{
  int freeSpaces = 9;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (grid[i][j] != ' ')
        freeSpaces--;
  return freeSpaces;
}

// FUNCTION TO HANDLE PLAYER'S INPUT
void playerMove(char **grid, char PLAYER)
{
  int x, y;
  printf("\n--YOUR TURN--\n");
  do
  {
    printf("Row (1-3): ");
    scanf("%d", &x);
    printf("Column (1-3): ");
    scanf("%d", &y);
    x--;
    y--;
    if (grid[x][y] != ' ')
    {
      printf("\n--Invalid Move--\n");
      createBoard(grid);
    }
    else
    {
      grid[x][y] = PLAYER;
      break;
    }
  } while (grid[x][y] != ' ');
}

// FUNCTION TO HANDLES COMPUTER'S INPUT
void computerMove(char **grid, char COMPUTER)
{
  // create a seed based on curretn time
  srand(time(0));
  int x, y;
  printf("\n--COMPUTER'S TURN--\n");
  do
  {
    x = rand() % 3;
    y = rand() % 3;
  } while (grid[x][y] != ' ');
  grid[x][y] = COMPUTER;
}

// FUNCTION TO CHECK IF WINNER EXIST OR NOT
char winnerState(char **grid)
{
  // check rows
  for (int i = 0; i < 3; i++)
    if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
      return grid[i][0];
  // check columns
  for (int i = 0; i < 3; i++)
    if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
      return grid[0][i];
  // check diagonals
  if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2])
    return grid[0][0];
  if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0])
    return grid[0][2];
  return ' ';
}

// FUNCTION TO DISPLAY RESULT AFTER ALL AVAILABLE SPACES GET FILLED
void showResult(char **grid, char winner, char PLAYER, char COMPUTER)
{
  if (winner == PLAYER)
  {
    if (blankLeft(grid) < 2)
      printf("\nOH... THAT WAS A CLOSE ONE \n");
    else if (blankLeft(grid) == 4)
      printf("\nCLEAN SWEEP!!");
    printf("\nHURRAY !! YOU WIN!!");
  }
  else if (winner == COMPUTER)
  {
    if (blankLeft(grid) == 3)
    {
      printf("\nSEEMS LIKE YOU ARE A BAD PLAYER");
      printf("\nYOU LOSE ): TRY AGAIN");
    }
    else
      printf("\nYOU LOSE ):");
  }
  else
    printf("\nIT'S A TIE\nDon't worry try another chance");
}

//  FUNCTION TO CLEAN BOARD FOR A RE-PLAY
void cleanBoard(char **grid)
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      grid[i][j] = ' ';
}
