#ifndef SPECIALCHARACTER_H
#define SPECIALCHARACTER_H

#include <QtCore/QObject>
#include <QString>

class SpecialCharacter : public QObject {
    Q_OBJECT

public:
    SpecialCharacter(QObject* parent = nullptr);

    void specialCharacter(QString&);
};

#endif // SPECIALCHARACTER_H
