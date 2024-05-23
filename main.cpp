//#include "MainWindow.h"
//#include "db_pool.h"
#include "LoginWindow.h"

int main(int argc, char *argv[])
{
    //DbPool* pool = new DbPool(5);
    //result res = pool->runQuery("SELECT * FROM users");
    QApplication a(argc, argv);
   /* MainWindow w;
    w.show();*/
    LoginWindow lW;
    lW.showMaximized();
    return a.exec();
}
