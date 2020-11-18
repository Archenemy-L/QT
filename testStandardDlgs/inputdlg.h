#ifndef INPUTDLG_H
#define INPUTDLG_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class InputDlg : public QDialog
{
    Q_OBJECT
public:
    InputDlg(QWidget* parent = 0);
    ~InputDlg();

private:
    QLabel* m_nameTitle;
    QLabel* m_ageTitle;
    QLabel* m_sexTitle;
    QLabel* m_scoreTitle;

    QLabel* m_nameLabel;
    QLabel* m_ageLabel;
    QLabel* m_sexLabel;
    QLabel* m_scoreLabel;

    QPushButton* m_nameBtn;
    QPushButton* m_ageBtn;
    QPushButton* m_sexBtn;
    QPushButton* m_scoreBtn;

    QGridLayout* m_mainLayout;      //布局管理器


private slots:
    void setName();
    void setSex();
    void setAge();
    void setScore();

};

#endif // INPUTDLG_H
