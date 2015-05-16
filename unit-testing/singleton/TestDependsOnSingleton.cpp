#include "gtest/gtest.h"
#include "DependsOnSingleton.h"
#include "MockMySingleton.h"

TEST(DependencyTest, CanSetMemberVariable) {
    SingletonAbstraction singleton { };
    SingletonAbstraction::abstraction = &singleton;

    DependsOnSingleton dos { };

    EXPECT_CALL(singleton, setMemberVariable(8))
        .Times(1);

    dos.stupidRedirectSet(7);
}
