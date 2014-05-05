#include <QDesktopServices>
#include <QUrl>
#include "signup.h"
#include "signin.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}


void SignUp::on_pushButton_clicked()
{
    QUrl join("https://www.github.com/join", QUrl::TolerantMode);
    bool open = QDesktopServices::openUrl(join);
    if(open) {
        this->close();
    } else {
        //ERROR MESSAGE;
    }
}

void SignUp::on_pushButton_2_clicked()
{
    this->close();
    SignIn signin;
    Qt::WindowFlags flags = signin.windowFlags();
    signin.setWindowFlags(flags ^ Qt::WindowStaysOnTopHint);
    signin.exec();
}

void SignUp::on_pushButton_3_clicked()
{
    this->close();
}
