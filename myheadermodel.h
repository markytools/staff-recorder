#ifndef MYHEADERMODEL_H
#define MYHEADERMODEL_H
#include <QAbstractItemModel>

class MyHeaderModel : public QAbstractItemModel
{
public:
    MyHeaderModel(QObject *parent = 0);
        int columnCount(const QModelIndex &parent = QModelIndex()) const { return 2; }
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const { return QVariant(); }
        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const { return QModelIndex(); }
        QModelIndex parent(const QModelIndex &index) const { return QModelIndex(); }
        int rowCount(const QModelIndex &parent = QModelIndex()) const { return 0; }
};

#endif // MYHEADERMODEL_H
