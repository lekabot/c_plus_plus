/**
 * @file fsm_types.h
 * @brief This file contains the definition of the state and signal types used
 * in the finite state machine.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_FSM_TYPES_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_FSM_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumeration of possible states in the finite state machine.
 */
typedef enum {
  S_START = 0,      /**< Initial state of the game. */
  S_SPAWN = 1,      /**< State related to block spawning. */
  S_MOVING = 2,     /**< State relating to block movements. */
  S_COLLIDE = 3,    /**< State representing a collision. */
  S_GAME_OVER = 4,  /**< State indicating the end of the game. */
  S_EXIT_STATE = 5, /**< State for exiting the game. */
  S_PAUSE = 6,      /**< State representing a paused game. */
} State;

/**
 * @brief Enumeration of possible signal types for the finite state machine.
 */
typedef enum {
  S_NONE = 0,          /**< No specific signal. */
  S_MOVE_UP = 1,       /**< Signal for moving up. */
  S_MOVE_DOWN = 2,     /**< Signal for moving down. */
  S_MOVE_LEFT = 3,     /**< Signal for moving left. */
  S_MOVE_RIGHT = 4,    /**< Signal for moving right. */
  S_ESCAPE_BUTTON = 5, /**< Signal for the escape button. */
  S_ENTER_BUTTON = 6,  /**< Signal for the enter button. */
  S_PAUSE_BUTTON = 7,  /**< Signal for the pause button. */
} SignalType;

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_FSM_TYPES_H_
