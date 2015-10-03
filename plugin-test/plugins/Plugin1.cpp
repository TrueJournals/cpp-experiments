#include "../interface.hpp"
#include "../TestPlugin.hpp"

class Plugin1 : public TestPlugin {
public:
    using TestPlugin::TestPlugin;
    virtual ~Plugin1() = default;

    virtual std::string get_name() override { return "Plugin1"; }
    virtual unsigned int calc(unsigned int input) override { return input * 2; }
};

extern "C" std::shared_ptr<TestPlugin> load(TestState* state)
{
    return std::make_shared<Plugin1>(state);
}
