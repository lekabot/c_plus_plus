#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QApplication>
#include <QPainter>
#include <QWidget>

#include "../../../brick_game/common/board/board.h"
#include "../../../brick_game/common/player/player.h"
#include "constants.h"

class GridWidget : public QWidget {
  Q_OBJECT
 public:
  explicit GridWidget(QWidget *parent = nullptr,
                      int rows = s21::constants::m_Rows,
                      int columns = s21::constants::m_Columns);

  void SetBoard(Board board);
  void SetPlayer(Player player);
  void SetPredictPlayer(Player player);
  void SetFruit(Cell fruit);
  void SetCurrentGame(s21::CurrentGame currentGame);

 protected:
  void paintEvent(QPaintEvent *event) override;
  void DrawPlayer(QPainter *painter, Player *player);
  void DrawSnake(QPainter *painter, Player *player);

 private:
  Board m_Board;
  Player m_Player;
  Player m_Predict_Played;
  Cell m_Fruit;
  int m_Row;
  int m_Columns;
  s21::CurrentGame m_Current_Game{s21::CurrentGame::m_Snake};
};

#endif  // GRIDWIDGET_H
