#include "frontend.h"

#include <ctype.h>
#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../../brick_game/snake/controller/controller.h"
#include "../../brick_game/tetris/fsm/fsm.h"

void printTetrisOverlay(void) {
  printRectangle(0, BOARD_HEIGHT + 1, 0, BOARD_WIDTH + 1);
  printRectangle(0, BOARD_HEIGHT + 1, BOARD_WIDTH + 2,
                 BOARD_WIDTH + HUD_WIDTH + 3);

  printRectangle(1, 6, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);

  printRectangle(7, 9, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);
  printRectangle(10, 12, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);

  MVPRINTW(1, BOARD_WIDTH + 5, "Next");
  MVPRINTW(7, BOARD_WIDTH + 5, "Score");
  MVPRINTW(10, BOARD_WIDTH + 5, "Level");
}
void printSnakeOverlay(void) {
  printRectangle(0, BOARD_HEIGHT + 1, 0, BOARD_WIDTH + 1);
  printRectangle(0, BOARD_HEIGHT + 1, BOARD_WIDTH + 2,
                 BOARD_WIDTH + HUD_WIDTH + 3);

  printRectangle(1, 3, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);
  printRectangle(4, 6, BOARD_WIDTH + 3, BOARD_WIDTH + HUD_WIDTH + 2);

  MVPRINTW(1, BOARD_WIDTH + 5, "Score");
  MVPRINTW(4, BOARD_WIDTH + 5, "Level");
}

void printUserNamePrompt() {
  printRectangle(BOARD_HEIGHT / 2 - 5, BOARD_HEIGHT / 2 + 5, BOARDS_BEGIN,
                 BOARDS_BEGIN + BOARD_WIDTH * 2);
  for (int i = BOARD_HEIGHT / 2 - 5 + 1; i < BOARD_HEIGHT / 2 - 5 + 1 + 9;
       ++i) {
    for (int j = BOARDS_BEGIN + 1; j < BOARDS_BEGIN + 1 + 19; ++j) {
      MVPRINTW(i, j, " ");
    }
  }

  MVPRINTW(7, 5, "Enter your name:");
}

void printRectangle(int topY, int bottomY, int leftX, int rightX) {
  MVADDCH(topY, leftX, ACS_ULCORNER);

  int i = leftX + 1;

  for (; i < rightX; i++) MVADDCH(topY, i, ACS_HLINE);
  MVADDCH(topY, i, ACS_URCORNER);

  for (int i_2 = topY + 1; i_2 < bottomY; i_2++) {
    MVADDCH(i_2, leftX, ACS_VLINE);
    MVADDCH(i_2, rightX, ACS_VLINE);
  }

  MVADDCH(bottomY, leftX, ACS_LLCORNER);
  i = leftX + 1;
  for (; i < rightX; i++) MVADDCH(bottomY, i, ACS_HLINE);
  MVADDCH(bottomY, i, ACS_LRCORNER);
}

void printTetrisGameStatus(GameStatus *gameStatus) {
  MVPRINTW(8, BOARD_WIDTH + 5, "%7d", gameStatus->score);
  MVPRINTW(11, BOARD_WIDTH + 5, "%7d", gameStatus->level);
}
void printSnakeGameStatus(GameStatus *gameStatus) {
  MVPRINTW(2, BOARD_WIDTH + 5, "%7d", gameStatus->score);
  MVPRINTW(5, BOARD_WIDTH + 5, "%7d", gameStatus->level);
}

void clearGame() {
  for (int rowIndex = 0; rowIndex < 24; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < 28; ++columnIndex) {
      attron(COLOR_PAIR(INIT_COLOR_PAIR));
      mvprintw(rowIndex + 1, columnIndex + 1, " ");
      attroff(COLOR_PAIR(INIT_COLOR_PAIR));
    }
  }
}

void printTetrisGame(Parameters *parameters) {
  clearGame();
  printTetrisOverlay();
  printBoard(parameters->tetrisBoard);
  printTetrisGameStatus(parameters->tetrisGameStatus);
  printRecords(13, parameters->tetrisRecords);
  printBlock(parameters->tetrisPredictPlayer);
  printBlock(parameters->tetrisPlayer);
  printBlock(parameters->tetrisNextetPlayer);
}

