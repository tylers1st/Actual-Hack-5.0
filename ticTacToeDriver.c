/*
* Collaborators : Karthik Reddy Pagilla,  Izzy Hinrichsen, Tyler Furst, Theo Joseph.
* Date : 03/08 /2019
* This program has been debugged and it allows the user to play TicTacToe in three modes
*/



#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#include "gameUtils.h"
#include "playerUtils.h"

/*
 *
 */


int main(int argc, char **argv) {

  srandom(time(NULL));

  int gameChoice = mainMenu();
  Move **board = newBoard();
  Status s = getStatus(board);

  while(s == PLAYING) {

    //x moves
    printBoard(board);
    userMove(board, X);
    s = getStatus(board);
    if(s != PLAYING) {
      break;
    }

    //o moves
    printBoard(board);
    if(gameChoice == TWO_PLAYER) {
      userMove(board, O); // Changed 0 to O
    } else if(gameChoice == ONE_PLAYER_RANDOM) {
      randomComputerMove(board);
    } else if(gameChoice == ONE_PLAYER_SMART) {
      smartComputerMove(board);
    }
    s = getStatus(board);

  }

  printf("Final Board:\n");
  printBoard(board);

  if(s == O_WINS) {
    printf("O Wins!\n");
  } else if(s == X_WINS) {
    printf("X Wins!\n");
  } else if(s == TIE) {
    printf("Cats game, please play again!\n");
  }

  return 0;
}
