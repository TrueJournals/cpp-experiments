#pragma once

#include <memory>

class TestPlugin;
class TestState;

extern "C" std::shared_ptr<TestPlugin> load(TestState* state);
