#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::paintEvent(QPaintEvent *e)
{
    if(start==NULL)
    {
    QPainter painter2(this);
    painter2.drawText(50,400,"Tree is empty");
    }
    else
    {
    int height=start->height;
    paintEvent2(start,0, height);
    }
}

void Dialog::paintEvent2(struct node *first, int rightadj, int height)
{
    QString s;
    QPainter painter(this);
    QPoint polozenie;

    if (first!=NULL)
    {
    s = QString::number(first->key);
    polozenie.setX(qPow(2, height)*width+(rightadj/qPow(2,height)*width)*qPow(2, height+1));
    polozenie.setY(level-height*h);
    painter.drawText(polozenie, s);


    if(first->left)
    {
    painter.drawLine(polozenie.x()+5,polozenie.y()+5, qPow(2, height-1)*width+(rightadj/qPow(2,height-1)*width)*qPow(2, height)+5,polozenie.y()+h-10);
    }

    if(first->right)
    {
    painter.drawLine(polozenie.x()+5,polozenie.y()+5, qPow(2, height-1)*width+((rightadj+qPow(2,height-1))/qPow(2,height-1)*width)*qPow(2, height),polozenie.y()+h-10);
    }




    paintEvent2(first->left, rightadj, height-1);
    paintEvent2(first->right, rightadj+qPow(2,height-1), height-1);}


    }




void Dialog::on_pushButton_clicked()
{
    QString text;
    text=ui->lineEdit->text();
    int number;
    number=text.toInt();
    if(number!=0){
    start=insert(start, text.toInt() );

    repaint();}
}

void Dialog::on_pushButton_2_clicked()
{
    QString text;
    text=ui->lineEdit->text();
    int number;
    number=text.toInt();
    if(number>0){
    width=number;

    repaint();}
}

void Dialog::on_pushButton_3_clicked()
{
    QString text;
    text=ui->lineEdit->text();
    int number;
    number=text.toInt();
    if(number>0){
    h=number;

    repaint();}
}

void Dialog::on_pushButton_4_clicked()
{
    QString text;
    text=ui->lineEdit->text();
    int number;
    number=text.toInt();
    if(number>0){
    level=number;

    repaint();}
}
