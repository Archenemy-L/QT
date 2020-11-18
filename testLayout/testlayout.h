#ifndef TESTLAYOUT_H
#define TESTLAYOUT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TestLayout; }
QT_END_NAMESPACE

class TestLayout : public QWidget
{
    Q_OBJECT

public:
    TestLayout(QWidget *parent = nullptr);
    ~TestLayout();

private:
    Ui::TestLayout *ui;
};
#endif // TESTLAYOUT_H
