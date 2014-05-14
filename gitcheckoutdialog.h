#ifndef GITCHECKOUTDIALOG_H
#define GITCHECKOUTDIALOG_H

#include <QDialog>

namespace Ui {
  class GitCheckoutDialog;
}

class GitCheckoutDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitCheckoutDialog(QWidget *parent = 0);
    ~GitCheckoutDialog();
    QString* path;
    
  private slots:
    void on_checkoutButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitCheckoutDialog *ui;
};

#endif // GITCHECKOUTDIALOG_H
