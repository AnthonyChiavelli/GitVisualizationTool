#ifndef GITCOMMITDIALOG_H
#define GITCOMMITDIALOG_H

#include <QDialog>

namespace Ui {
  class GitCommitDialog;
}

class GitCommitDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitCommitDialog(QWidget *parent = 0);
    QString* path;
    ~GitCommitDialog();
    
  private slots:
    void on_commitButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitCommitDialog *ui;
};

#endif // GITCOMMITDIALOG_H
