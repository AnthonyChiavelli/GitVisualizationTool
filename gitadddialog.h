#ifndef GITADDDIALOG_H
#define GITADDDIALOG_H
#include <QStringList>
#include <QFileDialog>
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
    QString* path;
    QStringList filenames;

  private slots:
    void on_addButton_clicked();

    void on_cancelButton_clicked();

    void on_fileBrowse_clicked();

  private:
    Ui::GitAddDialog *ui;

};

#endif // GITADDDIALOG_H
