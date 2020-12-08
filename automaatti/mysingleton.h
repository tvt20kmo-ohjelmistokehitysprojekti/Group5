#ifndef MYSINGLETON_H
#define MYSINGLETON_H
#include <qstring.h>

class MySingleton
{
private:
    static MySingleton* instance;
    QString cardID;
public:
    static MySingleton* getInstance();

    QString getCardID() const;
    void setCardID(const QString &value);
};

#endif // MYSINGLETON_H
