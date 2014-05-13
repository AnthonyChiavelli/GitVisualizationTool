#include "giterrordialog.h"
#include "ui_giterrordialog.h"

gitErrorDialog::gitErrorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gitErrorDialog)
{
    ui->setupUi(this);
}

gitErrorDialog::~gitErrorDialog()
{
    delete ui;
}
