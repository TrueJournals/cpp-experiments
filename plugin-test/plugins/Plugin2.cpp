#include "../interface.hpp"
#include "../TestPlugin.hpp"

class Plugin2 : public TestPlugin {
public:
    using TestPlugin::TestPlugin;
    virtual ~Plugin2() = default;

    virtual std::string get_name() override { return "Plugin2"; }
    virtual unsigned int calc(unsigned int input) override { return input / 2; }
};

extern "C" std::shared_ptr<TestPlugin> load(TestState* state)
{
    return std::make_shared<Plugin2>(state);
}
