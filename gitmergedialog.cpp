#include "gitmergedialog.h"
#include "ui_gitmergedialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include "branch.h"
#include <string>
#include "localrepoparser.h"
#include <iostream>
#include "giterrordialog.h"

GitMergeDialog::GitMergeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitMergeDialog)
{
  ui->setupUi(this);
}

GitMergeDialog::~GitMergeDialog()
{
  delete ui;
}

void GitMergeDialog::assembleSelector()
{
  branches = new QList<Branch*>(LocalRepoParser::getBranches(path->toStdString()));
  for(int i = 0; i < branches->size(); i++){
    Branch next = *(branches->at(i));
    QString name = QString::fromStdString(next.getName());
    ui->branchSelector->addItem(name);
  }
  this->adjustSize();
}

void GitMergeDialog::on_mergeButton_clicked()
{
  int selected = ui->branchSelector->currentIndex();
  string gitpath = path->toStdString();
  string name = branches->at(selected)->getName();
  string message = "Merging \"" + name + "\" into current branch.";
  GitAPIResponse response = GitApi::gitMergeByName(gitpath, name, message);
  //GitAPIResponse response = GitApi::gitMerge(gitpath, *(branches->at(selected)), message);

  if(response.getError()){
    QString message = QString::fromStdString(response.getMessage());
    std::cout << message.toStdString() << std::endl;
    GitErrorDialog ErrorBox;
    ErrorBox.setModal(true);
    ErrorBox.updateMessage(message);
    ErrorBox.exec();
  }
  accept();
}

void GitMergeDialog::on_cancelButton_clicked()
{
  reject();
}
