#ifndef GITOPENREPODIALOG_H
#define GITOPENREPODIALOG_H

#include <QDialog>
#include <QFileSystemModel>

class GGraphicsScene;

namespace Ui {
class gitOpenRepoDialog;
}

class gitOpenRepoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gitOpenRepoDialog(QWidget *parent = 0);
    GGraphicsScene* scene;
    QString *path;
    ~gitOpenRepoDialog();

private slots:
    void on_pushButton_clicked();
    void on_treeView_clicked(const QModelIndex &index);


private:
    Ui::gitOpenRepoDialog *ui;
    QFileSystemModel* directoryTree;
};

#endif // GITOPENREPODIALOG_H