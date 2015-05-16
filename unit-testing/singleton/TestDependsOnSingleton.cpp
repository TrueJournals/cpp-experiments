#include "gtest/gtest.h"
#include "DependsOnSingleton.h"
#include "MockMySingleton.h"

TEST(DependencyTest, CanSetMemberVariable) {
    SingletonAbstraction singleton { };
    SingletonAbstraction::abstraction = &singleton;

    DependsOnSingleton dos { };

    EXPECT_CALL(singleton, setMemberVariable(7))
        .Times(1);

    dos.stupidRedirectSet(7);
}

TEST(DependencyTest, CanGetMemberVariable) {
    SingletonAbstraction singleton { };
    SingletonAbstraction::abstraction = &singleton;

    DependsOnSingleton dos { };

    std::vector<int> test_conditions = {
        std::numeric_limits<int>::min(),
        std::numeric_limits<int>::max(),
        0, 10, -8
    };

    for (const auto& condition : test_conditions) {
        EXPECT_CALL(singleton, setMemberVariable(condition))
            .Times(1);
        EXPECT_CALL(singleton, getMemberVariable())
            .WillOnce(::testing::Return(condition));

        dos.stupidRedirectSet(condition);
        EXPECT_EQ(condition, dos.stupidRedirectGet());
    }
}
