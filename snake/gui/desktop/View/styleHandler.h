#ifndef STYLEHANDLER_H
#define STYLEHANDLER_H

#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>

namespace s21::styleHandler {

void SetSelectedTabButton(QPushButton *push_button);
void SetUnselectedTabButton(QPushButton *push_button);
void SetDefaultExpressionLineEdit(QLineEdit *line_edit);
void SetIncorrectExpressionLineEdit(QLineEdit *line_edit);
void SetDefaultVariableLineEdit(QLineEdit *line_edit);
void SetIncorrectVariableLineEdit(QLineEdit *line_edit);
void SetDefaultDomainLineEdit(QLineEdit *line_edit);
void SetIncorrectDomainLineEdit(QLineEdit *line_edit);
void SetDefaultCreditLineEdit(QLineEdit *line_edit);
void SetIncorrectCreditLineEdit(QLineEdit *line_edit);
void SetDefaultLineEditWidget(QLineEdit *line_edit);
void SetIncorrectLineEditWidget(QLineEdit *line_edit);
void SetDefaultPushButtonWidget(QPushButton *push_button);
void SetIncorrectPushButtonWidget(QPushButton *push_button);
void SetDefaultWidgetComboBox(QComboBox *combo_box);
void SetDefaultDateEditWidget(QDateEdit *date_edit);
void SetDefaultLineEditDeposit(QLineEdit *line_edit);
void SetIncorrectLineEditDeposit(QLineEdit *line_edit);

}  // namespace s21::styleHandler

#endif  // STYLEHANDLER_H
