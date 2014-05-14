#include "gitopenrepodialog.h"
#include "ui_gitopenrepodialog.h"
#include "gitapi.h"
#include "giterrordialog.h"
#include "ggraphicsscene.h"
#include "mainwindow.h"

GitOpenRepoDialog::GitOpenRepoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitOpenRepoDialog)
{
    ui->setupUi(this);

    QString rootPath = "/home";
    treeModel = new QFileSystemModel(this);
    treeModel->setRootPath(rootPath);
    treeModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeView->setModel(treeModel);
    ui->treeView->setRootIndex(treeModel->index(rootPath));
    ui->treeView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);
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
/*        GitErrorDialog ErrorBox;
        ErrorBox.setModal(true);
        ErrorBox.exec()*/;
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
    QString path = treeModel->fileInfo(index).absoluteFilePath();
    ui->lineEdit->setText(path);
}
