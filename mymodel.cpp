#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Game* std1 = new Game("1","GTA 5"," action-adventure","Rockstar","PC,PlayStation 4",this);
    Game* std2 = new Game("2","Elden Ring"," action/RPG","From Software","PlayStation 4, Xbox Series X|S, Xbox One, PlayStation 5, Windows",this);
    Game* std3 = new Game("3","Hollow Knight","метроидвания","Team Cherry","Windows, macOS, Linux, Nintendo Switch, Xbox One, PS4",this);
    AddGame(std1);
    AddGame(std2);
    AddGame(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return games.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 5;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Game* std = games.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Name();}
        else if (index.column() == 2){Value = std->Genre();}
        else if (index.column() == 3){Value = std->Company();}
        else if (index.column() == 4){Value = std->Platform();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Жанр");
            case 3:
                return QString("Компания");
            case 4:
                return QString("Платформа");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Game* std = games.at(index.row());
        if (index.column() == 0){std->SetName(value.toString());}
        else if (index.column() == 1){std->SetName(value.toString());}
        else if (index.column() == 2){std->SetGenre(value.toString());}
        else if (index.column() == 3){std->SetCompany(value.toString());}
        else if (index.column() == 4){std->SetPlatform(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddGame(Game* game)
{
    beginInsertRows(QModelIndex(),games.size(),games.size());
    games.append(game);
    endInsertRows();
    //emit layoutChanged();
}

void MyModel::DeleteGame(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    games.removeAt(row);
    endRemoveRows();
    //emit layoutChanged();
}

