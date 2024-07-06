#include <gtest/gtest.h>

#include "../brick_game/snake/controller/controller.h"
#include "../brick_game/tetris/backend/backend.h"

namespace s21 {
class ModelTest : public ::testing::Test {
 protected:
  Records records{};
  GameStatus game_status{};
  State state = S_START;
  Player player{};
  Board board{};
  long long time_in_secs{};
  Cell fruit{};
  SignalType signal_type{};
  Parameters parameters{};

  void SetUp() override {
    signal_type = S_NONE;
    initBoard(&board);
    initGameStatus(&game_status);
    initPlayer(&player);
    setPlayerPosition(&player, 10, 10);
    player.snakeLength = 4;
    player.direction = DIRECTION_2;
    player.snakeBody[0].x = 10 / 2;
    player.snakeBody[0].y = 20 / 2;

    initCell(&fruit);
    fruit.y = rand() % 10;
    fruit.x = rand() % 20;

    time_in_secs = getTimeInMS();

    parameters.snakeState = &state;
    parameters.snakePlayer = &player;
    parameters.snakeFruit = &fruit;
    parameters.snakeGameStatus = &game_status;
    parameters.snakeBoard = &board;
    parameters.snakeRecords = &records;
    parameters.snakeLastetMovedTime = &time_in_secs;
  }
};

TEST_F(ModelTest, EnterTest) {
  controllerSnake(signal_type, &parameters);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_ENTER_BUTTON;
  sleep(1);
  controllerSnake(signal_type, &parameters);
}

TEST_F(ModelTest, ExitTest) {
  controllerSnake(signal_type, &parameters);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_ESCAPE_BUTTON;
  sleep(1);
  controllerSnake(signal_type, &parameters);
  ASSERT_EQ(*parameters.snakeState, S_EXIT_STATE);
}

TEST_F(ModelTest, MoveStraightTest) {
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  sleep(1);
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_NONE;
  controllerSnake(signal_type, &parameters);
  signal_type = S_NONE;

  ASSERT_EQ(*parameters.snakeState, S_GAME_OVER);
}

TEST_F(ModelTest, MoveLeftTest) {
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  sleep(1);
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);

  ASSERT_EQ(*parameters.snakeState, S_GAME_OVER);
}

TEST_F(ModelTest, MoveUpTest) {
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  sleep(1);
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);

  ASSERT_EQ(*parameters.snakeState, S_GAME_OVER);
}

TEST_F(ModelTest, MoveRightTest) {
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  sleep(1);
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  sleep(1);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);

  ASSERT_EQ(*parameters.snakeState, S_GAME_OVER);
}
TEST_F(ModelTest, PauseTest) {
  signal_type = S_ENTER_BUTTON;
  controllerSnake(signal_type, &parameters);
  signal_type = S_PAUSE_BUTTON;
  controllerSnake(signal_type, &parameters);

  ASSERT_EQ(*parameters.snakeState, S_PAUSE);

  signal_type = S_PAUSE_BUTTON;
  controllerSnake(signal_type, &parameters);
  ASSERT_EQ(*parameters.snakeState, S_MOVING);
}

TEST_F(ModelTest, BoardOverlayBlockTest) {
  Player player{};
  Board board{};
  initBoard(&board);
  setPlayerBlockType(&player, BLOCK_O);
  initPlayerPosition(&player);

  movePredictPlayerDown(&player, &board);
  boardOverlayBlock(&player, &board);
  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (player.board.board[i][j].isSet) {
        ASSERT_GE(board.cells[player.y + i][player.x + j].isSet, 0);
      }
    }
  }
}
TEST_F(ModelTest, BoardOverlayBlockOnAnotherBlockTest) {
  Player player{};
  Board board{};
  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_O);
  initPlayerPosition(&player);

  movePredictPlayerDown(&player, &board);
  boardOverlayBlock(&player, &board);

  setPlayerBlockType(&player, BLOCK_O);
  initPlayerPosition(&player);

  movePredictPlayerDown(&player, &board);
  boardOverlayBlock(&player, &board);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (player.board.board[i][j].isSet) {
        ASSERT_GE(board.cells[player.y + i][player.x + j].isSet, 0);
      }
    }
  }
}

