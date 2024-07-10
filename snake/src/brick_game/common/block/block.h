/**
 * @file block.h
 * @brief This file defines the block data structure and related functions for
 * the brick game.
 */

#ifndef CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_BLOCK_BLOCK_H_
#define CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_BLOCK_BLOCK_H_

#include "../common/colors.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @var BLOCK_BIT_MASK
 * @brief Array containing the bit masks for each block type.
 * The first dimension represents the block type, and the second dimension
 * represents the 4 possible block rotations.
 */
static const int BLOCK_BIT_MASK[][4] = {
    {0b0100010001000100, 0b0000000011110000, 0b0100010001000100,
     0b0000000011110000},  // I
    {0b0000001000100110, 0b0000010001110000, 0b0000001100100010,
     0b0000000001110001},  // J
    {0b0000001000100011, 0b0000000001110100, 0b0000011000100010,
     0b0000000101110000},  // L
    {0b0000011001100000, 0b0000011001100000, 0b0000011001100000,
     0b0000011001100000},  // O
    {0b0000000000110110, 0b0000010001100010, 0b0000000000110110,
     0b0000010001100010},  // S
    {0b0000001001110000, 0b0000001000110010, 0b0000000001110010,
     0b0000001001100010},  // T
    {0b0000000001100011, 0b0000001001100100, 0b0000000001100011,
     0b0000001001100100},  // Z
};

/**
 * @enum BlockType
 * @brief Enum representing the different types of blocks used in the game.
 */
typedef enum {
  BLOCK_I = 0,     /**< I block */
  BLOCK_J = 1,     /**< J block */
  BLOCK_L = 2,     /**< L block */
  BLOCK_O = 3,     /**< O block */
  BLOCK_S = 4,     /**< S block */
  BLOCK_T = 5,     /**< T block */
  BLOCK_Z = 6,     /**< Z block */
  BLOCK_SNAKE = 7, /**< Snake block */
  BLOCK_FRUIT = 8  /**< Fruit block */
} BlockType;

/**
 * @enum Direction
 * @brief Enum representing the possible directions for block rotation.
 */
typedef enum {
  DIRECTION_1 = 0, /**< Direction 1 */
  DIRECTION_2 = 1, /**< Direction 2 */
  DIRECTION_3 = 2, /**< Direction 3 */
  DIRECTION_4 = 3  /**< Direction 4 */
} Direction;

/**
 * @brief Get a random block type.
 * @return Random block type.
 */
BlockType getRandomBlockType();

/**
 * @brief Get the next block rotation direction.
 * @param blockDirection The current block rotation direction.
 * @return The next block rotation direction.
 */
Direction getNextBlockDirection(Direction blockDirection);

/**
 * @brief Get the previous block rotation direction.
 * @param blockDirection The current block rotation direction.
 * @return The previous block rotation direction.
 */
Direction getPreviousBlockDirection(Direction blockDirection);

/**
 * @brief Get the color of a specific block type.
 * @param blockType The type of block.
 * @return Color of the block.
 */
BlockColorType getBlockColor(BlockType blockType);

#ifdef __cplusplus
}
#endif

#endif  // CPP3_BRICK_GAME_V_2_0_1_BRICK_GAME_COMMON_BLOCK_BLOCK_H_
