#include "gitcheckoutdialog.h"
#include "ui_gitcheckoutdialog.h"
#include "localrepoparser.h"

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

void GitCheckoutDialog::assembleSelector()
{
  QList<Branch *> branches = LocalRepoParser::getBranches(path->toStdString());
  for(int i = 0; i < branches.size(); i++){
    Branch next = *(branches.at(i));
    QString name = QString::fromStdString(next.getName());
    ui->branchSelector->addItem(name);
  }
  this->adjustSize();
}

void GitCheckoutDialog::on_checkoutButton_clicked()
{

  accept();
}

void GitCheckoutDialog::on_cancelButton_clicked()
{
  reject();
}
