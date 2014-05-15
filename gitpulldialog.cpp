#include "gitpulldialog.h"
#include "ui_gitpulldialog.h"
#include "localrepoparser.h"
#include "gitapi.h"
#include "gitapiresponse.h"

GitPullDialog::GitPullDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitPullDialog)
{
  ui->setupUi(this);
}

GitPullDialog::~GitPullDialog()
{
  delete ui;
}

void GitPullDialog::assembleSelectors(){
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

void GitPullDialog::on_pullButton_clicked(){
  /*
  int selectedBranch = ui->branchSelector->currentIndex();
  int selectedRemote = ui->remoteSelector->currentIndex();
  string gitpath = path->toStdString();
  //GitAPIResponse response;
  */
  accept();
}

void GitPullDialog::on_cancelButton_clicked()
{
  reject();
}
