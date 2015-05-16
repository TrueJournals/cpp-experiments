#pragma once
#include <memory>

class MySingleton {
public:
    static MySingleton& instance() {
        return instance_p ? *instance_p : *(instance_p = std::shared_ptr<MySingleton>(new MySingleton()));
    }

    void setMemberVariable(int value);
    int getMemberVariable() const;

private:
    static std::shared_ptr<MySingleton> instance_p;

    MySingleton() = default;
    MySingleton(const MySingleton& o) = default;

    int member_variable { 0 };
};
