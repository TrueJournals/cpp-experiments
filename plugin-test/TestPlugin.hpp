#pragma once

#include <string>

class TestState;

class TestPlugin {
public:
    TestPlugin(TestState* state);
    virtual ~TestPlugin();

    virtual std::string get_name() = 0;
    virtual unsigned int calc(unsigned int input) = 0;
protected:
    TestState* state;
};