TEST_F(ModelTest, updatePredictPlayerTest) {
  Player player{};
  Player predict_player{};
  Board board{};

  initBoard(&board);
  initPlayerPosition(&player);
  setPlayerBlockType(&player, BLOCK_J);
  updatePredictPlayer(&predict_player, player, &board);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      ASSERT_EQ(predict_player.x, player.x);
      ASSERT_GE(predict_player.y, -1);
      ASSERT_GE(player.y, -1);
    }
  }
}

TEST_F(ModelTest, getTimeStepMSTest) {
  GameStatus game_status{};
  game_status.level = 0;
  long long time_step_ms = getTimeStepMS(&game_status);
  ASSERT_EQ(time_step_ms, 1000);
  game_status.level = 1;
  time_step_ms = getTimeStepMS(&game_status);
  ASSERT_EQ(time_step_ms, 875);
  game_status.level = 2;
  time_step_ms = getTimeStepMS(&game_status);
  ASSERT_EQ(time_step_ms, 625);
}

TEST_F(ModelTest, GetRandomBlockTypeTest) {
  BlockType block_type = BLOCK_I;
  block_type = getRandomBlockType();
  ASSERT_GE(block_type, 0);
}

TEST_F(ModelTest, getNextBlockDirectionTest) {
  Direction block_rotation = DIRECTION_1;
  block_rotation = getNextBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_2);
  block_rotation = getNextBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_3);
  block_rotation = getNextBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_4);
}

TEST_F(ModelTest, GetPreviousBlockRotationTest) {
  Direction block_rotation = DIRECTION_1;
  block_rotation = getPreviousBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_4);
  block_rotation = getPreviousBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_3);
  block_rotation = getPreviousBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_2);
  block_rotation = getPreviousBlockDirection(block_rotation);
  ASSERT_EQ(block_rotation, DIRECTION_1);
}

TEST_F(ModelTest, HandleBoardCompleteLinesTest) {
  Board board{};
  board.width = 10;
  board.height = 20;

  for (int i = 0; i < board.width; ++i) {
    board.cells[19][i].isSet = true;
  }
  for (int i = 0; i < board.width; ++i) {
    board.cells[18][i].isSet = true;
  }
  for (int i = 0; i < board.width; i++) {
    board.cells[17][i].isSet = true;
  }
  for (int i = 0; i < board.width; i += 2) {
    board.cells[16][i].isSet = true;
  }
  int complete_lines = handleBoardCompleteLines(&board);
  ASSERT_EQ(complete_lines, 3);
}

TEST_F(ModelTest, CheckCollideTest1) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  bool flag = checkCollide(&player, &board);
  ASSERT_EQ(flag, false);
}

TEST_F(ModelTest, CheckFutureCollideWithBlocksLeftTest1) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  bool flag = checkFutureCollideWithBlocksLeft(&player, &board);
  ASSERT_EQ(flag, false);
}

TEST_F(ModelTest, CheckFutureCollideWithBlocksRightTest1) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);
  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  bool flag = checkFutureCollideWithBlocksRight(&player, &board);
  ASSERT_EQ(flag, false);
}

TEST_F(ModelTest, CheckFutureCollideWithBlocksLeftTest2) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);
  for (int i = 0; i < board.height; ++i) {
    board.cells[i][0].isSet = true;
  }

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);

  movePlayerLeft(&player);
  movePlayerLeft(&player);
  movePlayerLeft(&player);
  bool flag = checkFutureCollideWithBlocksLeft(&player, &board);
  ASSERT_EQ(flag, true);
}
TEST_F(ModelTest, CheckFutureCollideWithBlocksRightTest2) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);
  for (int i = 0; i < board.height; ++i) {
    board.cells[i][board.width - 1].isSet = true;
  }

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);

  movePlayerRight(&player);
  movePlayerRight(&player);
  bool flag = checkFutureCollideWithBlocksRight(&player, &board);
  ASSERT_EQ(flag, true);
}

TEST_F(ModelTest, CheckFutureCollideWithLeftTest) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  movePlayerLeft(&player);
  movePlayerLeft(&player);
  movePlayerLeft(&player);
  movePlayerLeft(&player);

  bool flag = checkFutureCollideWithLeft(&player, &board);
  ASSERT_EQ(flag, true);
}

