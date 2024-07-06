/**
 * @file board.h
 * @brief This file contains data structures and functions related to the game
 * board for the brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_BOARD_BOARD_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_BOARD_BOARD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../cell/cell.h"

#define BOARD_HEIGHT (20) /**< Number of rows in the game board */
#define BOARD_WIDTH (10)  /**< Number of columns in the game board */

/**
 * @enum BoardSide
 * @brief Enum representing the different sides of the board.
 */
typedef enum {
  BOARD_SIDE_UP = 0,   /**< Up side of the board */
  BOARD_SIDE_DOWN = 1, /**< Down side of the board */
  BOARD_SIDE_LEFT = 2, /**< Left side of the board */
  BOARD_SIDE_RIGHT = 3 /**< Right side of the board */
} BoardSide;

/**
 * @struct Board
 * @brief Structure representing the game board.
 */
typedef struct {
  int height; /**< Height of the board */
  int width;  /**< Width of the board */
  Cell cells[BOARD_HEIGHT]
            [BOARD_WIDTH]; /**< 2D array representing the cells of the board */
} Board;

/**
 * @brief Initialize the game board.
 * @param board Pointer to the game board.
 */
void initBoard(Board *board);

/**
 * @brief Handle complete lines in the board.
 * @param board Pointer to the game board.
 * @return Number of complete lines handled.
 */
int handleBoardCompleteLines(Board *board);

/**
 * @brief Remove a specific line from the board.
 * @param board Pointer to the game board.
 * @param lineIndex Index of the line to be removed.
 */
void removeBoardLine(Board *board, int lineIndex);

/**
 * @brief Apply physics to the game board (e.g., gravity).
 * @param board Pointer to the game board.
 */
void applyPhysics(Board *board);

/**
 * @brief Shift the board down after removing lines.
 * @param board Pointer to the game board.
 * @param emptyRowIndex Index of the row with empty cells.
 */
void shiftBoardDown(Board *board, int emptyRowIndex);

/**
 * @brief Copy a line from one position to another in the board.
 * @param board Pointer to the game board.
 * @param indexDest Destination index.
 * @param indexSrc Source index.
 */
void copyBoardLine(Board *board, int indexDest, int indexSrc);

/**
 * @brief Check if a specific line in the board is complete.
 * @param board Pointer to the game board.
 * @param rowIndex Index of the row to check.
 * @return True if the line is complete, otherwise false.
 */
bool checkBoardCompleteLine(Board *board, int rowIndex);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_BOARD_BOARD_H_
