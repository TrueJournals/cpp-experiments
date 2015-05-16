#include <iostream>

#include "DependsOnSingleton.h"

int main(int, char**) {
    DependsOnSingleton depender;
    depender.stupidRedirectSet(7);

    std::cout << "Value = " << depender.stupidRedirectGet() << std::endl;

    return 0;
}
