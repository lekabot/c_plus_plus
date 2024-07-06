/**
 * @file backend.h
 * @brief This file contains the declaration of functions and constants related
 * to the backend of the Tetris game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_BACKEND_BACKEND_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_BACKEND_BACKEND_H_

#include <string.h>

#include "../../common/block/block.h"
#include "../../common/board/board.h"
#include "../../common/cell/cell.h"
#include "../../common/collisions_checker/collisions_checker.h"
#include "../../common/game_status/game_status.h"
#include "../../common/parameters/parameters.h"
#include "../../common/player/player.h"
#include "../../common/records/records.h"
#include "../../common/time_handler/time_handler.h"

#define MAX_LEVEL_COUNT (10)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Array of time steps for different levels.
 */
static const long long ARRAY_OF_TIME_STEP[11] = {1000, 875, 625, 550, 425, 350,
                                                 325,  300, 250, 200, 150};

/**
 * @brief Overlay the block on the board for a specific player.
 *
 * @param player Pointer to the Player object.
 * @param board Pointer to the Board object.
 */
void boardOverlayBlock(Player *player, Board *board);

/**
 * @brief Move the predicted player down on the board.
 *
 * @param player Pointer to the Player object.
 * @param board Pointer to the Board object.
 */
void movePredictPlayerDown(Player *player, Board *board);

/**
 * @brief Update the predicted player with the data from another player and
 * board.
 *
 * @param playerDest Pointer to the destination Player object.
 * @param playerSrc Source Player object to copy from.
 * @param board Pointer to the Board object.
 */
void updatePredictPlayer(Player *playerDest, Player playerSrc, Board *board);

/**
 * @brief Get the time step in milliseconds based on the game status.
 *
 * @param gameStatus Pointer to the GameStatus object.
 * @return The time step in milliseconds.
 */
long long int getTimeStepMS(GameStatus *gameStatus);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_BACKEND_BACKEND_H_
