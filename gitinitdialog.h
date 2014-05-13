#ifndef GITINITDIALOG_H
#define GITINITDIALOG_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class GitInitDialog;
}

class GitInitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitInitDialog(QWidget *parent = 0);
    ~GitInitDialog();

  private slots:

    void on_initButton_clicked();

    void on_cancelButton_clicked();

    void on_treeView_activated(const QModelIndex &index);

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::GitInitDialog *ui;
    QFileSystemModel* directoyTree;

};

#endif // GITINITDIALOG_H
