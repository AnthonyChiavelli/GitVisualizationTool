#include "gitcommitdialog.h"
#include "ui_gitcommitdialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include <string>

GitCommitDialog::GitCommitDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitCommitDialog)
{
  ui->setupUi(this);
}

GitCommitDialog::~GitCommitDialog()
{
  delete ui;
}

void GitCommitDialog::on_commitButton_clicked()
{
  std::string message = ui->commitMessage->toPlainText().toStdString();
  std::string path = "/home/maura/Desktop/GitTest";
  GitAPIResponse response = GitApi::gitCommit(path, message);
  accept();
}

void GitCommitDialog::on_cancelButton_clicked()
{
  reject();
}
