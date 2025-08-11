#include <bits/stdc++.h>
#include "totem_manipulation_hardware_interface/plugin_base.hpp"
#include <pluginlib/class_list_macros.hpp>

namespace pkg_b {

class RobStride: public ActuatorInterface {
public:
  
  ~RobStride() override = default;

  std::vector<ActuatorResponse> read() override;

  void write(std::vector<ActuatorCommand> cmds) override;

  void init(std::string interface, std::vector<ActuatorSpec> actuator_spec) override;

  void stop() override;

  void set_zero(uint32_t id) override;

private:

  using ActuatorInterface::_num_actuators;

  uint32_t p_bus_id;

};

}
