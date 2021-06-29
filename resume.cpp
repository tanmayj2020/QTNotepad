#include "resume.h"
#include "ui_resume.h"
#include<Qpixmap>
Resume::Resume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resume)
{
    ui->setupUi(this);
    QPixmap pix(":/resume/tanmay_resume.jpg");
    ui->label->setScaledContents(true);

    ui->label->setPixmap(pix);



}

Resume::~Resume()
{
    delete ui;
}
