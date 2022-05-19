#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <cstring>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_OpenFile_clicked()
{
    QString temp=QFileDialog::getOpenFileName(this,"Open Text file to summarize",QString(),"Text Files (*txt)");
    if(temp.isEmpty()) return;
    filePath=temp;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }
    QTextStream stream(&file);
    ui->InsertText->setText(stream.readAll());
    ui->filePath->setText(temp);
    file.close();
}


void Widget::on_btn_summrize_clicked()
{
    QDir dir("input.txt");

    QFile file(dir.absolutePath());
    if(!file.open(QIODevice::OpenModeFlag::WriteOnly|QIODeviceBase::Truncate)){
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }
        QString a=dir.absolutePath();
    QString x=ui->InsertText->toPlainText();
    file.write(QByteArray(x.toUtf8()));
    file.flush();
    file.close();


    QDir dirww("output.txt");
    QFile fileww(dirww.absolutePath());
    if(!fileww.open(QIODevice::OpenModeFlag::WriteOnly)){
        QMessageBox::critical(this,"Error",fileww.errorString());
        return;
    }
            QString b=dirww.absolutePath();
    fileww.close();


    //------------------------------------------------------------------
    QDir dirqrc(":/untitled.py");
    QFile fileqrc(dirqrc.absolutePath());
    if(!fileqrc.open(QIODevice::OpenModeFlag::ReadOnly)){
        QMessageBox::critical(this,"Error",fileqrc.errorString());
        return;
    }
    fileqrc.seek(0);
    QString cp=fileqrc.readAll();
    fileqrc.close();


    QDir dirxx("untitled1.py");
    QFile filexx(dirxx.absolutePath());
    if(!filexx.open(QIODevice::OpenModeFlag::WriteOnly|QIODevice::Truncate)){
        QMessageBox::critical(this,"Error",filexx.errorString());
        return;
    }
    filexx.write(QByteArray(cp.toUtf8()));
    filexx.close();
    //------------------------------------------------------------------------




        QDir dirpy("untitled1.py");
    std::string pi=dirpy.absolutePath().toStdString()+" "+a.toStdString()+" "+b.toStdString();
    int result = system(pi.c_str());
    qInfo()<<result;


    QDir dir2("output.txt");
    QFile file2(dir2.absolutePath());
    if(!file2.open(QIODevice::OpenModeFlag::ReadOnly)){
        QMessageBox::critical(this,"Error",file2.errorString());
        return;
    }
    file2.seek(0);
    QString x2=file2.readAll();
    file2.close();
    ui->SummrizeText->setText(x2);
}

