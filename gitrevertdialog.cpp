#include "gitrevertdialog.h"
#include "ui_gitrevertdialog.h"

GitRevertDialog::GitRevertDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitRevertDialog)
{
  ui->setupUi(this);
}

GitRevertDialog::~GitRevertDialog()
{
  delete ui;
}

void GitRevertDialog::on_revertButton_clicked()
{

}

void GitRevertDialog::on_cancelButton_clicked()
{

}
