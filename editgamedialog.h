#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "game.h"

class EditGameDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editName;
    QLineEdit* editGenre;
    QLineEdit* editCompany;
    QLineEdit* editPlatform;

public:
    EditGameDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString genre() const;
    QString company() const;
    QString platform() const;

    void SetUpDialog(QString id, QString name, QString genre, QString company, QString platform);
};

#endif // INPUTDIALOG_H
