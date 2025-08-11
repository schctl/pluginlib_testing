#include <pluginlib/class_loader.hpp>
#include "totem_manipulation_hardware_interface/plugin_base.hpp"

int main(int argc, char** argv)
{
  // To avoid unused parameter warnings
  (void) argc;
  (void) argv;

  pluginlib::ClassLoader<ActuatorInterface> plugin_loader("pkg_a", "ActuatorInterface");

  try
  {
    std::shared_ptr<ActuatorInterface> driver = plugin_loader.createSharedInstance("pkg_b::RobStride");
    driver->stop();
  }
  catch(pluginlib::PluginlibException& ex)
  {
    printf("The plugin failed to load for some reason. Error: %s\n", ex.what());
  }

  return 0;
}
