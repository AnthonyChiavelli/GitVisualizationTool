#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include "ggraphicsscene.h"
#include "gitinitdialog.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionGitInit_triggered();

    void on_actionGitMerge_triggered();

    void on_actionGitAdd_triggered();

    void on_actionGitStatus_triggered();

    void on_actionGitCommit_triggered();

    void on_actionGitBranch_triggered();

    void on_actionGitRevert_triggered();

    void on_actionGit_Init_triggered();

    void on_actionGit_Add_triggered();

    void on_actionGit_Commit_triggered();

    void on_actionGit_Merge_triggered();

    void on_actionGit_Branch_triggered();

    void on_actionGit_Status_triggered();

    void on_actionCurrent_Version_triggered();

    void on_actionAbout_us_triggered();

    void on_actionGitHub_triggered();

    void on_actionBitBucket_triggered();

    void on_actionGit_Revert_triggered();

    void on_actionGitPush_triggered();

    void on_actionGitPull_triggered();

    void on_actionGit_Push_triggered();

    void on_actionGit_Pull_triggered();

    void on_actionRefresh_triggered();

    void on_UpdateButton_clicked();

    void on_actionOpenRepo_triggered();

  private:
    Ui::MainWindow *ui;
    GGraphicsScene *scene;

};

#endif // MAINWINDOW_H
