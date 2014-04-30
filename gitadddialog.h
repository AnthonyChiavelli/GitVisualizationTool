#ifndef GITADDDIALOG_H
#define GITADDDIALOG_H

#include <QDialog>

namespace Ui {
class GitAddDialog;
}

class GitAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitAddDialog(QWidget *parent = 0);
    ~GitAddDialog();

  private slots:
    void on_addButton_clicked();

    void on_cancelButton_clicked();

  private:
    Ui::GitAddDialog *ui;
};

#endif // GITADDDIALOG_H
