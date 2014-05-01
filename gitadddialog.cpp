#include "gitadddialog.h"
#include "ui_gitadddialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include <QFileDialog>

GitAddDialog::GitAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitAddDialog)
{
    ui->setupUi(this);
}

GitAddDialog::~GitAddDialog()
{
    delete ui;
}

void GitAddDialog::on_addButton_clicked()
{
  string path = "/home/maura/Desktop/GitTest";
  if (! filenames.empty()){
    GitAPIResponse response = GitApi::gitAdd(path, filenames);
    //GitApi::gitAdd_All();
  }
  accept();
}

void GitAddDialog::on_cancelButton_clicked()
{
  reject();
}

void GitAddDialog::on_fileBrowse_clicked()
{
  QFileDialog fileD(this);
  fileD.setFileMode(QFileDialog::ExistingFiles);
  if ( fileD.exec())
    filenames = fileD.selectedFiles();
}
