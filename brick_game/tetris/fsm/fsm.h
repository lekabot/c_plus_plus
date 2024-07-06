/**
 * @file fsm.h
 * @brief This file contains the declaration of functions and constants related
 * to the Finite State Machine (FSM) for the Tetris game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_FSM_FSM_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_FSM_FSM_H_

#include "../../../gui/cli/frontend.h"
#include "../../common/collisions_checker/collisions_checker.h"
#include "../../common/common/defines.h"
#include "../../common/fsm_types.h"
#include "../backend/backend.h"
#include "callback.h"

#define KEY_DOWN 0402   /**< The key code for the down-arrow key. */
#define KEY_UP 0403     /**< The key code for the up-arrow key. */
#define KEY_LEFT 0404   /**< The key code for the left-arrow key. */
#define KEY_RIGHT 0405  /**< The key code for the right-arrow key. */
#define DELETE (127)    /**< The key code for the delete key. */
#define ESCAPE (27)     /**< The key code for the escape key. */
#define ENTER_KEY (10)  /**< The key code for the enter key. */
#define PAUSE_KEY ('p') /**< The key code for the pause key. */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the signal based on the user input and current game state.
 *
 * @param userInput User input key code.
 * @param hold Flag indicating if the key is being held down.
 * @param keyHeld Pointer to a boolean indicating if the key is being held down.
 * @return The SignalType based on the user input.
 */
SignalType getSignal(int userInput, bool hold, bool *keyHeld);

/**
 * @brief Perform the action based on the signal and current parameters.
 *
 * @param signal The signal to be processed.
 * @param parameters Pointer to the Parameters object.
 */
void signalAction(SignalType signal, Parameters *parameters);

/**
 * @brief Perform the action of spawning a new block in the game.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionSpawn(Parameters *parameters);

/**
 * @brief Perform the action of moving the current block upwards.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionMoveUp(Parameters *parameters);

/**
 * @brief Perform the action of moving the current block downwards.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionMoveDown(Parameters *parameters);

/**
 * @brief Perform the action of moving the current block to the right.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionMoveRight(Parameters *parameters);

/**
 * @brief Perform the action of moving the current block to the left.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionMoveLeft(Parameters *parameters);

/**
 * @brief Perform the action of handling a collision in the game.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionCollide(Parameters *parameters);

/**
 * @brief Perform the action of ending the game due to a game over condition.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionGameOver(Parameters *parameters);

/**
 * @brief Perform the action of exiting the current state.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionExitState(Parameters *parameters);

/**
 * @brief Perform the action of pausing the game.
 *
 * @param parameters Pointer to the Parameters object.
 */
void actionPause(Parameters *parameters);

/**
 * @brief Check for collisions in the game and return the result.
 *
 * @param parameters Pointer to the Parameters object.
 * @return True if collisions are detected, false otherwise.
 */
bool checkCollisions(Parameters *parameters);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_FSM_FSM_H_