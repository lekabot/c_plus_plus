#include "block.h"

#include <stdlib.h>

BlockType getRandomBlockType() {
  BlockType blockType = (BlockType)(rand() % (BLOCK_Z + 1));
  return blockType;
}

Direction getNextBlockDirection(Direction blockDirection) {
  Direction nextBlockDirection = DIRECTION_1;
  if (blockDirection == DIRECTION_1) {
    nextBlockDirection = DIRECTION_2;
  } else if (blockDirection == DIRECTION_2) {
    nextBlockDirection = DIRECTION_3;
  } else if (blockDirection == DIRECTION_3) {
    nextBlockDirection = DIRECTION_4;
  } else if (blockDirection == DIRECTION_4) {
    nextBlockDirection = DIRECTION_1;
  }
  return nextBlockDirection;
}

Direction getPreviousBlockDirection(Direction blockDirection) {
  Direction previousBlockDirection = DIRECTION_1;
  if (blockDirection == DIRECTION_1) {
    previousBlockDirection = DIRECTION_4;
  } else if (blockDirection == DIRECTION_2) {
    previousBlockDirection = DIRECTION_1;
  } else if (blockDirection == DIRECTION_3) {
    previousBlockDirection = DIRECTION_2;
  } else if (blockDirection == DIRECTION_4) {
    previousBlockDirection = DIRECTION_3;
  }
  return previousBlockDirection;
}

BlockColorType getBlockColor(BlockType blockType) {
  BlockColorType blockColorType;
  blockColorType = BLOCK_COLORS[blockType];
  return blockColorType;
}