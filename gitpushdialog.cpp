#include "gitpushdialog.h"
#include "ui_gitpushdialog.h"
#include "localrepoparser.h"
#include "gitapi.h"
#include "gitapiresponse.h"

GitPushDialog::GitPushDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitPushDialog)
{
  ui->setupUi(this);
}

GitPushDialog::~GitPushDialog()
{
  delete ui;
}

void GitPushDialog::assembleSelectors(){
  /*
  branches = new QList<Branch*>(LocalRepoParser::getBranches(path->toStdString()));
  for(int i = 0; i < branches->size(); i++){
    Branch next = *(branches->at(i));
    QString name = QString::fromStdString(next.getName());
    ui->branchSelector->addItem(name);
  }
  this->adjustSize();
  */
}

void GitPushDialog::on_pushButton_clicked(){
  /*
  int selectedBranch = ui->branchSelector->currentIndex();
  int selectedRemote = ui->remoteSelector->currentIndex();
  string gitpath = path->toStdString();
  //GitAPIResponse response;
  */
  accept();
}

void GitPushDialog::on_cancelButton_clicked(){
  reject();
}
