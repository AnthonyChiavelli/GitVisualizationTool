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

private:
    Ui::GitAddDialog *ui;
};

#endif // GITADDDIALOG_H
