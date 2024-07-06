#include "GridWidget.h"

GridWidget::GridWidget(QWidget *parent, int rows, int columns)
    : QWidget(parent), m_Row(rows), m_Columns(columns) {
  setFixedSize(m_Columns * s21::constants::m_Cell_Size,
               m_Row * s21::constants::m_Cell_Size);
}

void GridWidget::SetBoard(Board board) {
  m_Board = board;
  update();
}

void GridWidget::SetPlayer(Player player) {
  m_Player = player;
  update();
}

void GridWidget::SetPredictPlayer(Player player) {
  m_Predict_Played = player;
  update();
}

void GridWidget::SetFruit(Cell fruit) { m_Fruit = fruit; }

void GridWidget::SetCurrentGame(s21::CurrentGame currentGame) {
  m_Current_Game = currentGame;
}

void GridWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(s21::constants::m_Color_Array[7]);
  for (int row_i = 0; row_i < s21::constants::m_Rows; ++row_i) {
    for (int col_i = 0; col_i < s21::constants::m_Columns; ++col_i) {
      painter.drawRect(col_i * s21::constants::m_Cell_Size,
                       row_i * s21::constants::m_Cell_Size,
                       s21::constants::m_Cell_Size,
                       s21::constants::m_Cell_Size);
    }
  }

  for (int row_i = 0; row_i < s21::constants::m_Rows; ++row_i) {
    for (int col_i = 0; col_i < s21::constants::m_Columns; ++col_i) {
      if (m_Board.cells[row_i][col_i].isSet) {
        int color = m_Board.cells[row_i][col_i].color;
        auto objColor = s21::constants::m_Color_Array[color];
        painter.fillRect(col_i * s21::constants::m_Cell_Size,
                         row_i * s21::constants::m_Cell_Size,
                         s21::constants::m_Cell_Size,
                         s21::constants::m_Cell_Size, objColor);
      }
    }
  }
  DrawPlayer(&painter, &m_Predict_Played);
  DrawPlayer(&painter, &m_Player);

  DrawSnake(&painter, &m_Player);
}

void GridWidget::DrawPlayer(QPainter *painter, Player *player) {
  int playerPosX = player->x;
  int playerPosY = player->y;
  PlayerBoard playerBoard = player->board;

  for (int row_i = 0; row_i < PLAYER_BOARD_SIZE; ++row_i) {
    for (int col_i = 0; col_i < PLAYER_BOARD_SIZE; ++col_i) {
      int printY = playerPosY + row_i;
      int printX = playerPosX + col_i;

      if (playerBoard.board[row_i][col_i].isSet) {
        int color = playerBoard.board[row_i][col_i].color;
        auto objColor = s21::constants::m_Color_Array[color];
        painter->fillRect(printX * s21::constants::m_Cell_Size,
                          printY * s21::constants::m_Cell_Size,
                          s21::constants::m_Cell_Size,
                          s21::constants::m_Cell_Size, objColor);
      }
    }
  }
}

void GridWidget::DrawSnake(QPainter *painter, Player *player) {
  if (m_Current_Game == s21::CurrentGame::m_Snake) {
    for (int y = 0; y < m_Board.height; ++y) {
      for (int x = 0; x < m_Board.width; ++x) {
        bool isSnakeBody = false;
        for (int snakeI = 0; snakeI < player->snakeLength; ++snakeI) {
          if (player->snakeBody[snakeI].x == x &&
              player->snakeBody[snakeI].y == y) {
            painter->fillRect(
                x * s21::constants::m_Cell_Size,
                y * s21::constants::m_Cell_Size, s21::constants::m_Cell_Size,
                s21::constants::m_Cell_Size, QColor(50, 210, 50, 255));
            isSnakeBody = true;
            break;
          }
        }
        if (!isSnakeBody && x == m_Fruit.x && y == m_Fruit.y) {
          painter->fillRect(
              x * s21::constants::m_Cell_Size, y * s21::constants::m_Cell_Size,
              s21::constants::m_Cell_Size, s21::constants::m_Cell_Size,
              QColor(210, 50, 50, 255));
        }
        if (isSnakeBody && x == m_Fruit.x && y == m_Fruit.y) {
          painter->fillRect(
              x * s21::constants::m_Cell_Size, y * s21::constants::m_Cell_Size,
              s21::constants::m_Cell_Size, s21::constants::m_Cell_Size,
              QColor(70, 150, 70, 255));
        }
      }
    }
  }
}
