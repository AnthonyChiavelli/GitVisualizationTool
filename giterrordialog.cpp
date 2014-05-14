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
