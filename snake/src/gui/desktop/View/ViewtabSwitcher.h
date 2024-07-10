#ifndef VIEWTABSWITCHER_H
#define VIEWTABSWITCHER_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

#include "GridWidget.h"
#include "NextPlayerGridWidget.h"
#include "ui_View.h"

QT_BEGIN_NAMESPACE
namespace UI {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class ViewtabSwitcher : public QWidget {
  Q_OBJECT
 public:
  explicit ViewTabSwitcher(Ui::VIew *ui, QWidget *parent = nullptr);
  ~ViewTabSwitcher() = default;

  void SetButtons();

 public slots:
  void SetExpressionCurrIndex();
  void SetGraphCurrIndex();
  void SetCreditCurrIndex();
  void SetDepositCurrIndex();
  void InitStackedWidgetIndex();

  void SetStyle(QPushButton *pushButton);

 protected:
  Ui::VIew *m_UI;
  QWidget *m_Parent;
};

}  // namespace s21

#endif  // VIEWTABSWITCHER_H
