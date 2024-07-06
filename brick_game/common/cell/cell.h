/**
 * @file cell.h
 * @brief This file contains the data structure and functions related to game
 * cells for the brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_CELL_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_CELL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

/**
 * @struct Cell
 * @brief Structure representing a single cell in the game board.
 */
typedef struct {
  unsigned char color; /**< Color of the cell */
  bool isSet;          /**< Boolean indicating if the cell is set or not */
  int x;               /**< X-coordinate of the cell */
  int y;               /**< Y-coordinate of the cell */
} Cell;

/**
 * @brief Initialize a cell.
 * @param cell Pointer to the cell to be initialized.
 */
void initCell(Cell *cell);

/**
 * @brief Copy the content of one cell to another.
 * @param cellDest Pointer to the destination cell.
 * @param cellSrc Source cell from which the content will be copied.
 */
void copyCell(Cell *cellDest, Cell cellSrc);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_CELL_H_
