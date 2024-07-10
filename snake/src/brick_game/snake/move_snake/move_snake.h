/**
 * @file move_snake.h
 * @brief This file contains the declaration of functions related to moving the
 * snake in the snake game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_MOVE_SNAKE_MOVE_SNAKE_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_MOVE_SNAKE_MOVE_SNAKE_H_

#include "../../common/parameters/parameters.h"

namespace s21 {
/**
 * @brief Move the fruit to a random place on the game board.
 *
 * @param parameters Pointer to the Parameters object.
 */
void moveFruitToRandomPlace(Parameters *parameters);

/**
 * @brief Handle the collision of the snake with the wall.
 *
 * @param parameters Pointer to the Parameters object.
 */
void handleCollideWithWall(Parameters *parameters);

/**
 * @brief Function to handle the snake eating the fruit.
 *
 * @param parameters Pointer to the Parameters object.
 */
void eatFruit(Parameters *parameters);

/**
 * @brief Function to handle the movement of the snake's head.
 *
 * @param parameters Pointer to the Parameters object.
 */
void handleMoveHead(Parameters *parameters);

/**
 * @brief Function to move the snake.
 *
 * @param parameters Pointer to the Parameters object.
 */
void moveSnake(Parameters *parameters);

/**
 * @brief Function to handle the collision of the snake with itself.
 *
 * @param parameters Pointer to the Parameters object.
 */
void handleCollideWithItself(Parameters *parameters);
}  // namespace s21

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_MOVE_SNAKE_MOVE_SNAKE_H_
