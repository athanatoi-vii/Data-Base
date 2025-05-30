#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QLayout>
#include <QRegExpValidator>
#include <QFont>

#include "C_L_LE_Add.h"

C_L_LE_Add::C_L_LE_Add(QWidget *parent) : QWidget(parent)
{
    L = new QLabel("", this);
    LE = new QLineEdit("", this);
    HL = new QHBoxLayout();

    LE->setStyleSheet("QLineEdit { border: 1px solid gray; border-radius: 2px; padding: 1px; }");
    LE->setPlaceholderText("...");
    QFont font = LE->font();
    font.setPointSize(10);
    LE->setFont(font);
    LE->setCursor(Qt::IBeamCursor);

    HL->addWidget(L);
    HL->addWidget(LE);

    this->setLayout(HL);
}

C_L_LE_Add::~C_L_LE_Add() {}

void C_L_LE_Add::Set_Text_L(QString S)
{
    L->setText(S);
}

void C_L_LE_Add::Set_Format_LE(QString S)
{
    LE->setValidator(new QRegExpValidator(QRegExp(S), this));
}

void C_L_LE_Add::Set_Text_LE(QString S)
{
    LE->setText(S);
}

bool C_L_LE_Add::Is_Empty()
{
    if (LE->text().isEmpty())
    {
        return true;
    }

    return false;
}

QString C_L_LE_Add::Get_Text_LE()
{
    return LE->text();
}
