#include "gitinitdialog.h"
#include "ui_gitinitdialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include <string>

GitInitDialog::GitInitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitInitDialog)
{
    ui->setupUi(this);
}

GitInitDialog::~GitInitDialog()
{
    delete ui;
}



void GitInitDialog::on_initButton_clicked()
{
  std::string path = ui->path->text().toStdString();
  GitAPIResponse init = GitApi::gitInit(path);
  accept();
}

void GitInitDialog::on_cancelButton_clicked()
{
  reject();
}
