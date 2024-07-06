/**
 * @file frontend.h
 * @brief This file contains the declaration of functions and constants related
 * to the command-line interface (CLI) frontend for games.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_GUI_CLI_FRONTEND_H_
#define CPP3_BRICK_GAME_V_2_0_1_GUI_CLI_FRONTEND_H_

#include "../../brick_game/common/block/block.h"
#include "../../brick_game/common/board/board.h"
#include "../../brick_game/common/cell/cell.h"
#include "../../brick_game/common/common/color_handler.h"
#include "../../brick_game/common/game_status/game_status.h"
#include "../../brick_game/common/parameters/parameters.h"
#include "../../brick_game/common/player/player.h"
#include "../../brick_game/common/time_handler/time_handler.h"

/**
 * @brief Initialize the CLI window with specific time settings.
 */
#define WIN_INIT(time)     \
  {                        \
    initscr();             \
    noecho();              \
    curs_set(0);           \
    keypad(stdscr, TRUE);  \
    timeout(time);         \
    nodelay(stdscr, TRUE); \
    start_color();         \
  }

#define GET_USER_INPUT getch()

#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), __VA_ARGS__)
#define MVADDCH(y, x, c) mvaddch(BOARDS_BEGIN + (y), BOARDS_BEGIN + (x), c)

#define MAX_LENGTH_NAME (10)

typedef enum {
  GAME_STATE_NONE = 0,   /**< No specific game state. */
  GAME_STATE_START = 1,  /**< Start state of the game. */
  GAME_STATE_TETRIS = 2, /**< State indicating the Tetris game. */
  GAME_STATE_SNAKE = 3,  /**< State indicating the Snake game. */
  GAME_STATE_EXIT = 6,   /**< State indicating the exit from the game. */
} GameState;

/**
 * @brief Print the user name prompt on the CLI.
 */
void printUserNamePrompt();

/**
 * @brief Print the Tetris game overlay on the CLI.
 */
void printTetrisOverlay(void);

/**
 * @brief Print the Snake game overlay on the CLI.
 */
void printSnakeOverlay(void);

/**
 * @brief Print the game status for the Snake game on the CLI.
 *
 * @param gameStatus Pointer to the GameStatus object.
 */
void printSnakeGameStatus(GameStatus *gameStatus);

/**
 * @brief Print a rectangle on the CLI with given coordinates.
 *
 * @param topY Y-coordinate of the top edge of the rectangle.
 * @param bottomY Y-coordinate of the bottom edge of the rectangle.
 * @param leftX X-coordinate of the left edge of the rectangle.
 * @param rightX X-coordinate of the right edge of the rectangle.
 */
void printRectangle(int topY, int bottomY, int leftX, int rightX);

/**
 * @brief Print the game status for the Tetris game on the CLI.
 *
 * @param gameStatus Pointer to the GameStatus object.
 */
void printTetrisGameStatus(GameStatus *gameStatus);

/**
 * @brief Print the Tetris game on the CLI based on the game parameters.
 *
 * @param parameters Pointer to the Parameters object.
 */
void printTetrisGame(Parameters *parameters);

/**
 * @brief Print the Snake game on the CLI based on the game parameters.
 *
 * @param parameters Pointer to the Parameters object.
 */
void printSnakeGame(Parameters *parameters);

/**
 * @brief Print the Snake and fruit on the CLI based on the game parameters.
 *
 * @param parameters Pointer to the Parameters object.
 */
void printSnakeAndFruit(Parameters *parameters);

/**
 * @brief Clear the CLI window for the game.
 */
void clearGame();

/**
 * @brief Print a player's block on the CLI based on the player object.
 *
 * @param player Pointer to the Player object.
 */
void printBlock(Player *player);

/**
 * @brief Print the game board on the CLI based on the board object.
 *
 * @param board Pointer to the Board object.
 */
void printBoard(Board *board);

/**
 * @brief Get the player's name input from the CLI and store it in the given
 * parameters.
 *
 * @param parameters Array to store the player's name.
 */
void getPlayerName(char parameters[]);

/**
 * @brief Print the "Game Begin" message on the CLI.
 */
void printBegin();

/**
 * @brief Print the "Game Paused" message on the CLI.
 */
void printPause();

/**
 * @brief Clear the records from the CLI display.
 */
void clearRecords();

/**
 * @brief Print the game records on the CLI based on the shift and given records
 * object.
 *
 * @param shift The shift value for displaying the records.
 * @param records Pointer to the Records object.
 */
void printRecords(int shift, Records *records);

/**
 * @brief Handle the Tetris game loop for the CLI.
 */
void handleTetrisLoop();

/**
 * @brief Handle the Snake game loop for the CLI based on the given parameters.
 *
 * @param parameters Pointer to the Parameters object.
 */
void snakeLoop(Parameters *parameters);

/**
 * @brief Create a menu on the CLI with the given options and size.
 *
 * @param options Array of option strings for the menu.
 * @param size Number of options in the menu.
 * @return The selected index of the menu.
 */
int createMenu(const char *options[], int size);

#endif  // CPP3_BRICK_GAME_V_2_0_1_GUI_CLI_FRONTEND_H_