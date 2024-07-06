/**
 * @file controller.h
 * @brief This file contains the declaration of the controller function for the
 * snake game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_CONTROLLER_CONTROLLER_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_CONTROLLER_CONTROLLER_H_

#include "../../common/fsm_types.h"
#include "../../common/parameters/parameters.h"
#include "../../common/time_handler/time_handler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Function to control the snake game based on the input signal.
 *
 * @param signal The input signal to control the game.
 * @param parameters Pointer to the Parameters object containing game
 * parameters.
 */
extern void controllerSnake(SignalType signal, Parameters *parameters);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_CONTROLLER_CONTROLLER_H_