TEST_F(ModelTest, CheckFutureCollideWithRightTest) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  movePlayerRight(&player);
  movePlayerRight(&player);
  movePlayerRight(&player);

  bool flag = checkFutureCollideWithRight(&player, &board);
  ASSERT_EQ(flag, true);
}

TEST_F(ModelTest, CheckFutureCollideWithUpTest) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  movePlayerRight(&player);
  movePlayerRight(&player);
  movePlayerRight(&player);

  bool flag = checkFutureCollideWithUp(&player, &board);
  ASSERT_EQ(flag, false);
}

TEST_F(ModelTest, CheckFutureCollideWithDownTest) {
  Player player{};
  Board board{};
  initPlayer(&player);
  initPlayerPosition(&player);

  initBoard(&board);

  setPlayerBlockType(&player, BLOCK_T);
  setPlayerBlockDirection(&player, DIRECTION_1);
  movePlayerRight(&player);
  movePlayerRight(&player);
  movePlayerRight(&player);

  bool flag = checkFutureCollideWithDown(&player, &board);
  ASSERT_EQ(flag, false);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  flag = checkFutureCollideWithDown(&player, &board);
  ASSERT_EQ(flag, false);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  flag = checkFutureCollideWithDown(&player, &board);
  ASSERT_EQ(flag, false);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  flag = checkFutureCollideWithDown(&player, &board);
  ASSERT_EQ(flag, false);
  movePlayerDown(&player);
  movePlayerDown(&player);
  movePlayerDown(&player);
  flag = checkFutureCollideWithDown(&player, &board);
  ASSERT_EQ(flag, true);
}

TEST_F(ModelTest, initGameStatusTest) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
}

TEST_F(ModelTest, addScoreGameStatusTest1) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 100);
  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 200);
  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 300);
  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 400);
  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 500);
}

TEST_F(ModelTest, addScoreGameStatusTest2) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 100);
  addScoreGameStatus(&game_status, 2);
  ASSERT_EQ(game_status.score, 400);
  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 500);
  addScoreGameStatus(&game_status, 2);
  ASSERT_EQ(game_status.score, 800);
  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 900);
}

TEST_F(ModelTest, addScoreGameStatusTest3) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 1);
  ASSERT_EQ(game_status.score, 100);
  addScoreGameStatus(&game_status, 2);
  ASSERT_EQ(game_status.score, 400);
  addScoreGameStatus(&game_status, 3);
  ASSERT_EQ(game_status.score, 1100);
  addScoreGameStatus(&game_status, 4);
  ASSERT_EQ(game_status.score, 2600);
  addScoreGameStatus(&game_status, 5);
  ASSERT_EQ(game_status.score, 4100);
}
TEST_F(ModelTest, addScoreGameStatusupdateGameStatusLevelTest1) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 1);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 100);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 2);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 400);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 1);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 500);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 2);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 800);
  ASSERT_EQ(game_status.level, 1);
  addScoreGameStatus(&game_status, 1);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 900);
  ASSERT_EQ(game_status.level, 1);
}

TEST_F(ModelTest, addScoreGameStatusupdateGameStatusLevelTest2) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 1);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 100);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 2);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 400);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 3);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 1100);
  ASSERT_EQ(game_status.level, 1);
  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 2600);
  ASSERT_EQ(game_status.level, 4);
  addScoreGameStatus(&game_status, 5);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 4100);
  ASSERT_EQ(game_status.level, 6);
}

TEST_F(ModelTest, addScoreGameStatusNoChangesTest) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 0);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 0);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 0);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, 0);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
}

TEST_F(ModelTest, addScoreGameStatusInvalidArgumentTest) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, -1);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
  addScoreGameStatus(&game_status, -100);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);
}

TEST_F(ModelTest, addScoreGameStatusupdateGameStatusLevelMaxLevelExceedTest) {
  GameStatus game_status{};
  initGameStatus(&game_status);
  ASSERT_EQ(game_status.score, 0);
  ASSERT_EQ(game_status.level, 0);

  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 1500);
  ASSERT_EQ(game_status.level, 2);

  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 3000);
  ASSERT_EQ(game_status.level, 5);

  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 4500);
  ASSERT_EQ(game_status.level, 7);

  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 6000);
  ASSERT_EQ(game_status.level, 10);

  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 7500);
  ASSERT_EQ(game_status.level, 10);

  addScoreGameStatus(&game_status, 4);
  updateGameStatusLevel(&game_status);
  ASSERT_EQ(game_status.score, 9000);
  ASSERT_EQ(game_status.level, 10);
}

