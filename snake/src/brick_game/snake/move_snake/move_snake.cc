#include "move_snake.h"

#include <cstdlib>

namespace s21 {

void moveFruitToRandomPlace(Parameters *parameters) {
  parameters->snakeFruit->x = (rand() % parameters->snakeBoard->width);
  parameters->snakeFruit->y = (rand() % parameters->snakeBoard->height);
}

int calculateLevel(const Parameters *parameters) {
  return parameters->snakeGameStatus->score / 5;
}

void eatFruit(Parameters *parameters) {
  parameters->snakePlayer->snakeLength++;
  parameters->snakeGameStatus->score++;
  parameters->snakeGameStatus->level = calculateLevel(parameters);
}

void handleMoveTail(Parameters *parameters) {
  for (int i = parameters->snakePlayer->snakeLength - 1; i > 0; --i) {
    parameters->snakePlayer->snakeBody[i] =
        parameters->snakePlayer->snakeBody[i - 1];
  }
}
void handleMoveHead(Parameters *parameters) {
  if (parameters->snakePlayer->direction == DIRECTION_1) {
    parameters->snakePlayer->snakeBody[0].y--;
  } else if (parameters->snakePlayer->direction == DIRECTION_2) {
    parameters->snakePlayer->snakeBody[0].y++;

  } else if (parameters->snakePlayer->direction == DIRECTION_3) {
    parameters->snakePlayer->snakeBody[0].x--;

  } else if (parameters->snakePlayer->direction == DIRECTION_4) {
    parameters->snakePlayer->snakeBody[0].x++;
  }
}
bool getFlagEatFruitX(const Parameters *parameters) {
  bool flag =
      parameters->snakePlayer->snakeBody[0].x == parameters->snakeFruit->x;
  return flag;
}
bool getFlagEatFruitY(const Parameters *parameters) {
  bool flag =
      parameters->snakePlayer->snakeBody[0].y == parameters->snakeFruit->y;
  return flag;
}

void handleEatFruit(Parameters *parameters) {
  bool flagEatFruitX = getFlagEatFruitX(parameters);
  bool flagEatFruitY = getFlagEatFruitY(parameters);
  bool flagEatFruit = flagEatFruitX && flagEatFruitY;
  if (flagEatFruit) {
    eatFruit(parameters);
    moveFruitToRandomPlace(parameters);
    addRecord(parameters->snakeRecords, "Unnamed",
              parameters->snakeGameStatus->score, SNAKE_RECORDS_FILE_NAME);
    if (parameters->snakePlayer->snakeLength >= 200) {
      *parameters->snakeState = S_GAME_OVER;
    }
  }
}

bool getFlagCollideWithHeadX(const Parameters *parameters, int i) {
  bool flag = parameters->snakePlayer->snakeBody[0].x ==
              parameters->snakePlayer->snakeBody[i].x;
  return flag;
}
bool getFlagCollideWithHeadY(const Parameters *parameters, int i) {
  bool flag = parameters->snakePlayer->snakeBody[0].y ==
              parameters->snakePlayer->snakeBody[i].y;
  return flag;
}
void handleCollideWithItself(Parameters *parameters) {
  int firstSegmentToCollideIndex = 4;
  for (int i = firstSegmentToCollideIndex;
       i < parameters->snakePlayer->snakeLength; ++i) {
    bool flagCollideWithHeadX = getFlagCollideWithHeadX(parameters, i);
    bool flagCollideWithHeadY = getFlagCollideWithHeadY(parameters, i);
    bool is_collide_with_head = (flagCollideWithHeadX && flagCollideWithHeadY);
    if (is_collide_with_head) {
      *parameters->snakeState = S_COLLIDE;
      break;
    }
  }
}
void moveSnake(Parameters *parameters) {
  handleMoveTail(parameters);
  handleMoveHead(parameters);
  handleEatFruit(parameters);
  handleCollideWithWall(parameters);
  handleCollideWithItself(parameters);
}
bool getFlagCollideWallX(const Parameters *parameters) {
  bool flagCollideWithLeft = parameters->snakePlayer->snakeBody[0].x < 0;
  bool flagCollideWithRight =
      parameters->snakePlayer->snakeBody[0].x >= parameters->snakeBoard->width;
  bool flag = flagCollideWithLeft || flagCollideWithRight;
  return flag;
}
bool getFlagCollideWallY(const Parameters *parameters) {
  bool flagCollideWithUp = parameters->snakePlayer->snakeBody[0].y < 0;
  bool flagCollideWithDown =
      parameters->snakePlayer->snakeBody[0].y >= parameters->snakeBoard->height;
  bool flag = flagCollideWithUp || flagCollideWithDown;
  return flag;
}

void handleCollideWithWall(Parameters *parameters) {
  bool flagCollideWithX = getFlagCollideWallX(parameters);
  bool flagCollideWithY = getFlagCollideWallY(parameters);
  bool isCollideWall = flagCollideWithX || flagCollideWithY;
  if (isCollideWall) {
    *parameters->snakeState = S_COLLIDE;
  }
}

}  // namespace s21
