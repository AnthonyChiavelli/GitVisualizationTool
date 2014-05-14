#include "gitcheckoutdialog.h"
#include "ui_gitcheckoutdialog.h"

GitCheckoutDialog::GitCheckoutDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitCheckoutDialog)
{
  ui->setupUi(this);
}

GitCheckoutDialog::~GitCheckoutDialog()
{
  delete ui;
}

void GitCheckoutDialog::on_checkoutButton_clicked()
{

  accept();
}

void GitCheckoutDialog::on_cancelButton_clicked()
{
  reject();
}
