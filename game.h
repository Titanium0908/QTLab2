#ifndef GAME_H
#define GAME_H

#include "QString"
#include <QObject>

class Game: public QObject
{
    Q_OBJECT

public:
    Game(QString ID, QString Name, QString Genre, QString Company, QString Platform, QObject *parent = nullptr );
    virtual ~Game();
    void SetID(QString ID);
    void SetName(QString Name);
    void SetGenre(QString Genre);
    void SetCompany(QString Company);
    void SetPlatform(QString Platform);

    QString ID();
    QString Name();
    QString Genre();
    QString Company();
    QString Platform();
private:
    QString id;
    QString name;
    QString genre;
    QString company;
    QString platform;
};

#endif
