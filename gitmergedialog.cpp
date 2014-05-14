#include "gitmergedialog.h"
#include "ui_gitmergedialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include "branch.h"
#include <string>
#include "localrepoparser.h"
#include <iostream>

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
    std::cout << "Branch: " << name.toStdString() << " Index: " << i << std::endl;
  }
  this->adjustSize();
}

void GitMergeDialog::on_mergeButton_clicked()
{
  int selected = ui->branchSelector->currentIndex();
  std::cout << "selected index" << selected << std::endl;
  string gitpath = path->toStdString();
  std::cout << gitpath << std::endl;
  string name = branches->at(selected)->getName();
  std::cout << "branch " << name << std::endl;
  string message = "Merging \"" + name + "\" into current branch.";
  GitAPIResponse response = GitApi::gitMergeByName(gitpath, name, message);
  //GitAPIResponse response = GitApi::gitMerge(gitpath, *(branches->at(selected)), message);
  accept();
}

void GitMergeDialog::on_cancelButton_clicked()
{
  reject();
}
