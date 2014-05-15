#ifndef GITPUSHDIALOG_H
#define GITPUSHDIALOG_H

#include <QDialog>
#include "branch.h"
#include "remote.h"

namespace Ui {
  class GitPushDialog;
}

class GitPushDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitPushDialog(QWidget *parent = 0);
    ~GitPushDialog();
    QString* path;
    QList<Branch *>* branches;
    QList<Remote *>* remotes;
    void assembleSelectors();
    
  private slots:
    void on_pushButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitPushDialog *ui;
};

#endif // GITPUSHDIALOG_H
