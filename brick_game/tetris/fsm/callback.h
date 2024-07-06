/**
 * @file fsm_callback.h
 * @brief This file contains the declaration of the action callback function
 * pointer type for the Tetris game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_FSM_CALLBACK_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_FSM_CALLBACK_H_

#include "../../common/parameters/parameters.h"

/**
 * @brief Function pointer type for the action callback function.
 *
 * This function type represents a callback function that takes a pointer to
 * Parameters as an argument and returns void.
 */
typedef void (*action_callback)(Parameters *parameters);

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_TETRIS_FSM_CALLBACK_H_
