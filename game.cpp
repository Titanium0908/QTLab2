#include "game.h"

Game::Game(QString ID, QString Name, QString Genre, QString Company, QString Platform, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    genre = Genre;
    company = Company;
    platform = Platform;
}

void Game::SetID(QString ID)
{
    id = ID;
}
void Game::SetName(QString Name)
{
    name = Name;
}
void Game::SetGenre(QString Genre)
{
    genre = Genre;
}
void Game::SetCompany(QString Company)
{
    company = Company;
}
void Game::SetPlatform(QString Platform)
{
    platform = Platform;
}
QString Game::ID()
{
    return id;
}
QString Game::Name()
{
    return name;
}
QString Game::Genre()
{
    return genre;
}
QString Game::Company()
{
    return company;
}
QString Game::Platform()
{
    return platform;
}
 Game::~Game()
{
}
