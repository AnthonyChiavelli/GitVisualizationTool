#ifndef OPENREPODIALOG_H
#define OPENREPODIALOG_H

#include <QDialog>

namespace Ui {
class OpenRepoDialog;
}

class gitOpenRepoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gitOpenRepoDialog(QWidget *parent = 0);
    ~gitOpenRepoDialog();

private:
    Ui::OpenRepoDialog *ui;
};

#endif // OPENREPODIALOG_H
