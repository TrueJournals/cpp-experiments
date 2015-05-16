#include "DependsOnSingleton.h"

#include "MySingleton.h"

void DependsOnSingleton::stupidRedirectSet(int value) {
    MySingleton::instance().setMemberVariable(value);
}

int DependsOnSingleton::stupidRedirectGet() const {
    return MySingleton::instance().getMemberVariable();
}
