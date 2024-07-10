#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QColor>

namespace s21 {
namespace constants {

inline constexpr int m_Cell_Size = 21;
inline constexpr int m_Rows = 20;
inline constexpr int m_Columns = 10;

inline static QColor m_Color_Array[] = {
    {254, 3, 0, 210},     {255, 102, 0, 210},   {255, 254, 6, 210},
    {255, 153, 203, 210}, {1, 128, 2, 210},     {1, 0, 254, 210},
    {129, 0, 128, 210},   {150, 150, 150, 100},
};

}  // namespace constants

enum CurrentGame {
  m_Tetris,
  m_Snake,
  m_CarRacing,
  m_Tank_Classic,
};

}  // namespace s21

#endif  // CONSTANTS_H
