#include "cell.h"

#include "../common/colors.h"

void initCell(Cell *cell) {
  cell->isSet = false;
  cell->color = COLOR_BLACK;
  cell->x = 0;
  cell->y = 0;
}

void copyCell(Cell *cellDest, Cell cellSrc) {
  cellDest->color = cellSrc.color;
  cellDest->isSet = cellSrc.isSet;
  cellDest->x = cellSrc.x;
  cellDest->y = cellSrc.y;
}
