/**
 * @file collisions_checker.h
 * @brief This file contains function prototypes for checking collisions in the
 * brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_COLLISIONS_CHECKER_COLLISIONS_CHECKER_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_COLLISIONS_CHECKER_COLLISIONS_CHECKER_H_

#include "../board/board.h"
#include "../parameters/parameters.h"
#include "../player/player.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Perform collision check with a specific side of the board.
 * @param board Pointer to the game board.
 * @param boardSide Side of the board to check for collision.
 * @param x X-coordinate to check for collision.
 * @param y Y-coordinate to check for collision.
 * @return True if a collision is detected, otherwise false.
 */
bool performCollideCheckWithSide(Board *board, BoardSide boardSide, int x,
                                 int y);

/**
 * @brief Check for collision with a specific side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @param boardSide Side of the board to check for collision.
 * @return True if a collision is detected, otherwise false.
 */
bool checkCollideWithSide(Player *player, Board *board, BoardSide boardSide);

/**
 * @brief Check for collision with the upper side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a collision with the upper side is detected, otherwise false.
 */
bool checkCollideWithUp(Player *player, Board *board);

/**
 * @brief Check for collision with the lower side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a collision with the lower side is detected, otherwise false.
 */
bool checkCollideWithDown(Player *player, Board *board);

/**
 * @brief Check for collision with the left side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a collision with the left side is detected, otherwise false.
 */
bool checkCollideWithLeft(Player *player, Board *board);

/**
 * @brief Check for collision with the right side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a collision with the right side is detected, otherwise false.
 */
bool checkCollideWithRight(Player *player, Board *board);

/**
 * @brief Check for collision with any side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a collision with any side is detected, otherwise false.
 */
bool checkCollide(Player *player, Board *board);

/**
 * @brief Perform future collision check with a specific side of the board.
 * @param board Pointer to the game board.
 * @param boardSide Side of the board to check for future collision.
 * @param x X-coordinate to check for future collision.
 * @param y Y-coordinate to check for future collision.
 * @return True if a future collision is detected, otherwise false.
 */
bool performFutureCollideCheckWithSide(Board *board, BoardSide boardSide, int x,
                                       int y);

/**
 * @brief Check for future collision with a specific side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @param boardSide Side of the board to check for future collision.
 * @return True if a future collision with the specified side is detected,
 * otherwise false.
 */
bool checkFutureCollideWithSide(Player *player, Board *board,
                                BoardSide boardSide);

/**
 * @brief Check for future collision with the upper side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a future collision with the upper side is detected, otherwise
 * false.
 */
bool checkFutureCollideWithUp(Player *player, Board *board);

/**
 * @brief Check for future collision with the lower side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a future collision with the lower side is detected, otherwise
 * false.
 */
bool checkFutureCollideWithDown(Player *player, Board *board);

/**
 * @brief Check for future collision with the left side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a future collision with the left side is detected, otherwise
 * false.
 */
bool checkFutureCollideWithLeft(Player *player, Board *board);

/**
 * @brief Check for future collision with the right side of the board.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a future collision with the right side is detected, otherwise
 * false.
 */
bool checkFutureCollideWithRight(Player *player, Board *board);

/**
 * @brief Check for collision with the game blocks.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a collision with the game blocks is detected, otherwise
 * false.
 */
bool checkCollideWithBlocks(Player *player, Board *board);

/**
 * @brief Check for future collision with the blocks on the left side of the
 * player.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a future collision with the blocks on the left side is
 * detected, otherwise false.
 */
bool checkFutureCollideWithBlocksLeft(Player *player, Board *board);

/**
 * @brief Check for future collision with the blocks on the right side of the
 * player.
 * @param player Pointer to the player object.
 * @param board Pointer to the game board.
 * @return True if a future collision with the blocks on the right side is
 * detected, otherwise false.
 */
bool checkFutureCollideWithBlocksRight(Player *player, Board *board);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_COLLISIONS_CHECKER_COLLISIONS_CHECKER_H_
