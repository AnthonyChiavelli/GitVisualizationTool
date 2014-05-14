#include "gitopenrepodialog.h"
#include "ui_gitopenrepodialog.h"
#include "gitapi.h"
#include "giterrordialog.h"
#include "ggraphicsscene.h"

GitOpenRepoDialog::GitOpenRepoDialog(QWidget *parent) :
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

GitOpenRepoDialog::~GitOpenRepoDialog()
{
    delete ui;
}

void GitOpenRepoDialog::on_pushButton_clicked()
{
    QString path = ui->lineEdit->text();


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
        string pth = path.toStdString();
        this->scene->renderRepository(pth);
        *(this->path) = path;
    }

    accept();
}

void GitOpenRepoDialog::on_treeView_clicked(const QModelIndex &index)
{
    QString path = directoryTree->fileInfo(index).absoluteFilePath();
    ui->lineEdit->setText(path);
}
