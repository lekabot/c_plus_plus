/**
 * @file player_board.h
 * @brief This file contains the definition of the PlayerBoard structure and
 * related functions.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PLAYER_PLAYER_BOARD_PLAYER_BOARD_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PLAYER_PLAYER_BOARD_PLAYER_BOARD_H_

#include "../../block/block.h"
#include "../../cell/cell.h"

#define PLAYER_BOARD_SIZE (4)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure representing the player's board with cells.
 */
typedef struct {
  Cell board[PLAYER_BOARD_SIZE][PLAYER_BOARD_SIZE]; /**< 2D array representing
                                                       the player's board. */
} PlayerBoard;

/**
 * @brief Initialize the player's board, setting all cells to default values.
 * @param playerBoard Pointer to the PlayerBoard structure to be initialized.
 */
void initPlayerBoard(PlayerBoard *playerBoard);

/**
 * @brief Copy the contents of one player's board to another.
 * @param playerBoardDest Pointer to the destination PlayerBoard structure.
 * @param playerBoardSrc Source PlayerBoard structure to be copied.
 */
void copyPlayerBoard(PlayerBoard *playerBoardDest, PlayerBoard playerBoardSrc);

/**
 * @brief Set a block on the player's board based on the block type and
 * direction.
 * @param playerBoard Pointer to the PlayerBoard structure.
 * @param blockType Type of the block to be set on the board.
 * @param blockDirection Direction of the block to be set on the board.
 */
void setPlayerBoardBlock(PlayerBoard *playerBoard, BlockType blockType,
                         Direction blockDirection);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PLAYER_PLAYER_BOARD_PLAYER_BOARD_H_