TEST_F(ModelTest, setPlayerBoardBlockTestIFirstRotation) {
  PlayerBoard player_board{};
  setPlayerBoardBlock(&player_board, BLOCK_I, DIRECTION_1);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (j == 1) {
        ASSERT_EQ(player_board.board[i][j].isSet, true);
      } else {
        ASSERT_EQ(player_board.board[i][j].isSet, false);
      }
    }
  }
}

TEST_F(ModelTest, setPlayerBoardBlockTestISecondRotation) {
  PlayerBoard player_board{};
  setPlayerBoardBlock(&player_board, BLOCK_I, DIRECTION_2);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (i == 2) {
        ASSERT_EQ(player_board.board[i][j].isSet, true);
      } else {
        ASSERT_EQ(player_board.board[i][j].isSet, false);
      }
    }
  }
}

TEST_F(ModelTest, setPlayerBoardBlockTestIThirdRotation) {
  PlayerBoard player_board{};
  setPlayerBoardBlock(&player_board, BLOCK_I, DIRECTION_3);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (j == 1) {
        ASSERT_EQ(player_board.board[i][j].isSet, true);
      } else {
        ASSERT_EQ(player_board.board[i][j].isSet, false);
      }
    }
  }
}

TEST_F(ModelTest, setPlayerBoardBlockTestIForthRotation) {
  PlayerBoard player_board{};
  setPlayerBoardBlock(&player_board, BLOCK_I, DIRECTION_4);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      if (i == 2) {
        ASSERT_EQ(player_board.board[i][j].isSet, true);
      } else {
        ASSERT_EQ(player_board.board[i][j].isSet, false);
      }
    }
  }
}

TEST_F(ModelTest, initPlayerBoardTest) {
  PlayerBoard player_board{};
  initPlayerBoard(&player_board);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      ASSERT_EQ(player_board.board[i][j].color, COLOR_BLACK);
      ASSERT_EQ(player_board.board[i][j].isSet, false);
    }
  }
}
TEST_F(ModelTest, CopyPlayerBoardTest) {
  PlayerBoard player_board_1{};
  PlayerBoard player_board_2{};
  initPlayerBoard(&player_board_1);
  initPlayerBoard(&player_board_2);

  for (int i = 0; i < PLAYER_BOARD_SIZE; i += 2) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; j += 2) {
      player_board_1.board[i][j].isSet = true;
    }
  }
  copyPlayerBoard(&player_board_2, player_board_1);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      ASSERT_EQ(player_board_1.board[i][j].isSet,
                player_board_2.board[i][j].isSet);
      ASSERT_EQ(player_board_1.board[i][j].color,
                player_board_2.board[i][j].color);
    }
  }
}

