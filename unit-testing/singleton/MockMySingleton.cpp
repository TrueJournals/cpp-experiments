#include "gmock/gmock.h"
#include "MockMySingleton.h"
#include "MySingleton.h"

std::shared_ptr<MySingleton> MySingleton::instance_p { nullptr };
SingletonAbstraction* SingletonAbstraction::abstraction { nullptr };

void MySingleton::setMemberVariable(int value) {
    return SingletonAbstraction::abstraction->setMemberVariable(value);
}

int MySingleton::getMemberVariable() const {
    return SingletonAbstraction::abstraction->getMemberVariable();
}
