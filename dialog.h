#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <qmath.h>
#include "node.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    struct node *start;
    int width;
    int h;
    int level;

    ~Dialog();

private:
    Ui::Dialog *ui;



protected:
     void  paintEvent(QPaintEvent *e);
     void  paintEvent2(struct node *first, int rightadj, int height);




private slots:

     void on_pushButton_clicked();
     void on_pushButton_2_clicked();
     void on_pushButton_3_clicked();
     void on_pushButton_4_clicked();
};

#endif // DIALOG_H
