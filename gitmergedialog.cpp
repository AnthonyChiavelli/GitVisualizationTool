#include "gitmergedialog.h"
#include "ui_gitmergedialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include <string>

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

void GitMergeDialog::on_mergeButton_clicked()
{
  string name = ui->branchSelector->currentText().toStdString();
  string path = "/home/maura/Desktop/GitTest";
  string message = "Merging \"" + name + "\" into current branch.";
  GitAPIResponse response = GitApi::gitMerge(path, name, message);
  accept();
}

void GitMergeDialog::on_cancelButton_clicked()
{
  reject();
}
