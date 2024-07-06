/**
 * @file model.h
 * @brief This file contains the declaration of the Model class for the snake
 * game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_MODEL_MODEL_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_MODEL_MODEL_H_

#include <functional>

#include "../../common/fsm_types.h"
#include "../../common/parameters/parameters.h"
#include "../Action/action.h"

namespace s21 {

/**
 * @brief Array of time steps for different levels.
 */
inline constexpr long long ARRAY_OF_TIME_STEP[11] = {
    500, 450, 400, 350, 300, 250, 225, 200, 175, 150, 125};

inline constexpr int MAX_LEVEL_NUMBER = 10;

/**
 * @brief Table defining the Finite State Machine (FSM) for the snake game.
 */
const std::function<void(Parameters *)> FSM_TABLE[7][8] = {
    {nullptr, nullptr, nullptr, nullptr, nullptr, Action::exit, Action::spawn,
     nullptr},
    {Action::spawn, Action::spawn, Action::spawn, Action::spawn, Action::spawn,
     Action::spawn, Action::spawn, Action::spawn},
    {nullptr, Action::movingUp, Action::movingDown, Action::movingLeft,
     Action::movingRight, Action::exit, nullptr, Action::pause},
    {Action::collide, Action::collide, Action::collide, Action::collide,
     Action::collide, Action::collide, Action::collide, Action::collide},
    {Action::gameOver, Action::gameOver, Action::gameOver, Action::gameOver,
     Action::gameOver, Action::gameOver, Action::gameOver, Action::gameOver},
    {Action::exit, Action::exit, Action::exit, Action::exit, Action::exit,
     Action::exit, Action::exit, Action::exit},
    {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
     Action::pause},
};

/**
 * @brief Class representing the model of the snake game.
 */
class Model {
 public:
  /**
   * @brief Default constructor for the Model class.
   */
  Model();

  /**
   * @brief Perform the action based on the current signal type.
   */
  void signalAction();

  /**
   * @brief Set the signal type for the model.
   *
   * @param signalType The signal type to be set.
   */
  void setSignalType(SignalType signalType);

  /**
   * @brief Set the parameters for the model.
   *
   * @param parameters Pointer to the Parameters object.
   */
  void setParameters(Parameters *parameters);

  /**
   * @brief Get the current state of the model.
   *
   * @return The current state of the model.
   */
  State getState();

  /**
   * @brief Get the current signal type of the model.
   *
   * @return The current signal type of the model.
   */
  SignalType getSignal();

  /**
   * @brief Get the parameters of the model.
   *
   * @return Pointer to the Parameters object.
   */
  Parameters *getParameters();

 private:
  SignalType signalType_;  /**< The current signal type */
  Parameters *parameters_; /**< Pointer to the Parameters object */

  /**
   * @brief Get the time step in milliseconds based on the game status.
   *
   * @param gameStatus Pointer to the GameStatus object.
   * @return The time step in milliseconds.
   */
  static long long int getTimeStepMS(GameStatus *gameStatus);
};

}  // namespace s21

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_SNAKE_MODEL_MODEL_H_