TEST_F(ModelTest, initPlayerTest) {
  Player player{};
  initPlayer(&player);
  ASSERT_EQ(player.x, 0);
  ASSERT_EQ(player.y, 0);
  ASSERT_GE(player.blockType, 0);
  ASSERT_GE(player.direction, 0);
}
TEST_F(ModelTest, InitNextPlayerTest) {
  Player player{};
  initNextPlayer(&player);
  ASSERT_EQ(player.x, INIT_NEXT_PLAYER_POS_X);
  ASSERT_EQ(player.y, INIT_NEXT_PLAYER_POS_Y);
  ASSERT_GE(player.blockType, 0);
  ASSERT_GE(player.direction, 0);
}
TEST_F(ModelTest, initPlayerPositionTest) {
  Player player{};
  initPlayerPosition(&player);
  ASSERT_EQ(player.x, INIT_PLAYER_POS_X);
  ASSERT_EQ(player.y, INIT_PLAYER_POS_Y);
  ASSERT_GE(player.blockType, 0);
  ASSERT_GE(player.direction, 0);
}
TEST_F(ModelTest, CopyPlayerTest) {
  Player player{};
  initNextPlayer(&player);
  Player player_2{};
  copyPlayer(&player_2, player);

  ASSERT_EQ(player_2.x, player.x);
  ASSERT_EQ(player_2.y, player.y);
  ASSERT_EQ(player_2.blockType, player.blockType);
  ASSERT_EQ(player_2.direction, player.direction);
  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      ASSERT_EQ(player.board.board[i][j].color, player.board.board[i][j].color);
      ASSERT_EQ(player.board.board[i][j].isSet, player.board.board[i][j].isSet);
    }
  }
}
TEST_F(ModelTest, setPlayerBlockDirectionTest) {
  Player player{};
  initPlayer(&player);
  setPlayerBlockDirection(&player, DIRECTION_3);
  ASSERT_EQ(player.direction, DIRECTION_3);
}
TEST_F(ModelTest, SetPlayerNextBlockRotationTest) {
  Player player{};
  initPlayer(&player);
  setPlayerBlockDirection(&player, DIRECTION_1);
  setPlayerNextBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_2);
  setPlayerNextBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_3);
  setPlayerNextBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_4);
  setPlayerNextBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_1);
}
TEST_F(ModelTest, SetPlayerPreviousBlockRotationTest) {
  Player player{};
  initPlayer(&player);
  setPlayerBlockDirection(&player, DIRECTION_1);
  setPlayerPreviousBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_4);
  setPlayerPreviousBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_3);
  setPlayerPreviousBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_2);
  setPlayerPreviousBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_1);
  setPlayerPreviousBlockDirection(&player);
  ASSERT_EQ(player.direction, DIRECTION_4);
}
TEST_F(ModelTest, movePlayerRightTest1) {
  Player player{};
  Player player_before{};
  initPlayer(&player);
  initPlayer(&player_before);
  initPlayerPosition(&player);
  initPlayerPosition(&player_before);

  movePlayerRight(&player);

  ASSERT_EQ(player.x, player_before.x + 1);
  ASSERT_EQ(player.y, player_before.y);
}
TEST_F(ModelTest, movePlayerRightTest2) {
  Player player{};
  Player player_before{};
  initPlayer(&player);
  initPlayerPosition(&player);
  copyPlayer(&player_before, player);

  movePlayerRight(&player);
  movePlayerRight(&player);
  movePlayerRight(&player);
  ASSERT_EQ(player.x, player_before.x + 3);
  ASSERT_EQ(player.y, player_before.y);
}
TEST_F(ModelTest, movePlayerLeftRightTest) {
  Player player{};
  Player player_before{};
  initPlayer(&player);
  initPlayerPosition(&player);

  copyPlayer(&player_before, player);

  movePlayerRight(&player);
  movePlayerLeft(&player);

  ASSERT_EQ(player_before.x, player.x);
  ASSERT_EQ(player_before.y, player.y);
  ASSERT_EQ(player_before.blockType, player.blockType);
  ASSERT_EQ(player_before.direction, player.direction);
  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      ASSERT_EQ(player.board.board[i][j].color,
                player_before.board.board[i][j].color);
      ASSERT_EQ(player.board.board[i][j].isSet,
                player_before.board.board[i][j].isSet);
    }
  }
}
TEST_F(ModelTest, MovePlayerUpTest) {
  Player player{};
  Player player_before{};
  initPlayer(&player);
  initPlayer(&player_before);
  copyPlayer(&player_before, player);

  movePlayerUp(&player);

  ASSERT_EQ(player_before.x, player.x);
  ASSERT_EQ(player_before.y, player.y + 1);
  ASSERT_EQ(player_before.blockType, player.blockType);
  ASSERT_EQ(player_before.direction, player.direction);
}
TEST_F(ModelTest, MovePlayerUpDownTest) {
  Player player{};
  Player player_before{};
  initPlayer(&player);
  initPlayerPosition(&player);
  copyPlayer(&player_before, player);

  movePlayerUp(&player);
  movePlayerDown(&player);

  ASSERT_EQ(player_before.x, player.x);
  ASSERT_EQ(player_before.y, player.y);
  ASSERT_EQ(player_before.blockType, player.blockType);
  ASSERT_EQ(player_before.direction, player.direction);

  for (int i = 0; i < PLAYER_BOARD_SIZE; ++i) {
    for (int j = 0; j < PLAYER_BOARD_SIZE; ++j) {
      ASSERT_EQ(player.board.board[i][j].color,
                player_before.board.board[i][j].color);
      ASSERT_EQ(player.board.board[i][j].isSet,
                player_before.board.board[i][j].isSet);
    }
  }
}

