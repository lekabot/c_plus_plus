/**
 * @file parameters.h
 * @brief This file contains the definition of the Parameters structure used in
 * the brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PARAMETERS_PARAMETERS_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PARAMETERS_PARAMETERS_H_

#include <utime.h>

#include "../board/board.h"
#include "../fsm_types.h"
#include "../game_status/game_status.h"
#include "../player/player.h"
#include "../records/records.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Structure to store various game parameters such as state, game status,
 * board, player, records, etc.
 */
typedef struct {
  union {
    struct {
      State *tetrisState; /**< Pointer to the state of the Tetris game. */
      GameStatus *tetrisGameStatus; /**< Pointer to the game status of the
                                       Tetris game. */
      Board *tetrisBoard; /**< Pointer to the game board of the Tetris game. */
      Player
          *tetrisPlayer; /**< Pointer to the main player of the Tetris game. */
      Player *tetrisNextetPlayer;  /**< Pointer to the next player of the Tetris
                                      game. */
      Player *tetrisPredictPlayer; /**< Pointer to the predict player of the
                                      Tetris game. */
      Records *tetrisRecords; /**< Pointer to the records of the Tetris game. */
      long long *tetrisLastetMovedTime; /**< Pointer to the last moved time of
                                           the Tetris game. */
      char tetrisUsername[20];          /**< Username for the Tetris game. */
    };
    struct {
      State *snakeState;   /**< Pointer to the state of the Snake game. */
      Player *snakePlayer; /**< Pointer to the main player of the Snake game. */
      Cell *snakeFruit;    /**< Pointer to the fruit cell in the Snake game. */
      GameStatus *
          snakeGameStatus; /**< Pointer to the game status of the Snake game. */
      Board *snakeBoard;   /**< Pointer to the game board of the Snake game. */
      Records *snakeRecords; /**< Pointer to the records of the Snake game. */
      long long *snakeLastetMovedTime; /**< Pointer to the last moved time of
                                          the Snake game. */
      char snakeUsername[20];          /**< Username for the Snake game. */
    };
  };
} Parameters;

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_PARAMETERS_PARAMETERS_H_
