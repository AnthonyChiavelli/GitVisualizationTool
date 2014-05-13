#ifndef GITERRORDIALOG_H
#define GITERRORDIALOG_H

#include <QDialog>

namespace Ui {
class gitErrorDialog;
}

class gitErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gitErrorDialog(QWidget *parent = 0);
    ~gitErrorDialog();

private:
    Ui::gitErrorDialog *ui;
};

#endif // GITERRORDIALOG_H
