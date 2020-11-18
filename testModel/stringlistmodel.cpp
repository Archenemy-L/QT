#include "stringlistmodel.h"


int StringListModel::rowCount(const QModelIndex &parent) const
{
    return m_stringList.count();
}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row() == m_stringList.size())
    {
        return  QVariant();
    }
    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return m_stringList.at(index.row());
    }
    else
    {
        return QVariant();
    }
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    //水平表头
    if(orientation == Qt::Horizontal)
        return QString("Columm %1").arg(section);
    else
        return  QString("Row %1").arg(section);



}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
     if(!index.isValid())
         return Qt::ItemIsEnabled;
     return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //检查索引有效且项目可编辑
    if(index.isValid() && role == Qt::EditRole)
    {
        m_stringList.replace(index.row(),value.toString());
        emit dataChanged(index,index);  //数据改变时发送数据变更信号
        return true;
    }
    return false;
}

bool StringListModel::insertRows(int position, int rows, const QModelIndex &index)
{
    //告知别的组件开始进行插入
    beginInsertRows(QModelIndex(),position,position + rows - 1);
    for(int row = 0;row < rows ; ++row)
    {
        m_stringList.insert(position,QString("我干"));
    }
    //告知其他组件完成插入
    endInsertRows();
    return true;

}

bool StringListModel::removeRows(int position, int rows, const QModelIndex &index)
{
    //告知别的组件开始删除
    beginRemoveRows(QModelIndex(),position,position + rows - 1);
    for(int row = 0;row < rows ; ++row)
    {
        m_stringList.removeAt(position);
    }
    //告知别的组件结束删除
    endRemoveRows();
    return true;
}
