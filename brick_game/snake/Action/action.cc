#include "action.h"

#include "../move_snake/move_snake.h"

namespace s21 {

void Action::start(Parameters *parameters) {
  *parameters->snakeState = S_SPAWN;
}
void Action::spawn(Parameters *parameters) {
  initPlayer(parameters->snakePlayer);
  parameters->snakePlayer->snakeLength = 4;
  parameters->snakeGameStatus->level = 0;
  parameters->snakeGameStatus->score = 0;
  for (int i = 3; i >= 0; --i) {
    parameters->snakePlayer->snakeBody[i].x = 5;
    parameters->snakePlayer->snakeBody[i].y = 5 + i + 1;
  }
  *parameters->snakeState = S_MOVING;
  parameters->snakePlayer->direction = DIRECTION_2;

  moveFruitToRandomPlace(parameters);
}
void Action::movingUp(Parameters *parameters) {
  if (parameters->snakePlayer->direction != DIRECTION_2) {
    parameters->snakePlayer->direction = DIRECTION_1;
  }
  moveSnake(parameters);
}
void Action::movingDown(Parameters *parameters) {
  if (parameters->snakePlayer->direction != DIRECTION_1) {
    parameters->snakePlayer->direction = DIRECTION_2;
  }
  moveSnake(parameters);
}
void Action::movingLeft(Parameters *parameters) {
  if (parameters->snakePlayer->direction != DIRECTION_4) {
    parameters->snakePlayer->direction = DIRECTION_3;
  }
  moveSnake(parameters);
}
void Action::movingRight(Parameters *parameters) {
  if (parameters->snakePlayer->direction != DIRECTION_3) {
    parameters->snakePlayer->direction = DIRECTION_4;
  }
  moveSnake(parameters);
}
void Action::collide(Parameters *parameters) {
  *parameters->snakeState = S_GAME_OVER;
}
void Action::gameOver(Parameters *parameters) {
  *parameters->tetrisState = *parameters->tetrisState;
}
void Action::exit(Parameters *parameters) {
  *parameters->snakeState = S_EXIT_STATE;
}
void Action::pause(Parameters *parameters) {
  if (*parameters->snakeState == S_PAUSE) {
    *parameters->snakeState = S_MOVING;
  } else if (*parameters->snakeState == S_MOVING) {
    *parameters->snakeState = S_PAUSE;
  }
}
}  // namespace s21
