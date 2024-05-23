#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   // CreateConnection();

}



//bool MainWindow::CreateConnection() {
    //std::string connectionString = "host=localhost port=5432 dbname=TerraCRM user=postgres password =1234";
    //try
    //{
    //    pqxx::connection connectionObject(connectionString.c_str());

    //    pqxx::work worker(connectionObject);

    //    pqxx::result response = worker.exec("SELECT * FROM users");

    //    for (auto const& rows : response)
    //    {
    //        for (auto const& field : rows) {
    //            qDebug() << field.c_str() << '\t';
    //            std::cout << std::endl;
    //        }
    //    }
    //    
    //    return true;

    //}
    //catch (const std::exception& e)
    //{
    //    return false;
    //    qDebug() << e.what();
    //}
//}
MainWindow::~MainWindow()
{}
