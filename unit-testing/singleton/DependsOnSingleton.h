#pragma once

class DependsOnSingleton {
public:
    DependsOnSingleton() = default;
    virtual ~DependsOnSingleton() = default;

    void stupidRedirectSet(int value);
    int stupidRedirectGet() const;
};