void printSnakeGame(Parameters *parameters) {
  clearGame();
  printSnakeOverlay();
  printRecords(7, parameters->snakeRecords);
  printSnakeGameStatus(parameters->snakeGameStatus);
  printSnakeAndFruit(parameters);
}

void printSnakeAndFruit(Parameters *parameters) {
  for (int y = 0; y < parameters->snakeBoard->height; ++y) {
    for (int x = 0; x < parameters->snakeBoard->width; ++x) {
      bool isSnakeBody = false;
      for (int i = 0; i < parameters->snakePlayer->snakeLength; ++i) {
        if (parameters->snakePlayer->snakeBody[i].x == x &&
            parameters->snakePlayer->snakeBody[i].y == y) {
          attron(COLOR_PAIR(GREEN_COLOR_PAIR_INDEX));
          mvprintw(y + BOARDS_BEGIN + 1, x + BOARDS_BEGIN + 1, "S");
          attroff(COLOR_PAIR(GREEN_COLOR_PAIR_INDEX));

          isSnakeBody = true;
          break;
        }
      }
      if (!isSnakeBody && x == parameters->snakeFruit->x &&
          y == parameters->snakeFruit->y) {
        attron(COLOR_PAIR(RED_COLOR_PAIR_INDEX));
        mvprintw(y + BOARDS_BEGIN + 1, x + BOARDS_BEGIN + 1, "*");
        attroff(COLOR_PAIR(RED_COLOR_PAIR_INDEX));
      }
      if (isSnakeBody && x == parameters->snakeFruit->x &&
          y == parameters->snakeFruit->y) {
        attron(COLOR_PAIR(PREDICT_COLOR_PAIR_INDEX));
        mvprintw(y + BOARDS_BEGIN + 1, x + BOARDS_BEGIN + 1, "*");
        attroff(COLOR_PAIR(PREDICT_COLOR_PAIR_INDEX));
      }
    }
  }
}

void printBoard(Board *board) {
  for (int rowIndex = 0; rowIndex < 20; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < 10; ++columnIndex) {
      if (board->cells[rowIndex][columnIndex].isSet) {
        int color = board->cells[rowIndex][columnIndex].color;
        attron(COLOR_PAIR(BLOCK_COLOR_PAIRS_ARRAY[color]));
        mvprintw(rowIndex + BOARDS_BEGIN + 1, columnIndex + BOARDS_BEGIN + 1,
                 "S");
        attroff(COLOR_PAIR(BLOCK_COLOR_PAIRS_ARRAY[color]));
      } else {
        attron(COLOR_PAIR(INIT_COLOR_PAIR));
        mvprintw(rowIndex + BOARDS_BEGIN + 1, columnIndex + BOARDS_BEGIN + 1,
                 " ");
        attroff(COLOR_PAIR(INIT_COLOR_PAIR));
      }
    }
  }
}

void printBlock(Player *player) {
  int playerPosX = player->x;
  int playerPosY = player->y;
  PlayerBoard playerBoard = player->board;

  for (int rowIndex = 0; rowIndex < PLAYER_BOARD_SIZE; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < PLAYER_BOARD_SIZE; ++columnIndex) {
      int printY = playerPosY + BOARDS_BEGIN + 1 + rowIndex;
      int printX = playerPosX + BOARDS_BEGIN + 1 + columnIndex;
      if (playerBoard.board[rowIndex][columnIndex].isSet) {
        int color = playerBoard.board[rowIndex][columnIndex].color;
        attron(COLOR_PAIR(BLOCK_COLOR_PAIRS_ARRAY[color]));
        mvprintw(printY, printX, "F");
        attroff(COLOR_PAIR(BLOCK_COLOR_PAIRS_ARRAY[color]));
      }
    }
  }
}

void getPlayerName(char str[]) {
  printUserNamePrompt();
  int ch;
  int i = 0;

  flushinp();

  refresh();
  while ((ch = getch()) != '\n') {
    if (ch == ERR) {
      continue;
    } else if (ch == KEY_BACKSPACE || ch == DELETE) {
      if (i > 0) {
        i--;
        str[i] = '\0';
        mvprintw(12, 6, "%*s", MAX_LENGTH_NAME + 8, " ");
        mvprintw(12, 6, "%s", str);
        move(MAX_LENGTH_NAME, 6 + i);
        refresh();
      }
    } else if (i < MAX_LENGTH_NAME - 1 && isprint(ch)) {
      str[i++] = ch;
      str[i] = '\0';
      mvprintw(12, 6, "%s", str);
      refresh();
    }
  }
  getch();
}

