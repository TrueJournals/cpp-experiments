#include "MySingleton.h"

std::shared_ptr<MySingleton> MySingleton::instance_p { nullptr };

void MySingleton::setMemberVariable(int value) {
    member_variable = value;
}

int MySingleton::getMemberVariable() const {
    return member_variable;
}
