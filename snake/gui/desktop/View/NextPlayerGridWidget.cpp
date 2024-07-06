#include "NextPlayerGridWidget.h"

NextPlayerGridWidget::NextPlayerGridWidget(QWidget *parent) : QWidget(parent) {
  setFixedSize(PLAYER_BOARD_SIZE * s21::constants::m_Cell_Size,
               PLAYER_BOARD_SIZE * s21::constants::m_Cell_Size);
}

void NextPlayerGridWidget::SetPlayers(Player nextPlayer) {
  m_Next_Player = nextPlayer;
  update();
}

void NextPlayerGridWidget::paintEvent(QPaintEvent *event) {
  QPainter painer(this);
  painer.setRenderHint(QPainter::Antialiasing);

  painer.setPen(s21::constants::m_Color_Array[7]);
  for (int row_i = 0; row_i < PLAYER_BOARD_SIZE; ++row_i) {
    for (int col_i = 0; col_i < PLAYER_BOARD_SIZE; ++col_i) {
      painer.drawRect(col_i * s21::constants::m_Cell_Size,
                      row_i * s21::constants::m_Cell_Size,
                      s21::constants::m_Cell_Size, s21::constants::m_Cell_Size);
    }
  }

  for (int row_i = 0; row_i < PLAYER_BOARD_SIZE; ++row_i) {
    for (int col_i = 0; col_i < PLAYER_BOARD_SIZE; ++col_i) {
      if (m_Next_Player.board.board[row_i][col_i].isSet) {
        int color = m_Next_Player.board.board[row_i][col_i].color;
        auto objColor = s21::constants::m_Color_Array[color];
        painer.fillRect(col_i * s21::constants::m_Cell_Size,
                        row_i * s21::constants::m_Cell_Size,
                        s21::constants::m_Cell_Size,
                        s21::constants::m_Cell_Size, objColor);
      }
    }
  }
}
