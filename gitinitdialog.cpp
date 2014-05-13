#include "gitinitdialog.h"
#include "ui_gitinitdialog.h"
#include "gitapi.h"
#include "gitapiresponse.h"
#include <string>
#include <QFileSystemModel>
#include <QtCore>
#include <QtGui>
#include <QDialog>

GitInitDialog::GitInitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitInitDialog)
{
    ui->setupUi(this);

    QString rootPath = "/home";
    directoyTree = new QFileSystemModel(this);
    directoyTree->setRootPath(rootPath);
    directoyTree->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeView->setModel(directoyTree);

}

GitInitDialog::~GitInitDialog()
{
    delete ui;
}

void GitInitDialog::on_initButton_clicked()
{
  string path = ui->path->text().toStdString();
  if(path.empty())
    return;
  GitAPIResponse response = GitApi::gitInit(path);
  accept();
}

void GitInitDialog::on_cancelButton_clicked()
{
  reject();
}

void GitInitDialog::on_treeView_activated(const QModelIndex &index)
{

}

void GitInitDialog::on_treeView_clicked(const QModelIndex &index)
{
    QString path = directoyTree->fileInfo(index).absoluteFilePath();
    ui->path->setText(path);
}
