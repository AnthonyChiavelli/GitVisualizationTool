#include "gitpushdialog.h"
#include "ui_gitpushdialog.h"

GitPushDialog::GitPushDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitPushDialog)
{
  ui->setupUi(this);
}

GitPushDialog::~GitPushDialog()
{
  delete ui;
}

void GitPushDialog::on_pushButton_clicked()
{
  accept();
}

void GitPushDialog::on_cancelButton_clicked()
{
  reject();
}
