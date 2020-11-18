#include "spinboxdelegate.h"
#include <QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(QObject *parent):QItemDelegate(parent)
{

}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();
    QSpinBox* spinBox = static_cast<QSpinBox*>(editor); //转换数据类型
    spinBox->setValue(value);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //option.ret返回一个矩形
    editor->setGeometry(option.rect);
}
