#ifndef VIEW_H
#define VIEW_H

#include <QInputDialog>
#include <QKeyEvent>
#include <QLabel>
#include <QLayoutItem>
#include <QMainWindow>
#include <QPushButton>
#include <QTimer>

#include "../../../brick_game/common/fsm_types.h"
#include "../../../brick_game/common/parameters/parameters.h"
#include "../../../brick_game/snake/controller/controller.h"
#include "../../../brick_game/tetris/fsm/fsm.h"
#include "GridWidget.h"
#include "NextPlayerGridWidget.h"
#include "ViewTabSwitcher.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(QWidget *parent = nullptr);
  ~View();

  void HandleSignal(SignalType signalType);
  void UpdateTetris();
  void UpdateSnake();

 signals:
  void SignalMoveUp();
  void SignalMoveDown();
  void SignalMoveLeft();
  void SignalMoveRight();

  void SignalEscButton();
  void SignalEnterButton();
  void SignalPauseButton();
  void SignalNoneButton();

 protected:
  void keyPressEvent(QKeyEvent *event) override;
 private slots:
  void StartTetrisGame();
  void StartSnakeGame();

 private:
  Ui::View *m_UI;

  ViewTabSwitcher *m_ViewTabSwitcher;
  SignalType m_SignalType{};

  GameStatus m_GameStatus{};
  Board tetrisBoard{};
  Player tetrisPlayer{};
  Player tetrisNextPlayer{};
  Player tetrisPredictPlayer{};
  State tetrisState = S_START;
  Records tetrisRecords{};
  Parameters tetrisParameters{};

  long long tetrisLastetMovedTime{};

  Board snakeBoard{};
  GameStatus snakeGameStatus{};
  Player snakePlayer{};
  State snakeState = S_START;
  Records snakeRecords{};
  Cell snakeFruit{};
  Parameters snakeParameters{};

  long long snakeLastetMovedTime{};

  Parameters *p_tetrisParameters;
  Parameters *p_snakeParameters;

  QTimer *m_Timer;

  CurrentGame m_CurrentGame{CurrentGame::m_Tetris};

  void InitUI();
  void PrintTetrisRecords();
  void PrintSnakeRecords();
  void PrintState(State state, QLabel *label);
};
}  // namespace s21

#endif  // VIEW_H
