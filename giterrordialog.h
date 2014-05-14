#ifndef GITERRORDIALOG_H
#define GITERRORDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
  class GitErrorDialog;
}

class GitErrorDialog : public QDialog
{
    Q_OBJECT
    
  public:
    explicit GitErrorDialog(QWidget *parent = 0);
    ~GitErrorDialog();
    void updateMessage(QString& message);
    
  private slots:
    void on_okButton_clicked();

  private:
    Ui::GitErrorDialog *ui;
};

#endif // GITERRORDIALOG_H
