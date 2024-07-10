#include "backend.h"

void boardOverlayBlock(Player *player, Board *board) {
  PlayerBoard *playerBoard = &player->board;

  int playerPosX = player->x;
  int playerPosY = player->y - 1;

  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      int cellGlobalPosX = playerPosX + columnIndex;
      int cellGlobalPosY = playerPosY + rowIndex;
      Cell *boardcell = &board->cells[cellGlobalPosY][cellGlobalPosX];
      Cell playerCell = playerBoard->board[rowIndex][columnIndex];

      if (playerCell.isSet) {
        copyCell(boardcell, playerCell);
      }
    }
  }
}

void movePredictPlayerDown(Player *player, Board *board) {
  bool breakFlag = false;
  while (!breakFlag) {
    if (checkFutureCollideWithDown(player, board)) {
      breakFlag = true;
    }
    if (checkCollideWithBlocks(player, board)) {
      breakFlag = true;
    }
    if (!breakFlag) {
      movePlayerDown(player);
    }
  }
  movePlayerUp(player);
}

void updatePredictPlayer(Player *playerDest, Player playerSrc, Board *board) {
  copyPlayer(playerDest, playerSrc);
  movePredictPlayerDown(playerDest, board);
  setNextPlayerColor(playerDest);
}

long long int getTimeStepMS(GameStatus *gameStatus) {
  if (gameStatus->level > MAX_LEVEL_COUNT) {
    gameStatus->level = MAX_LEVEL_COUNT;
  }
  return ARRAY_OF_TIME_STEP[gameStatus->level];
}
