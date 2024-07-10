#include <time.h>

#include "fsm.h"

action_callback fsmTable[7][8] = {
    {NULL, NULL, NULL, NULL, NULL, actionExitState, actionSpawn, NULL},
    {actionSpawn, actionSpawn, actionSpawn, actionSpawn, actionSpawn,
     actionSpawn, actionSpawn, NULL},
    {NULL, actionMoveUp, actionMoveDown, actionMoveLeft, actionMoveRight,
     actionExitState, NULL, actionPause},
    {actionCollide, actionCollide, actionCollide, actionCollide, actionCollide,
     actionCollide, actionCollide, actionCollide},
    {actionGameOver, actionGameOver, actionGameOver, actionGameOver,
     actionGameOver, actionGameOver, actionSpawn, actionCollide},
    {actionExitState, actionExitState, actionExitState, actionExitState,
     actionExitState, actionExitState, actionExitState, actionExitState},
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, actionPause},
};

void signalAction(SignalType signal, Parameters *parameters) {
  action_callback act = fsmTable[*parameters->tetrisState][signal];

  if (act) {
    act(parameters);
  }

  long long timeInMs = getTimeInMS();

  if (*parameters->tetrisState == S_MOVING) {
    long long timeStep = getTimeStepMS(parameters->tetrisGameStatus);
    if (timeInMs - *parameters->tetrisLastetMovedTime > timeStep) {
      *parameters->tetrisLastetMovedTime = timeInMs;
      actionMoveDown(parameters);
    }
  }
}

SignalType getSignal(int userInput, bool hold, bool *keyHeld) {
  SignalType signal = S_NONE;
  if (hold) {
    *keyHeld = true;
  } else {
    if (userInput == KEY_UP) {
      signal = S_MOVE_UP;
    } else if (userInput == KEY_DOWN) {
      signal = S_MOVE_DOWN;
    } else if (userInput == KEY_LEFT) {
      signal = S_MOVE_LEFT;
    } else if (userInput == KEY_RIGHT) {
      signal = S_MOVE_RIGHT;
    } else if (userInput == ESCAPE) {
      signal = S_ESCAPE_BUTTON;
    } else if (userInput == ENTER_KEY) {
      signal = S_ENTER_BUTTON;
    } else if (userInput == PAUSE_KEY) {
      signal = S_PAUSE_BUTTON;
    }
    *keyHeld = false;
  }

  return signal;
}

bool checkCollisions(Parameters *parameters) {
  bool flag = false;

  if (checkFutureCollideWithDown(parameters->tetrisPlayer,
                                 parameters->tetrisBoard)) {
    *parameters->tetrisState = S_COLLIDE;
    flag = true;
  } else if (checkCollideWithBlocks(parameters->tetrisPlayer,
                                    parameters->tetrisBoard)) {
    *parameters->tetrisState = S_COLLIDE;
    flag = true;
  }
  return flag;
}

void actionSpawn(Parameters *parameters) {
  initPlayer(parameters->tetrisPlayer);
  initPlayerPosition(parameters->tetrisPlayer);

  BlockType nextBlockType = parameters->tetrisNextetPlayer->blockType;
  setPlayerBlockType(parameters->tetrisPlayer, nextBlockType);
  if (checkCollisions(parameters)) {
    *parameters->tetrisState = S_GAME_OVER;
  } else {
    updatePredictPlayer(parameters->tetrisPredictPlayer,
                        *parameters->tetrisPlayer, parameters->tetrisBoard);

    setPlayerBlockType(parameters->tetrisNextetPlayer, getRandomBlockType());

    *parameters->tetrisState = S_MOVING;
  }
}

void actionMoveUp(Parameters *parameters) {
  setPlayerNextBlockDirection(parameters->tetrisPlayer);
  if (checkCollide(parameters->tetrisPlayer, parameters->tetrisBoard)) {
    setPlayerPreviousBlockDirection(parameters->tetrisPlayer);
  }
  updatePredictPlayer(parameters->tetrisPredictPlayer,
                      *parameters->tetrisPlayer, parameters->tetrisBoard);
  checkCollisions(parameters);
}

void actionMoveDown(Parameters *parameters) {
  movePlayerDown(parameters->tetrisPlayer);

  checkCollisions(parameters);
}

void actionMoveLeft(Parameters *parameters) {
  bool flagOk = !checkFutureCollideWithLeft(parameters->tetrisPlayer,
                                            parameters->tetrisBoard);
  flagOk &= !checkFutureCollideWithBlocksLeft(parameters->tetrisPlayer,
                                              parameters->tetrisBoard);
  if (flagOk) {
    movePlayerLeft(parameters->tetrisPlayer);
  }
  updatePredictPlayer(parameters->tetrisPredictPlayer,
                      *parameters->tetrisPlayer, parameters->tetrisBoard);
  checkCollisions(parameters);
}

void actionMoveRight(Parameters *parameters) {
  bool flagOk = !checkFutureCollideWithRight(parameters->tetrisPlayer,
                                             parameters->tetrisBoard);
  flagOk &= !checkFutureCollideWithBlocksRight(parameters->tetrisPlayer,
                                               parameters->tetrisBoard);
  if (flagOk) {
    movePlayerRight(parameters->tetrisPlayer);
  }
  updatePredictPlayer(parameters->tetrisPredictPlayer,
                      *parameters->tetrisPlayer, parameters->tetrisBoard);
  checkCollisions(parameters);
}

void actionCollide(Parameters *parameters) {
  boardOverlayBlock(parameters->tetrisPlayer, parameters->tetrisBoard);

  *parameters->tetrisState = S_SPAWN;

  int completeLinesCount = handleBoardCompleteLines(parameters->tetrisBoard);

  if (completeLinesCount > 0) {
    addScoreGameStatus(parameters->tetrisGameStatus, completeLinesCount);
    updateGameStatusLevel(parameters->tetrisGameStatus);
    addRecord(parameters->tetrisRecords, "Unnamed",
              parameters->tetrisGameStatus->score, TETRIS_RECORDS_FILE_NAME);
  }
}

void actionGameOver(Parameters *parameters) {
  char name[14] = {0};

  removeRecord(parameters->tetrisRecords, "Unnamed", TETRIS_RECORDS_FILE_NAME);
  addRecord(parameters->tetrisRecords, name,
            parameters->tetrisGameStatus->score, TETRIS_RECORDS_FILE_NAME);

  initBoard(parameters->tetrisBoard);
  initGameStatus(parameters->tetrisGameStatus);
  *parameters->tetrisState = S_START;
}

void actionExitState(Parameters *parameters) {
  saveRecords(parameters->tetrisRecords, TETRIS_RECORDS_FILE_NAME);
  *parameters->tetrisState = S_EXIT_STATE;
}
void actionPause(Parameters *parameters) {
  if (*parameters->tetrisState != S_PAUSE) {
    *parameters->tetrisState = S_PAUSE;
  } else {
    *parameters->tetrisState = S_MOVING;
  }
}