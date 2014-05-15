#include "gitbranchdialog.h"
#include "ui_gitbranchdialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include "giterrordialog.h"

GitBranchDialog::GitBranchDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitBranchDialog)
{
  ui->setupUi(this);
}

GitBranchDialog::~GitBranchDialog()
{
  delete ui;
}


void GitBranchDialog::on_branchButton_clicked()
{
  QString path = *(this->path);
  string repoPath = path.toStdString();
  string name = ui->branch->text().toStdString();
  GitAPIResponse response = GitApi::gitBranch(repoPath, name);
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

void GitBranchDialog::on_cancelButton_clicked()
{
  reject();
}
