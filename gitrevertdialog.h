#ifndef GITREVERTDIALOG_H
#define GITREVERTDIALOG_H

#include <QDialog>

namespace Ui {
  class GitRevertDialog;
}

class GitRevertDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitRevertDialog(QWidget *parent = 0);
    ~GitRevertDialog();
    
  private slots:
    void on_revertButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitRevertDialog *ui;
};

#endif // GITREVERTDIALOG_H
