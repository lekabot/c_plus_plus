/**
 * @file player.h
 * @brief This file contains the definition of the Player structure and related
 * functions.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PLAYER_PLAYER_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PLAYER_PLAYER_H_

#include "../block/block.h"
#include "player_board/player_board.h"

#define INIT_PLAYER_POS_X (3)
#define INIT_PLAYER_POS_Y (0)

#define INIT_NEXT_PLAYER_POS_X (16)
#define INIT_NEXT_PLAYER_POS_Y (1)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure representing the player including position, block type,
 * board, and movement.
 */
typedef struct {
  int x;               /**< The x-coordinate of the player's position. */
  int y;               /**< The y-coordinate of the player's position. */
  BlockType blockType; /**< The type of block the player is using. */
  PlayerBoard board;   /**< The board associated with the player. */
  Cell snakeBody[200]; /**< Array representing the snake body for the player (if
                          applicable). */
  int snakeLength;     /**< The length of the snake body. */
  Direction
      direction; /**< The direction in which the player is currently moving. */
} Player;

/**
 * @brief Initialize the player with default values.
 *
 * @param player Pointer to the Player structure to be initialized.
 */
void initPlayer(Player *player);

/**
 * @brief Initialize the next player with default values.
 *
 * @param player Pointer to the Player structure to be initialized as the next
 * player.
 */
void initNextPlayer(Player *player);

/**
 * @brief Copy the contents of one player to another.
 *
 * @param player_dest Pointer to the destination Player structure.
 * @param playerSrc Source Player structure to be copied.
 */
void copyPlayer(Player *player_dest, Player playerSrc);

/**
 * @brief Initialize the player's position.
 *
 * @param player Pointer to the Player structure.
 */
void initPlayerPosition(Player *player);

/**
 * @brief Set the block type for the player.
 *
 * @param player Pointer to the Player structure.
 * @param blockType Type of the block to be set for the player.
 */
void setPlayerBlockType(Player *player, BlockType blockType);

/**
 * @brief Set the block direction for the player.
 *
 * @param player Pointer to the Player structure.
 * @param blockDirection Direction of the block to be set for the player.
 */
void setPlayerBlockDirection(Player *player, Direction blockDirection);

/**
 * @brief Set the next block direction for the player.
 *
 * @param player Pointer to the Player structure.
 */
void setPlayerNextBlockDirection(Player *player);

/**
 * @brief Set the previous block direction for the player.
 *
 * @param player Pointer to the Player structure.
 */
void setPlayerPreviousBlockDirection(Player *player);

/**
 * @brief Update the player's board based on the block, direction, and position.
 *
 * @param player Pointer to the Player structure.
 */
void updatePlayerBoard(Player *player);

/**
 * @brief Set the color for the next player.
 *
 * @param player Pointer to the Player structure representing the next player.
 */
void setNextPlayerColor(Player *player);

/**
 * @brief Set the position of the player on the board.
 *
 * @param player Pointer to the Player structure.
 * @param x The x-coordinate of the player's position.
 * @param y The y-coordinate of the player's position.
 */
void setPlayerPosition(Player *player, int x, int y);

/**
 * @brief Move the player by the specified offsets.
 *
 * @param player Pointer to the Player structure.
 * @param dX The change in the x-coordinate of the player's position.
 * @param dY The change in the y-coordinate of the player's position.
 */
void movePlayerByDXDY(Player *player, int dX, int dY);

/**
 * @brief Move the player up on the board.
 *
 * @param player Pointer to the Player structure.
 */
void movePlayerUp(Player *player);

/**
 * @brief Move the player down on the board.
 *
 * @param player Pointer to the Player structure.
 */
void movePlayerDown(Player *player);

/**
 * @brief Move the player left on the board.
 *
 * @param player Pointer to the Player structure.
 */
void movePlayerLeft(Player *player);

/**
 * @brief Move the player right on the board.
 *
 * @param player Pointer to the Player structure.
 */
void movePlayerRight(Player *player);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PLAYER_PLAYER_H_
