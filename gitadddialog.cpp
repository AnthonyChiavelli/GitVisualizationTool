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