void printBegin() {
  clearGame();

  printRectangle(0, BOARDS_BEGIN + BOARD_HEIGHT - 1, 0,
                 BOARDS_BEGIN + BOARD_WIDTH + HUD_WIDTH + 1);
  mvprintw(11, 6, "Press Enter to play");

  mvprintw(13, 6, "Press Esc to choose");
  mvprintw(14, 10, "another game");
}

void printPause() {
  printRectangle(0 + 8, BOARDS_BEGIN + BOARD_HEIGHT - 1 - 8, 0 + 4,
                 BOARDS_BEGIN + BOARD_WIDTH + HUD_WIDTH + 1 - 4);
  for (int i = 11; i < 15; ++i) {
    for (int j = 7; j < 23; ++j) {
      mvprintw(i, j, " ");
    }
  }
  mvprintw(12, 8, "Game is paused");
}

void clearRecords() {}

void printRecords(int shift, Records *records) {
  clearRecords();
  printRectangle(shift, 20, 13, 24);
  mvprintw(shift + 2, 16, "Records");

  attron(COLOR_PAIR(RECORD_1_COLOR_PAIR_INDEX));
  mvprintw(shift + 3, 16, "1. %7d", records->records[0].score);
  attron(COLOR_PAIR(RECORD_1_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(RECORD_2_COLOR_PAIR_INDEX));
  mvprintw(shift + 4, 16, "2. %7d", records->records[1].score);
  attroff(COLOR_PAIR(RECORD_2_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(RECORD_3_COLOR_PAIR_INDEX));
  mvprintw(shift + 5, 16, "3. %7d", records->records[2].score);
  attroff(COLOR_PAIR(RECORD_3_COLOR_PAIR_INDEX));

  attron(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
  mvprintw(shift + 6, 16, "4. %7d", records->records[3].score);
  attroff(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
  attron(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
  mvprintw(shift + 7, 16, "5. %7d", records->records[4].score);
  attroff(COLOR_PAIR(RECORD_4_5_COLOR_PAIR_INDEX));
}

void snakeLoop(Parameters *parameters) {
  int userInput = 0;
  bool keyHeld = false;
  bool breakFlag = false;

  while (!breakFlag) {
    if (*parameters->snakeState == S_EXIT_STATE) {
      breakFlag = TRUE;
    }

    SignalType signal = getSignal(userInput, 0, &keyHeld);
    controllerSnake(signal, parameters);
    if (*parameters->snakeState != S_START &&
        *parameters->snakeState != S_PAUSE) {
      printSnakeGame(parameters);
    }
    if (*parameters->snakeState == S_PAUSE) {
      printPause();
    } else if (*parameters->snakeState == S_GAME_OVER) {
      getPlayerName(parameters->snakeUsername);
      printBegin();
      removeRecord(parameters->snakeRecords, "Unnamed",
                   SNAKE_RECORDS_FILE_NAME);
      addRecord(parameters->snakeRecords, parameters->snakeUsername,
                parameters->snakeGameStatus->score, SNAKE_RECORDS_FILE_NAME);

      *parameters->snakeState = S_START;
    }
    userInput = GET_USER_INPUT;
  }
}

void handleSnakeLoop() {
  Board board = {0};
  initBoard(&board);

  GameStatus gameStatus = {0};
  initGameStatus(&gameStatus);

  Player player = {0};
  initPlayer(&player);
  setPlayerPosition(&player, 10, 10);

  player.snakeLength = 4;
  player.direction = DIRECTION_1;
  player.snakeBody[0].x = 10 / 2;
  player.snakeBody[0].y = 20 / 2;

  State state = S_START;
  Records records = {0};

  Cell fruit = {0};
  initCell(&fruit);
  fruit.y = rand() % 10;
  fruit.x = rand() % 20;

  long long timeInSecs;
  timeInSecs = getTimeInMS();

  Parameters parameters = {0};

  parameters.snakeState = &state;
  parameters.snakePlayer = &player;
  parameters.snakeFruit = &fruit;
  parameters.snakeGameStatus = &gameStatus;
  parameters.snakeBoard = &board;
  parameters.snakeRecords = &records;
  parameters.snakeLastetMovedTime = &timeInSecs;
  loadRecords(parameters.snakeRecords, SNAKE_RECORDS_FILE_NAME);
  saveRecords(parameters.snakeRecords, SNAKE_RECORDS_FILE_NAME);

  initGameColors();
  printBegin();

  snakeLoop(&parameters);
}

void tetrisLoop(Parameters *parameters) {
  int userInput = 0;
  bool keyHeld = false;
  bool breakFlag = false;

  while (!breakFlag) {
    if (*parameters->tetrisState == S_EXIT_STATE) {
      breakFlag = TRUE;
    }

    SignalType signal = getSignal(userInput, 0, &keyHeld);
    signalAction(signal, parameters);
    if (*parameters->tetrisState != S_START &&
        *parameters->tetrisState != S_PAUSE) {
      printTetrisGame(parameters);
    }
    if (*parameters->tetrisState == S_PAUSE) {
      printPause();
    }
    if (*parameters->tetrisState == S_GAME_OVER) {
      getPlayerName(parameters->tetrisUsername);
      printBegin();
      removeRecord(parameters->tetrisRecords, "Unnamed",
                   TETRIS_RECORDS_FILE_NAME);
      addRecord(parameters->tetrisRecords, parameters->tetrisUsername,
                parameters->tetrisGameStatus->score, TETRIS_RECORDS_FILE_NAME);
    }

    userInput = GET_USER_INPUT;
  }
}

void handleTetrisLoop() {
  Board board = {0};
  GameStatus gameStatus = {0};
  Player player = {0};
  Player nextPlayer = {0};
  Player predictPlayer = {0};
  State state = S_START;
  Records records = {0};
  Parameters parameters = {0};
  long long timeInSecs;

  initPlayer(&player);
  initNextPlayer(&nextPlayer);
  initBoard(&board);
  initGameStatus(&gameStatus);
  timeInSecs = getTimeInMS();

  parameters.tetrisGameStatus = &gameStatus;
  parameters.tetrisState = &state;
  parameters.tetrisBoard = &board;
  parameters.tetrisPlayer = &player;
  parameters.tetrisNextetPlayer = &nextPlayer;
  parameters.tetrisPredictPlayer = &predictPlayer;
  parameters.tetrisLastetMovedTime = &timeInSecs;
  parameters.tetrisRecords = &records;

  loadRecords(parameters.tetrisRecords, TETRIS_RECORDS_FILE_NAME);
  saveRecords(parameters.tetrisRecords, TETRIS_RECORDS_FILE_NAME);

  initGameColors();
  printBegin();
  tetrisLoop(&parameters);
}

int main(void) {
  WIN_INIT(50);

  setlocale(LC_ALL, "");
  srand(time(NULL));

  GameState state = GAME_STATE_NONE;

  const char *options[] = {"Tetris", "Snake", "Exit"};
  int size = sizeof(options) / sizeof(options[0]);

  int choice;

  while (state != GAME_STATE_EXIT) {
    choice = createMenu(options, size);
    if (choice == 0) {
      state = GAME_STATE_TETRIS;
    } else if (choice == 1) {
      state = GAME_STATE_SNAKE;
    } else {
      state = GAME_STATE_EXIT;
    }

    if (state == GAME_STATE_TETRIS) {
      handleTetrisLoop();
    } else if (state == GAME_STATE_SNAKE) {
      handleSnakeLoop();
    }
  }

  endwin();

  return 0;
}

int createMenu(const char *options[], int size) {
  int highlight = 0;
  int choice = -1;
  int key;

  while (1) {
    clear();

    for (int i = 0; i < size; i++) {
      if (i == highlight) {
        attron(A_REVERSE);
      }
      mvprintw(i + 1, 1, "%s", options[i]);
      attroff(A_REVERSE);
    }

    key = getch();

    switch (key) {
      case KEY_UP:
        highlight = (highlight - 1 + size) % size;
        break;
      case KEY_DOWN:
        highlight = (highlight + 1) % size;
        break;
      case 10:
        choice = highlight;
        break;
    }
    if (choice != -1) {
      break;
    }
  }
  return choice;
}
