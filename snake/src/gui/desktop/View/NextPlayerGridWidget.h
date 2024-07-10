#ifndef NEXTPLAYERGRIDWIDGET_H
#define NEXTPLAYERGRIDWIDGET_H

#include <QApplication>
#include <QPainter>
#include <QWidget>

#include "../../../brick_game/common/board/board.h"
#include "../../../brick_game/common/player/player.h"
#include "constants.h"

class NextPlayerGridWidget : public QWidget {
  Q_OBJECT
 public:
  explicit NextPlayerGridWidget(QWidget *parent = nullptr);
  void SetPlayers(Player nextPlayer);

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  Player m_Next_Player;
};

#endif  // NEXTPLAYERGRIDWIDGET_H
