#ifndef GITMERGEDIALOG_H
#define GITMERGEDIALOG_H

#include <QDialog>

namespace Ui {
  class GitMergeDialog;
}

class GitMergeDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitMergeDialog(QWidget *parent = 0);
    ~GitMergeDialog();
    
  private slots:
    void on_mergeButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitMergeDialog *ui;
};

#endif // GITMERGEDIALOG_H
