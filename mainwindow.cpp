#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tiger.c"
#include "stdio.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    word64 buffer[65536];
    word64 res[3];
    int i;

    for (i=0;i<65536;i++)
      buffer[i] = i&0xFF;

    tiger(buffer, 65536, res);
////    qDebug(QString("%1").arg((long)res).toAscii());
//    printf("Hash of a 64K-byte string:\n\t%08X%08X %08X%08X %08X%08X\n",
//           (word32)(res[0]>>32),
//           (word32)(res[0]),
//           (word32)(res[1]>>32),
//           (word32)(res[1]),
//           (word32)(res[2]>>32),
//           (word32)(res[2]) );

//    tiger((word64*)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-", strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-"), res);

    QString str;
         str = QString("Hash of a 64K-byte string:\n\t%1%2 %3%4 %5%6\n")
            .arg((word32)(res[0]>>32),0,16)
            .arg((word32)res[0],0,16)
            .arg((word32)(res[1]>>32),0,16)
            .arg((word32)res[1],0,16)
            .arg((word32)(res[2]>>32),0,16)
            .arg((word32)res[2],0,16);

         str = QString("Hash of a 64K-byte string:\n\t%1 %2 %3\n")

            .arg(res[0],0,16)

            .arg(res[1],0,16)

            .arg(res[2],0,16);

         qDebug(str.toAscii());
}

MainWindow::~MainWindow()
{
    delete ui;
}
