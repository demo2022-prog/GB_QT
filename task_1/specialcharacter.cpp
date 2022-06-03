#include "specialcharacter.h"

SpecialCharacter::SpecialCharacter(QObject* parent) : QObject(parent) {

}

void SpecialCharacter::specialCharacter(QString &input)
{
    input.replace(QString("@авторское право@"),QString("©"));

    input.replace(QString("@промилле@"),QString("‰"));

    input.replace(QString("@товарный знак@"),QString("®"));

    input.replace(QString("@EURO@"),QString("€"));

    input.replace(QString("@RUB@"),QString("₽"));

}
