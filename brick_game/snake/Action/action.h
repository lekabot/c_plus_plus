/**
 * @file action.h
 * @brief This file contains the declaration of the Action class and its member
 * functions.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_ACTION_ACTION_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_ACTION_ACTION_H_

#include <iostream>

#include "../../common/fsm_types.h"
#include "../../common/parameters/parameters.h"

namespace s21 {

/**
 * @brief Class representing actions for the snake game.
 */
class Action {
 public:
  /**
   * @brief Perform the action to start the game.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void start(Parameters *parameters);

  /**
   * @brief Perform the action to spawn an object in the game.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void spawn(Parameters *parameters);

  /**
   * @brief Perform the action to move the object up.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void movingUp(Parameters *parameters);

  /**
   * @brief Perform the action to move the object down.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void movingDown(Parameters *parameters);

  /**
   * @brief Perform the action to move the object left.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void movingLeft(Parameters *parameters);

  /**
   * @brief Perform the action to move the object right.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void movingRight(Parameters *parameters);

  /**
   * @brief Perform the action when a collision occurs.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void collide(Parameters *parameters);

  /**
   * @brief Perform the action when the game is over.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void gameOver(Parameters *parameters);

  /**
   * @brief Perform the action to exit the game.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void exit(Parameters *parameters);

  /**
   * @brief Perform the action to pause the game.
   *
   * @param parameters Pointer to the Parameters object containing game
   * parameters.
   */
  static void pause(Parameters *parameters);
};

}  // namespace s21

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_ACTION_ACTION_H_
