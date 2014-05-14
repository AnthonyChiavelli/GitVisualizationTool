#ifndef GITMERGEDIALOG_H
#define GITMERGEDIALOG_H

#include <QDialog>
#include "branch.h"

namespace Ui {
  class GitMergeDialog;
}

class GitMergeDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitMergeDialog(QWidget *parent = 0);
    ~GitMergeDialog();
    QString* path;
    QList<Branch *>* branches;
    void assembleSelector();
    
  private slots:
    void on_mergeButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitMergeDialog *ui;
};

#endif // GITMERGEDIALOG_H
