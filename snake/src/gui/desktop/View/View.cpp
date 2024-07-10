#include "View.h"

#include "ui_View.h"

namespace s21 {

View::View(QWidget *parent) : QMainWindow(parent), m_UI(new Ui::View) {
  m_UI->setupUi(this);
  m_ViewTabSwitcher = new ViewTabSwitcher(m_UI, this);
  InitUI();

  m_Timer = new QTimer(this);

  connect(m_Timer, &QTimer::timeout, [=]() { HandleSignal(S_NONE); });

  m_Timer->start(1);
}

View::~View() {
  delete m_UI;
  delete m_ViewTabSwitcher;
  delete m_Timer;
}

void View::HandleSignal(SignalType signalType) {
  m_SignalType = signalType;
  if (m_CurrentGame == CurrentGame::m_Tetris) {
    UpdateTetris();
  } else if (m_CurrentGame == CurrentGame::m_Snake) {
    UpdateSnake();
  } else if (m_SignalType == S_ESCAPE_BUTTON) {
    this->close();
  }
}

void View::UpdateTetris() {
  SignalType signal = m_SignalType;
  signalAction(signal, p_tetrisParameters);
  PrintState(*p_tetrisParameters->tetrisState, m_UI->label_state_tetris);

  if (*p_tetrisParameters->tetrisState != S_START &&
      *p_tetrisParameters->tetrisState != S_PAUSE) {
    m_UI->widget_snake->SetCurrentGame(CurrentGame::m_Tetris);
    m_UI->widget_tetris->SetBoard(*p_tetrisParameters->tetrisBoard);
    m_UI->widget_tetris->SetPlayer(*p_tetrisParameters->tetrisPlayer);
    m_UI->widget_tetris->SetPredictPlayer(
        *p_tetrisParameters->tetrisPredictPlayer);
    m_UI->widget_tetris_next_player->SetPlayers(
        *p_tetrisParameters->tetrisNextetPlayer);
    m_UI->label_score_tetris_value->setText(
        QString::number(p_tetrisParameters->tetrisGameStatus->score, 10));
    m_UI->label_level_tetris_value->setText(
        QString::number(p_tetrisParameters->tetrisGameStatus->level, 10));

    PrintTetrisRecords();
  }
  if (*p_tetrisParameters->tetrisState == S_GAME_OVER) {
    bool ok;
    QString name = QInputDialog::getText(this, "Enter Your Name",
                                         "Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
      removeRecord(p_tetrisParameters->tetrisRecords, "Unnamed",
                   TETRIS_RECORDS_FILE_NAME);
      std::string string = name.toStdString();
      const char *convertedString = string.c_str();
      addRecord(p_tetrisParameters->tetrisRecords, convertedString,
                p_tetrisParameters->tetrisGameStatus->score,
                TETRIS_RECORDS_FILE_NAME);
    }
  }
  if (*p_tetrisParameters->tetrisState == S_EXIT_STATE) {
    this->close();
  }
}

void View::UpdateSnake() {
  SignalType signal = m_SignalType;
  controllerSnake(signal, p_snakeParameters);

  PrintState(*p_snakeParameters->snakeState, m_UI->label_state_snake);

  if (*p_snakeParameters->snakeState != S_START &&
      *p_snakeParameters->snakeState != S_PAUSE) {
    m_UI->widget_snake->SetCurrentGame(CurrentGame::m_Snake);
    m_UI->widget_snake->SetBoard(*p_snakeParameters->snakeBoard);
    m_UI->widget_snake->SetPlayer(*p_snakeParameters->snakePlayer);
    m_UI->widget_snake->SetFruit(*p_snakeParameters->snakeFruit);

    m_UI->label_score_snake_value->setText(
        QString::number(p_snakeParameters->snakeGameStatus->score, 10));
    m_UI->label_level_snake_value->setText(
        QString::number(p_snakeParameters->snakeGameStatus->level, 10));

    PrintSnakeRecords();
  }
  if (*p_snakeParameters->snakeState == S_GAME_OVER) {
    bool ok;
    QString name = QInputDialog::getText(this, "Enter Your Name",
                                         "Name:", QLineEdit::Normal, "", &ok);
    if (ok && !name.isEmpty()) {
      removeRecord(p_snakeParameters->snakeRecords, "Unnamed",
                   SNAKE_RECORDS_FILE_NAME);
      std::string string = name.toStdString();
      const char *convertedString = string.c_str();
      addRecord(p_snakeParameters->snakeRecords, convertedString,
                p_snakeParameters->snakeGameStatus->score,
                SNAKE_RECORDS_FILE_NAME);
      *p_snakeParameters->snakeState = S_START;
    }
  }
  if (*p_snakeParameters->snakeState == S_EXIT_STATE) {
    this->close();
  }
}

void View::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
      HandleSignal(S_MOVE_UP);
      break;
    case Qt::Key_Down:
    case Qt::Key_S:
      HandleSignal(S_MOVE_DOWN);
      break;
    case Qt::Key_Left:
    case Qt::Key_A:
      HandleSignal(S_MOVE_LEFT);
      break;
    case Qt::Key_Right:
    case Qt::Key_D:
      HandleSignal(S_MOVE_RIGHT);
      break;
    case Qt::Key_Escape:
      HandleSignal(S_ESCAPE_BUTTON);
      break;
    case Qt::Key_Return:
      HandleSignal(S_ENTER_BUTTON);
      break;
    case Qt::Key_P:
      HandleSignal(S_PAUSE_BUTTON);
      break;
    default:
      QWidget::keyPressEvent(event);
  }
}

