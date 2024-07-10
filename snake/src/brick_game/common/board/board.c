#include "board.h"

void initBoard(Board *board) {
  board->width = BOARD_WIDTH;
  board->height = BOARD_HEIGHT;
  for (int i = 0; i < board->height; ++i) {
    for (int j = 0; j < board->width; ++j) {
      initCell(&board->cells[i][j]);
    }
  }
}

int handleBoardCompleteLines(Board *board) {
  int completeLinesCount = 0;
  for (int rowIndex = board->height; rowIndex >= 0; --rowIndex) {
    for (int colIndex = board->height; colIndex >= 0; --colIndex) {
      bool flag = checkBoardCompleteLine(board, rowIndex);
      if (flag) {
        completeLinesCount++;
        removeBoardLine(board, rowIndex);
        applyPhysics(board);
      }
    }
  }
  return completeLinesCount;
}
void removeBoardLine(Board *board, int lineIndex) {
  for (int columnIndex = 0; columnIndex < BOARD_WIDTH; ++columnIndex) {
    initCell(&board->cells[lineIndex][columnIndex]);
  }
}

bool checkBoardCompleteLine(Board *board, int rowIndex) {
  bool flag = true;
  for (int columnIndex = 0; columnIndex < BOARD_WIDTH; ++columnIndex) {
    if (!board->cells[rowIndex][columnIndex].isSet) {
      flag = false;
    }
  }
  return flag;
}

void applyPhysics(Board *board) {
  for (int rowIndex = board->height - 1; rowIndex >= 0; --rowIndex) {
    bool emptyLineFlag = true;
    for (int columnIndex = 0; columnIndex < board->width && emptyLineFlag;
         ++columnIndex) {
      if (board->cells[rowIndex][columnIndex].isSet) {
        emptyLineFlag = false;
      }
    }
    if (emptyLineFlag) {
      shiftBoardDown(board, rowIndex);
    }
  }
}

void shiftBoardDown(Board *board, int emptyRowIndex) {
  for (int rowIndex = emptyRowIndex; rowIndex > 1; --rowIndex) {
    copyBoardLine(board, rowIndex, rowIndex - 1);
  }
}

void copyBoardLine(Board *board, int indexDest, int indexSrc) {
  for (int i = 0; i < BOARD_WIDTH; ++i) {
    copyCell(&board->cells[indexDest][i], board->cells[indexSrc][i]);
  }
}