#include "model.h"

#include <unistd.h>

#include <iostream>

#include "../../common/time_handler/time_handler.h"
#include "../move_snake/move_snake.h"

namespace s21 {

Model::Model() {}

void Model::signalAction() {
  State currentState = getState();
  SignalType currentSignal = getSignal();
  Parameters *parameters = getParameters();

  std::function<void(Parameters *)> action =
      FSM_TABLE[currentState][currentSignal];

  if (action) {
    action(parameters);
  }

  long long timeInMs = getTimeInMS();

  if (*parameters->tetrisState == S_MOVING) {
    long long timeStep = getTimeStepMS(parameters->snakeGameStatus);
    if (timeInMs - *parameters->snakeLastetMovedTime > timeStep) {
      *parameters->snakeLastetMovedTime = timeInMs;
      moveSnake(parameters);
    }
  }
}
void Model::setParameters(Parameters *parameters) { parameters_ = parameters; }
void Model::setSignalType(SignalType signalType) { signalType_ = signalType; }
State Model::getState() { return *parameters_->snakeState; }
SignalType Model::getSignal() { return signalType_; }
Parameters *Model::getParameters() { return parameters_; }

long long int Model::getTimeStepMS(GameStatus *gameStatus) {
  if (gameStatus->level > MAX_LEVEL_NUMBER) {
    gameStatus->level = MAX_LEVEL_NUMBER;
  }
  return ARRAY_OF_TIME_STEP[gameStatus->level];
}

}  // namespace s21