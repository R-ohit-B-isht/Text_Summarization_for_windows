#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QDir>
#include<QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <stdio.h>
#include <conio.h>
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_OpenFile_clicked();

    void on_btn_summrize_clicked();

private:
    Ui::Widget *ui;
    QString filePath;
};
#endif // WIDGET_H
