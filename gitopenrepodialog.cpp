#include "gitopenrepodialog.h"
#include "ui_gitopenrepodialog.h"
#include "gitapi.h"
#include "giterrordialog.h"

gitOpenRepoDialog::gitOpenRepoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gitOpenRepoDialog)
{
    ui->setupUi(this);

    QString rootPath = "/home";
    directoryTree = new QFileSystemModel(this);
    directoryTree->setRootPath(rootPath);
    directoryTree->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeView->setModel(directoryTree);

}

gitOpenRepoDialog::~gitOpenRepoDialog()
{
    delete ui;
}

void gitOpenRepoDialog::on_pushButton_clicked()
{
    QString path = ui->path->text();

    if(path.toStdString().empty())
      return;

    QString testPath = path + "/.git";

    QDir dir(testPath);

    if(!dir.exists()){
        gitErrorDialog ErrorBox;
        ErrorBox.setModal(true);
        ErrorBox.exec();
    }
    else{

    }

    accept();
}

void gitOpenRepoDialog::on_treeView_clicked(const QModelIndex &index)
{
    QString path = directoryTree->fileInfo(index).absoluteFilePath();
    ui->path->setText(path);
}