TEST_F(ModelTest, RecordsAddSaveLoadTest1) {
  Records records{};
  Records records2{};
  initRecords(&records);
  initRecords(&records2);

  addRecord(&records, "ivettepe1", 500, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe2", 600, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe3", 700, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe4", 800, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe5", 900, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe6", 1000, TETRIS_RECORDS_FILE_NAME);

  saveRecords(&records, TETRIS_RECORDS_FILE_NAME);
  loadRecords(&records2, TETRIS_RECORDS_FILE_NAME);
  for (int i = 0; i < RECORDS_NUMBER; ++i) {
    ASSERT_EQ(records.records[i].isCurrentPlayer,
              records2.records[i].isCurrentPlayer);
    ASSERT_EQ(records.records[i].score, records2.records[i].score);
    ASSERT_STREQ(records.records[i].name, records2.records[i].name);
  }
}

TEST_F(ModelTest, RecordsAddSaveLoadTest2) {
  Records records{};
  Records records2{};
  initRecords(&records);
  initRecords(&records2);

  addRecord(&records, "ivettepe", 500, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe", 600, TETRIS_RECORDS_FILE_NAME);

  saveRecords(&records, TETRIS_RECORDS_FILE_NAME);
  loadRecords(&records2, TETRIS_RECORDS_FILE_NAME);
  for (int i = 0; i < RECORDS_NUMBER; ++i) {
    ASSERT_EQ(records.records[i].isCurrentPlayer,
              records2.records[i].isCurrentPlayer);
    ASSERT_EQ(records.records[i].score, records2.records[i].score);
    ASSERT_STREQ(records.records[i].name, records2.records[i].name);
  }
}

TEST_F(ModelTest, RecordsAddSaveLoadTest3) {
  Records records{};
  Records records2{};
  initRecords(&records);
  initRecords(&records2);

  addRecord(&records, "ivettepe", 500, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe", 600, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe", 500, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe", 600, TETRIS_RECORDS_FILE_NAME);
  removeRecord(&records, "ivettepe", TETRIS_RECORDS_FILE_NAME);

  for (int i = 0; i < RECORDS_NUMBER; ++i) {
    ASSERT_EQ(records.records[i].score, 0);
    ASSERT_EQ(records.records[i].isCurrentPlayer, false);
    ASSERT_STREQ(records.records[i].name, "");
  }
}
TEST_F(ModelTest, RecordsAddSaveLoadTest4) {
  Records records{};
  Records records2{};
  initRecords(&records);
  initRecords(&records2);

  addRecord(&records, "ivettepe8", 1200, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe7", 1100, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe6", 1000, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe5", 900, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe4", 800, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe3", 700, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe2", 600, TETRIS_RECORDS_FILE_NAME);
  addRecord(&records, "ivettepe1", 500, TETRIS_RECORDS_FILE_NAME);

  ASSERT_EQ(records.records[0].score, 1200);
  ASSERT_STREQ(records.records[0].name, "ivettepe8");
}

TEST_F(ModelTest, EatFruitTest) {
  signal_type = S_ENTER_BUTTON;

  controllerSnake(signal_type, &parameters);

  signal_type = S_MOVE_DOWN;
  controllerSnake(signal_type, &parameters);

  parameters.snakeFruit->x = (parameters.snakePlayer->snakeBody[0].x);
  parameters.snakeFruit->y = (parameters.snakePlayer->snakeBody[0].y + 1);

  for (int i = 0; i < 25; ++i) {
    signal_type = S_MOVE_DOWN;
    controllerSnake(signal_type, &parameters);
  }

  ASSERT_EQ(*parameters.snakeState, S_GAME_OVER);
}

TEST_F(ModelTest, CollideWithItself) {
  signal_type = S_ENTER_BUTTON;

  controllerSnake(signal_type, &parameters);
  parameters.snakePlayer->snakeLength = 10;

  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_DOWN;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_LEFT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_UP;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_RIGHT;
  controllerSnake(signal_type, &parameters);
  signal_type = S_MOVE_DOWN;
  controllerSnake(signal_type, &parameters);

  ASSERT_EQ(*parameters.snakeState, S_GAME_OVER);
}

}  // namespace s21