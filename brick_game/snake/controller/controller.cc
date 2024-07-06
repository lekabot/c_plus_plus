#include "controller.h"

#include "../Model/model.h"

void controllerSnake(SignalType signal, Parameters *parameters) {
  s21::Model model{};
  model.setSignalType(signal);
  model.setParameters(parameters);
  model.signalAction();
}