#include "giterrordialog.h"
#include "ui_giterrordialog.h"

GitErrorDialog::GitErrorDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitErrorDialog)
{
  ui->setupUi(this);
}

GitErrorDialog::~GitErrorDialog()
{
  delete ui;
}

void GitErrorDialog::updateMessage(QString& message)
{
  ui->errorLabel->setText(message);
  this->adjustSize();

}

void GitErrorDialog::on_okButton_clicked()
{
  accept();
}
