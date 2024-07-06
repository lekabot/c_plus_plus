#include "collisions_checker.h"

bool checkFutureCollideWithUp(Player *player, Board *board) {
  return checkFutureCollideWithSide(player, board, BOARD_SIDE_UP);
}
bool checkFutureCollideWithDown(Player *player, Board *board) {
  return checkFutureCollideWithSide(player, board, BOARD_SIDE_DOWN);
}
bool checkFutureCollideWithLeft(Player *player, Board *board) {
  return checkFutureCollideWithSide(player, board, BOARD_SIDE_LEFT);
}
bool checkFutureCollideWithRight(Player *player, Board *board) {
  return checkFutureCollideWithSide(player, board, BOARD_SIDE_RIGHT);
}

bool checkCollideWithUp(Player *player, Board *board) {
  return checkCollideWithSide(player, board, BOARD_SIDE_UP);
}
bool checkCollideWithDown(Player *player, Board *board) {
  return checkCollideWithSide(player, board, BOARD_SIDE_DOWN);
}
bool checkCollideWithLeft(Player *player, Board *board) {
  return checkCollideWithSide(player, board, BOARD_SIDE_LEFT);
}
bool checkCollideWithRight(Player *player, Board *board) {
  return checkCollideWithSide(player, board, BOARD_SIDE_RIGHT);
}

bool checkCollide(Player *player, Board *board) {
  bool flag = checkCollideWithUp(player, board);
  flag |= checkCollideWithDown(player, board);
  flag |= checkCollideWithLeft(player, board);
  flag |= checkCollideWithRight(player, board);
  flag |= checkCollideWithBlocks(player, board);
  return flag;
}

bool checkCollideWithSide(Player *player, Board *board, BoardSide boardSide) {
  PlayerBoard *playerBoard = &player->board;
  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      if (playerBoard->board[rowIndex][columnIndex].isSet) {
        int cellGlobalPosX = player->x + columnIndex;
        int cellGlobalPosY = player->y + rowIndex;
        bool flag = performCollideCheckWithSide(board, boardSide,
                                                cellGlobalPosX, cellGlobalPosY);
        if (flag) {
          return flag;
        }
      }
    }
  }

  return false;
}

bool checkFutureCollideWithSide(Player *player, Board *board,
                                BoardSide boardSide) {
  PlayerBoard *playerBoard = &player->board;
  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      if (playerBoard->board[rowIndex][columnIndex].isSet) {
        int cellGlobalPosX = player->x + columnIndex;
        int cellGlobalPosY = player->y + rowIndex;
        bool flag = performFutureCollideCheckWithSide(
            board, boardSide, cellGlobalPosX, cellGlobalPosY);
        if (flag) {
          return flag;
        }
      }
    }
  }

  return false;
}

bool performCollideCheckWithSide(Board *board, BoardSide boardSide, int x,
                                 int y) {
  if (boardSide == BOARD_SIDE_UP) {
    if (y < 0) {
      return true;
    }
  } else if (boardSide == BOARD_SIDE_DOWN) {
    if (y > board->height) {
      return true;
    }
  } else if (boardSide == BOARD_SIDE_LEFT) {
    if (x <= -1) {
      return true;
    }
  } else if (boardSide == BOARD_SIDE_RIGHT) {
    if (x >= board->width) {
      return true;
    }
  }
  return false;
}
bool performFutureCollideCheckWithSide(Board *board, BoardSide boardSide, int x,
                                       int y) {
  if (boardSide == BOARD_SIDE_UP) {
    if (y - 1 < 0) {
      return true;
    }
  } else if (boardSide == BOARD_SIDE_DOWN) {
    if (y + 1 > board->height) {
      return true;
    }
  } else if (boardSide == BOARD_SIDE_LEFT) {
    if (x - 1 < 0) {
      return true;
    }
  } else if (boardSide == BOARD_SIDE_RIGHT) {
    if (x + 1 >= board->width) {
      return true;
    }
  }
  return false;
}

bool checkCollideWithBlocks(Player *player, Board *board) {
  PlayerBoard *playerBoard = &player->board;

  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      if (playerBoard->board[rowIndex][columnIndex].isSet) {
        int cellGlobalPosX = player->x + columnIndex;
        int cellGlobalPosY = player->y + rowIndex;
        bool flag = board->cells[cellGlobalPosY][cellGlobalPosX].isSet;
        if (flag) {
          return flag;
        }
      }
    }
  }
  return false;
}
bool checkFutureCollideWithBlocksLeft(Player *player, Board *board) {
  PlayerBoard *playerBoard = &player->board;

  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      if (playerBoard->board[rowIndex][columnIndex].isSet) {
        bool flag = false;
        int cellGlobalPosX = player->x + columnIndex - 1;
        int cellGlobalPosY = player->y + rowIndex;
        if (cellGlobalPosX < -1 || cellGlobalPosX > 8) {
          flag |= true;
        }
        flag |= board->cells[cellGlobalPosY][cellGlobalPosX].isSet;
        if (flag) {
          return flag;
        }
      }
    }
  }
  return false;
}
bool checkFutureCollideWithBlocksRight(Player *player, Board *board) {
  PlayerBoard *playerBoard = &player->board;

  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      if (playerBoard->board[rowIndex][columnIndex].isSet) {
        int cellGlobalPosX = player->x + columnIndex + 1;
        int cellGlobalPosY = player->y + rowIndex;
        bool flag = board->cells[cellGlobalPosY][cellGlobalPosX].isSet;
        if (flag) {
          return flag;
        }
      }
    }
  }
  return false;
}