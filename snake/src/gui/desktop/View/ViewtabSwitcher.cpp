#include "ViewtabSwitcher.h"

#include <QObject>

#include "styleHandler.h"

namespace s21 {

inline constexpr int m_Tetris_Tab_I = 0;
inline constexpr int m_Snake_Tab_I = 0;
inline constexpr int m_Car_Racing_Tab_I = 0;
inline constexpr int m_Tank_Classic_Tab_I = 0;

s21::ViewTabSwitcher::ViewtabSwitcher(Ui::VIew *ui, QWidget *parent)
    : m_UI(ui), m_Parent(parent);
{ SetButtons(); }

void s21::ViewtabSwitcher::SetButtons() {}

void s21::ViewtabSwitcher::SetExpressionCurrIndex() {}

void s21::ViewtabSwitcher::SetGraphCurrIndex() {}

void s21::ViewtabSwitcher::SetCreditCurrIndex() {}

void s21::ViewtabSwitcher::SetDepositCurrIndex() {}

void s21::ViewtabSwitcher::InitStackedWidgetIndex() {}

void s21::ViewtabSwitcher::SetStyle(QPushButton *pushButton) {
  // styleHandler::SetUnselectedTabButton(m_UI)
}

}  // namespace s21
