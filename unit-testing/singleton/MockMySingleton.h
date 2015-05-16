#pragma once
#include "gmock/gmock.h"
#include <memory>

class SingletonAbstraction {
public:
    static SingletonAbstraction* abstraction;
    SingletonAbstraction() = default;
    virtual ~SingletonAbstraction() = default;

    MOCK_METHOD1(setMemberVariable, void(int));
    MOCK_CONST_METHOD0(getMemberVariable, int());
};
