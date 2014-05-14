#include "gitbranchdialog.h"
#include "ui_gitbranchdialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"

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
  string repoPath = this->path->toStdString();
  string name = ui->branch->text().toStdString();
  GitAPIResponse response = GitApi::gitBranch(repoPath, name);
  accept();
}

void GitBranchDialog::on_cancelButton_clicked()
{
  reject();
}
