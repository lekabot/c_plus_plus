#include "game_status.h"

void initGameStatus(GameStatus* gameStatus) {
  gameStatus->level = 0;
  gameStatus->score = 0;
}

void addScoreGameStatus(GameStatus* gameStatus, int completeLinesCount) {
  if (completeLinesCount <= 0) {
    return;
  }
  if (completeLinesCount > MAX_AVAILABLE_COMPLETE_LINES_COUNT) {
    completeLinesCount = MAX_AVAILABLE_COMPLETE_LINES_COUNT;
  }
  int earnedScore = SCORE_COMPLETE_LINES_COUNT_ARRAY[completeLinesCount - 1];
  gameStatus->score += earnedScore;
}

void updateGameStatusLevel(GameStatus* gameStatus) {
  int currentLevel = (gameStatus->score / SCORE_PER_LEVEL);

  if (currentLevel > MAX_LEVEL) {
    currentLevel = MAX_LEVEL;
  }
  gameStatus->level = currentLevel;
}