/**
 * @file game_status.h
 * @brief This file contains definitions and functions related to the game
 * status in the brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_GAME_STATUS_GAME_STATUS_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_GAME_STATUS_GAME_STATUS_H_

#define MAX_LEVEL (10)
#define MAX_AVAILABLE_COMPLETE_LINES_COUNT (4)
#define SCORE_PER_LEVEL (600)

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Array storing score points for completing different numbers of lines.
 */
static const int SCORE_COMPLETE_LINES_COUNT_ARRAY[4] = {100, 300, 700, 1500};

/**
 * @brief Structure representing the game status including score and level.
 */
typedef struct {
  int score; /**< The current score of the game. */
  int level; /**< The current level of the game. */
} GameStatus;

/**
 * @brief Initialize the game status.
 * @param gameStatus Pointer to the game status structure to be initialized.
 */
void initGameStatus(GameStatus *gameStatus);

/**
 * @brief Add score to the game status based on the number of complete lines.
 * @param gameStatus Pointer to the game status structure.
 * @param completeLinesCount The number of complete lines to add score for.
 */
void addScoreGameStatus(GameStatus *gameStatus, int completeLinesCount);

/**
 * @brief Update the game status level based on the current score and predefined
 * rules.
 * @param gameStatus Pointer to the game status structure.
 */
void updateGameStatusLevel(GameStatus *gameStatus);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_GAME_STATUS_GAME_STATUS_H_
