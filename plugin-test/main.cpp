#include <iostream>
#include <memory>
#include <regex>
#include <vector>

#include <dlfcn.h>

#include <boost/filesystem.hpp>

#include "interface.hpp"
#include "TestPlugin.hpp"

class TestState { };

auto dlcloser = [](void* handle) { dlclose(handle); };
typedef std::vector<std::pair<std::unique_ptr<void, decltype(dlcloser)>, std::shared_ptr<TestPlugin>>> Plugins;
/* typedef std::vector<std::pair<std::shared_ptr<TestPlugin>, std::unique_ptr<void, decltype(dlcloser)>>> Plugins; */

void load_plugin(const std::string& filename, Plugins& plugins, TestState* state)
{
    std::unique_ptr<void, decltype(dlcloser)> handle(dlopen(filename.c_str(), RTLD_LAZY), dlcloser);
    if (!handle) {
        // TODO: Throw exception
        std::cerr << "Couldn't open " << filename << std::endl;
        return;
    }

    typedef std::shared_ptr<TestPlugin> (*plugin_loader)(TestState*);
    plugin_loader loader = reinterpret_cast<plugin_loader>(dlsym(handle.get(), "load"));
    char* error;
    if ((error = dlerror()) != NULL) {
        // TODO: Throw exception
        std::cerr << error << std::endl;
        return;
    }

    plugins.push_back({std::move(handle), loader(state)});
    /* plugins.push_back({loader(state), std::move(handle)}); */
}

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    TestState state;
    Plugins plugins;

    boost::filesystem::path current_dir(".");
    if (boost::filesystem::exists(current_dir) && boost::filesystem::is_directory(current_dir))
    {
        for (boost::filesystem::directory_iterator item(current_dir); item != boost::filesystem::directory_iterator(); ++item)
        {
            if (boost::filesystem::is_regular_file(item->status()))
            {
                std::regex plugin_match("./lib[A-Za-z0-9_]+\\.so");
                if (std::regex_match(item->path().string(), plugin_match))
                {
                    std::cout << "Loading " << item->path() << std::endl;
                    load_plugin(item->path().string(), plugins, &state);
                }
            }
        }
    }

    for (const auto& plugin : plugins)
    {
        std::cout << "Plugin: " << plugin.second->get_name() << std::endl;
        std::cout << "\t" << plugin.second->calc(100) << std::endl;
        /* std::cout << "Plugin: " << plugin.first->get_name() << std::endl; */
        /* std::cout << "\t" << plugin.first->calc(100) << std::endl; */
    }

    return 0;
}
