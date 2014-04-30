#include "gitmergedialog.h"
#include "ui_gitmergedialog.h"

GitMergeDialog::GitMergeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::GitMergeDialog)
{
  ui->setupUi(this);
}

GitMergeDialog::~GitMergeDialog()
{
  delete ui;
}

void GitMergeDialog::on_mergeButton_clicked()
{

}

void GitMergeDialog::on_cancelButton_clicked()
{

}