void View::StartTetrisGame() {
  m_CurrentGame = CurrentGame::m_Tetris;
  initBoard(&tetrisBoard);
  initPlayer(&tetrisPlayer);
  initPlayerPosition(&tetrisPlayer);
  tetrisState = S_START;

  initGameStatus(&m_GameStatus);
  initPlayer(&tetrisPlayer);
  initNextPlayer(&tetrisNextPlayer);
  initBoard(&tetrisBoard);

  tetrisLastetMovedTime = getTimeInMS();

  tetrisParameters.tetrisGameStatus = &m_GameStatus;
  tetrisParameters.tetrisState = &tetrisState;
  tetrisParameters.tetrisBoard = &tetrisBoard;
  tetrisParameters.tetrisPlayer = &tetrisPlayer;
  tetrisParameters.tetrisNextetPlayer = &tetrisNextPlayer;
  tetrisParameters.tetrisPredictPlayer = &tetrisPredictPlayer;
  tetrisParameters.tetrisLastetMovedTime = &tetrisLastetMovedTime;
  tetrisParameters.tetrisRecords = &tetrisRecords;

  loadRecords(tetrisParameters.tetrisRecords, TETRIS_RECORDS_FILE_NAME);
  saveRecords(tetrisParameters.tetrisRecords, TETRIS_RECORDS_FILE_NAME);

  p_tetrisParameters = &tetrisParameters;
}

void View::StartSnakeGame() {
  m_CurrentGame = CurrentGame::m_Snake;
  initBoard(&snakeBoard);
  initGameStatus(&m_GameStatus);

  initPlayer(&snakePlayer);
  setPlayerPosition(&snakePlayer, 10, 10);
  tetrisState = S_START;
  snakePlayer.snakeLength = 4;
  snakePlayer.direction = DIRECTION_2;
  snakePlayer.snakeBody[0].x = 10 / 2;
  snakePlayer.snakeBody[0].y = 20 / 2;

  initCell(&snakeFruit);
  snakeFruit.y = rand() % 10;
  snakeFruit.x = rand() % 20;
  snakeLastetMovedTime = getTimeInMS();

  snakeParameters.snakeState = &snakeState;
  snakeParameters.snakePlayer = &snakePlayer;
  snakeParameters.snakeFruit = &snakeFruit;
  snakeParameters.snakeGameStatus = &snakeGameStatus;
  snakeParameters.snakeBoard = &snakeBoard;
  snakeParameters.snakeRecords = &snakeRecords;
  snakeParameters.snakeLastetMovedTime = &snakeLastetMovedTime;

  loadRecords(snakeParameters.snakeRecords, SNAKE_RECORDS_FILE_NAME);
  saveRecords(snakeParameters.snakeRecords, SNAKE_RECORDS_FILE_NAME);

  p_snakeParameters = &snakeParameters;
}

void View::InitUI() {
  StartTetrisGame();
  connect(m_UI->push_button_tetris, &QPushButton::clicked, this,
          &View::StartTetrisGame);
  connect(m_UI->push_button_snake, &QPushButton::clicked, this,
          &View::StartSnakeGame);

  connect(this, &View::SignalMoveUp, [=]() { HandleSignal(S_MOVE_UP); });
  connect(this, &View::SignalMoveDown, [=]() { HandleSignal(S_MOVE_DOWN); });
  connect(this, &View::SignalMoveLeft, [=]() { HandleSignal(S_MOVE_LEFT); });
  connect(this, &View::SignalMoveRight, [=]() { HandleSignal(S_MOVE_RIGHT); });
  connect(this, &View::SignalEnterButton,
          [=]() { HandleSignal(S_ENTER_BUTTON); });
  connect(this, &View::SignalNoneButton, [=]() { HandleSignal(S_NONE); });
}

void View::PrintTetrisRecords() {
  auto records = p_tetrisParameters->tetrisRecords;
  m_UI->label_records_1_value->setText(
      QString::number(records->records[0].score));
  m_UI->label_records_2_value->setText(
      QString::number(records->records[1].score));
  m_UI->label_records_3_value->setText(
      QString::number(records->records[2].score));
  m_UI->label_records_4_value->setText(
      QString::number(records->records[3].score));
  m_UI->label_records_5_value->setText(
      QString::number(records->records[4].score));
}

void View::PrintSnakeRecords() {
  auto records = p_snakeParameters->snakeRecords;
  m_UI->label_records_snake_1_value->setText(
      QString::number(records->records[0].score));
  m_UI->label_records_snake_2_value->setText(
      QString::number(records->records[1].score));
  m_UI->label_records_snake_3_value->setText(
      QString::number(records->records[2].score));
  m_UI->label_records_snake_4_value->setText(
      QString::number(records->records[3].score));
  m_UI->label_records_snake_5_value->setText(
      QString::number(records->records[4].score));
}

void View::PrintState(State state, QLabel *label) {
  QString stateString{};
  switch (state) {
    case S_GAME_OVER:
      stateString = "Game Over";
      break;
    case S_PAUSE:
      stateString = "Pause";
      break;
    case S_MOVING:
      stateString = "Moving";
    case S_START:
      stateString = "Start";
    case S_EXIT_STATE:
      stateString = "Exit";
    case S_SPAWN:
      stateString = "Spawn";
  }

  label->setText(stateString);
}

}  // namespace s21
