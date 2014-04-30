#include "gitinitdialog.h"
#include "ui_gitinitdialog.h"
#include <string>

GitInitDialog::GitInitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitInitDialog)
{
    ui->setupUi(this);
}

GitInitDialog::~GitInitDialog()
{
    delete ui;
}



void GitInitDialog::on_initButton_clicked()
{

}

void GitInitDialog::on_cancelButton_clicked()
{

}
