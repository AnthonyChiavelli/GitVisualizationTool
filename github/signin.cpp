#include "signin.h"
#include "ui_signin.h"
#include "githubwebapi.h"
#include <iostream>

using namespace std;
SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    ui->label_3->setHidden(true);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_buttonBox_rejected()
{
    this->close();
}

void SignIn::on_buttonBox_accepted()
{
    SignIn::on_lineEdit_returnPressed();
}

void SignIn::on_lineEdit_returnPressed()
{
   string usr = ui->lineEdit->text().toStdString();
   string pass = ui->lineEdit_2->text().toStdString();
   char * user = new char[usr.size()+1];
   char * passw = new char[usr.size()+1];
   copy(usr.begin(), usr.end(), user);
   copy(pass.begin(), pass.end(), passw);
   user[usr.size()] = '\0';
   passw[pass.size()] = '\0';
   GitUser* you;
   if( !(you = GitHubWebApi::validUser(user, passw))){
       ui->label_3->setHidden(false);
    } else {
       this->close();
       MainWindow::setGitHubView(true);
   }
}

void SignIn::on_lineEdit_2_returnPressed()
{
    SignIn::on_lineEdit_returnPressed();
}


