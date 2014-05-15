#include "gitcheckoutdialog.h"
#include "ui_gitcheckoutdialog.h"
#include "localrepoparser.h"
#include "gitapi.h"
#include "giterrordialog.h"

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
  branches = new QList<Branch*>(LocalRepoParser::getBranches(path->toStdString()));
  for(int i = 0; i < branches->size(); i++){
    Branch next = *(branches->at(i));
    QString name = QString::fromStdString(next.getName());
    ui->branchSelector->addItem(name);
  }
  this->adjustSize();
}

void GitCheckoutDialog::on_checkoutButton_clicked()
{
  int selected = ui->branchSelector->currentIndex();
  string gitpath = path->toStdString();
  GitAPIResponse response = GitApi::gitCheckout(gitpath, *(branches->at(selected)));
  if(response.getError()){
    QString message = QString::fromStdString(response.getMessage());
    GitErrorDialog ErrorBox;
    ErrorBox.setModal(true);
    ErrorBox.updateMessage(message);
    ErrorBox.exec();
    reject();
  }
  accept();
}

void GitCheckoutDialog::on_cancelButton_clicked()
{
  reject();
}
