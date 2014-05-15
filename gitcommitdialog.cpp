#include "gitcommitdialog.h"
#include "ui_gitcommitdialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include <string>
#include "giterrordialog.h"

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
  string message = ui->commitMessage->toPlainText().toStdString();
  string path = this->path->toStdString();
  GitAPIResponse response = GitApi::gitCommit(path, message);
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

void GitCommitDialog::on_cancelButton_clicked()
{
  reject();
}
