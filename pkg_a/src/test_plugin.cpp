#include <pluginlib/class_loader.hpp>
#include "pkg_a/plugin_base.hpp"

int main(int argc, char** argv)
{
  // To avoid unused parameter warnings
  (void) argc;
  (void) argv;

  pluginlib::ClassLoader<pkg_a::BaseInterface> plugin_loader("pkg_a", "pkg_a::BaseInterface");

  try
  {
    std::shared_ptr<pkg_a::BaseInterface> driver = plugin_loader.createSharedInstance("pkg_b::PluginImpl");
  }
  catch(pluginlib::PluginlibException& ex)
  {
    printf("The plugin failed to load for some reason. Error: %s\n", ex.what());
  }

  return 0;
}
