#include "editgamedialog.h"
#include "game.h"
EditGameDialog::EditGameDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editGenre = new QLineEdit();
    editCompany = new QLineEdit();
    editPlatform = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Жанр"),3,1);
    mainLayout->addWidget(editGenre,3,2);
    mainLayout->addWidget(new QLabel("Компания"),4,1);
    mainLayout->addWidget(editCompany,4,2);
    mainLayout->addWidget(new QLabel("Платформа"),5,1);
    mainLayout->addWidget(editPlatform,5,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,6,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о игре");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditGameDialog::id() const
{
    return editID->text();
}
QString EditGameDialog::name() const
{
    return editName->text();
}
QString EditGameDialog::genre() const
{
    return editGenre->text();
}
QString EditGameDialog::company() const
{
    return editCompany->text();
}
QString EditGameDialog::platform() const
{
    return editPlatform->text();
}

void EditGameDialog::SetUpDialog(QString id, QString name, QString genre, QString company, QString platform)
{
    editID->setText(id);
    editName->setText(name);
    editGenre->setText(genre);
    editCompany->setText(company);
    editPlatform->setText(platform);
}
