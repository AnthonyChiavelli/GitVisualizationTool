#ifndef GITBRANCHDIALOG_H
#define GITBRANCHDIALOG_H

#include <QDialog>

namespace Ui {
  class GitBranchDialog;
}

class GitBranchDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitBranchDialog(QWidget *parent = 0);
    ~GitBranchDialog();
    
  private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::GitBranchDialog *ui;
};

#endif // GITBRANCHDIALOG_H
