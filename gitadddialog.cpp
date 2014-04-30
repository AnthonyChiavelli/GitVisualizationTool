#include "gitadddialog.h"
#include "ui_gitadddialog.h"

GitAddDialog::GitAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitAddDialog)
{
    ui->setupUi(this);
}

GitAddDialog::~GitAddDialog()
{
    delete ui;
}

void GitAddDialog::on_addButton_clicked()
{

}

void GitAddDialog::on_cancelButton_clicked()
{
  //delete ui; //doesn't work
  //delete this; //doesn't work
}
