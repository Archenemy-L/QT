#include <QApplication>
#include "weaponmodel.h"
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    WeaponModel model;
    QTableView view;
    view.setModel(&model);
    view.setWindowTitle(QString("自定义模型"));
    view.resize(600,400);
    view.show();

    return app.exec();
}
