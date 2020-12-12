#include "mysingleton.h"

MySingleton* MySingleton::instance = nullptr;

MySingleton* MySingleton::getInstance() {
    if (instance == nullptr) {
        instance = new MySingleton();
    }
    return instance;
}

QString MySingleton::getCardID() const {
    return cardID;
}

void MySingleton::setCardID(const QString &value) {
    cardID = value;
}

QString MySingleton::getAccount() const {
    return Account;
}

void MySingleton::setAccount(const QString &value) {
    Account = value;
}
