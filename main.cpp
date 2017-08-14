#include "dialog.h"
#include "node.h"
#include <QApplication>



int main(int argc, char *argv[])
{

  struct node *root=NULL;


root=insert(root,19);

  QApplication a(argc, argv);
  Dialog w;
  w.start=root;
  w.width=10;
   w.level=500;
   w.h=70;

  w.showFullScreen();



   return a.exec();

}
