#include "player_board.h"

void initPlayerBoard(PlayerBoard *playerBoard) {
  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      initCell(&playerBoard->board[i][j]);
    }
  }
}

void copyPlayerBoard(PlayerBoard *playerBoardDest, PlayerBoard playerBoardSrc) {
  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      copyCell(&playerBoardDest->board[i][j], playerBoardSrc.board[i][j]);
    }
  }
}

void setPlayerBoardBlock(PlayerBoard *playerBoard, BlockType blockType,
                         Direction blockDirection) {
  BlockColorType blockColorType = getBlockColor(blockType);
  int mask = 0b1000000000000000;

  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; rowIndex++) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; columnIndex++) {
      playerBoard->board[rowIndex][columnIndex].color = blockColorType;
      if (BLOCK_BIT_MASK[blockType][blockDirection] & mask) {
        playerBoard->board[rowIndex][columnIndex].isSet = true;
      } else {
        initCell(&playerBoard->board[rowIndex][columnIndex]);
      }
      mask >>= 1;
    }
  }
}