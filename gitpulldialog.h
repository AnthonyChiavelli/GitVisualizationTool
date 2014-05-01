#ifndef GITPULLDIALOG_H
#define GITPULLDIALOG_H

#include <QDialog>

namespace Ui {
  class GitPullDialog;
}

class GitPullDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitPullDialog(QWidget *parent = 0);
    ~GitPullDialog();
    
  private slots:
    void on_pullButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitPullDialog *ui;
};

#endif // GITPULLDIALOG_H
