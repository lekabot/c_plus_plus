/**
 * @file common_colors.h
 * @brief This file contains color definitions for the brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_COMMON_COLORS_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_COMMON_COLORS_H_

#ifndef COLOR_BLACK
#define COLOR_BLACK (0)
#endif  // COLOR_BLACK

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enumeration of block color types.
 */
typedef enum {
  BLOCK_COLOR_I = 0,
  BLOCK_COLOR_J = 1,
  BLOCK_COLOR_L = 2,
  BLOCK_COLOR_O = 3,
  BLOCK_COLOR_S = 4,
  BLOCK_COLOR_T = 5,
  BLOCK_COLOR_Z = 6,
  BLOCK_COLOR_PREDICT = 7,
} BlockColorType;

/**
 * @brief Array of block colors corresponding to block types.
 */
static const BlockColorType BLOCK_COLORS[] = {
    BLOCK_COLOR_I, BLOCK_COLOR_J, BLOCK_COLOR_L, BLOCK_COLOR_O,
    BLOCK_COLOR_S, BLOCK_COLOR_T, BLOCK_COLOR_Z, BLOCK_COLOR_PREDICT};
#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_COMMON_COLORS_H_
