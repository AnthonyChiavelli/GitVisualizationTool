#include "gitbranchdialog.h"
#include "ui_gitbranchdialog.h"

GitBranchDialog::GitBranchDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitBranchDialog)
{
  ui->setupUi(this);
}

GitBranchDialog::~GitBranchDialog()
{
  delete ui;
}

void GitBranchDialog::on_pushButton_clicked()
{
  accept();
}

void GitBranchDialog::on_pushButton_2_clicked()
{
  reject();
}
