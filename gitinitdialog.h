#ifndef GITINITDIALOG_H
#define GITINITDIALOG_H

#include <QDialog>

namespace Ui {
class GitInitDialog;
}

class GitInitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitInitDialog(QWidget *parent = 0);
    ~GitInitDialog();

private:
    Ui::GitInitDialog *ui;
};

#endif // GITINITDIALOG_H
