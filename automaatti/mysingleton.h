#ifndef MYSINGLETON_H
#define MYSINGLETON_H
#include <qstring.h>

class MySingleton
{
private:
    static MySingleton* instance;
    QString cardID;
    QString Account;
public:
    static MySingleton* getInstance();

    QString getCardID() const;
    void setCardID(const QString &value);

    QString getAccount() const;
    void setAccount(const QString &value);
};

#endif // MYSINGLETON_H
