#include "pkg_a/plugin_base.hpp"
#include <pluginlib/class_list_macros.hpp>

namespace pkg_b {

class PluginImpl : public pkg_a::BaseInterface {
public:
    ~PluginImpl() override = default;

    int placeholder(int arg) override {
        // Implementation of the placeholder method
        return arg * 2; // Example implementation
    }
};

}

PLUGINLIB_EXPORT_CLASS(pkg_b::PluginImpl, pkg_a::BaseInterface)
