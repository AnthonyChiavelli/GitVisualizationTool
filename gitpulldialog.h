#ifndef GITPULLDIALOG_H
#define GITPULLDIALOG_H

#include <QDialog>
#include "branch.h"
#include "remote.h"

namespace Ui {
  class GitPullDialog;
}

class GitPullDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitPullDialog(QWidget *parent = 0);
    ~GitPullDialog();
    QString* path;
    QList<Branch *>* branches;
    QList<Remote *>* remotes;
    void assembleSelectors();
    
  private slots:
    void on_pullButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitPullDialog *ui;
};

#endif // GITPULLDIALOG_H
