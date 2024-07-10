#include "player.h"

void initPlayer(Player *player) {
  initPlayerBoard(&player->board);
  setPlayerBlockType(player, getRandomBlockType());
}

void initNextPlayer(Player *player) {
  initPlayer(player);
  player->x = INIT_NEXT_PLAYER_POS_X;
  player->y = INIT_NEXT_PLAYER_POS_Y;
}

void initPlayerPosition(Player *player) {
  player->x = INIT_PLAYER_POS_X;
  player->y = INIT_PLAYER_POS_Y;
  player->blockType = BLOCK_SNAKE;
  player->direction = DIRECTION_4;
}

void copyPlayer(Player *playerDest, Player playerSrc) {
  playerDest->x = playerSrc.x;
  playerDest->y = playerSrc.y;
  playerDest->blockType = playerSrc.blockType;
  playerDest->direction = playerSrc.direction;
  playerDest->board = playerSrc.board;
}

void setPlayerBlockType(Player *player, BlockType blockType) {
  player->blockType = blockType;
  updatePlayerBoard(player);
}

void setPlayerBlockDirection(Player *player, Direction blockDirection) {
  player->direction = blockDirection;
  updatePlayerBoard(player);
}

void setPlayerPosition(Player *player, int x, int y) {
  player->x = x;
  player->y = y;
}

void setPlayerNextBlockDirection(Player *player) {
  Direction blockDirection = player->direction;

  Direction nextBlockDirection = getNextBlockDirection(blockDirection);

  setPlayerBlockDirection(player, nextBlockDirection);
  setPlayerBoardBlock(&player->board, player->blockType, player->direction);
}

void setPlayerPreviousBlockDirection(Player *player) {
  Direction blockDirection = player->direction;

  Direction previousBlockDirection = getPreviousBlockDirection(blockDirection);

  setPlayerBlockDirection(player, previousBlockDirection);
  setPlayerBoardBlock(&player->board, player->blockType, player->direction);
}

void updatePlayerBoard(Player *player) {
  setPlayerBoardBlock(&player->board, player->blockType, DIRECTION_1);
}

void movePlayerByDXDY(Player *player, int dX, int dY) {
  player->x += dX;
  player->y += dY;
}

void movePlayerUp(Player *player) { movePlayerByDXDY(player, 0, -1); }
void movePlayerDown(Player *player) { movePlayerByDXDY(player, 0, 1); }
void movePlayerLeft(Player *player) { movePlayerByDXDY(player, -1, 0); }
void movePlayerRight(Player *player) { movePlayerByDXDY(player, 1, 0); }

void setNextPlayerColor(Player *player) {
  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (player->board.board[i][j].isSet) {
        player->board.board[i][j].color = BLOCK_COLOR_PREDICT;
      }
    }
  }
}