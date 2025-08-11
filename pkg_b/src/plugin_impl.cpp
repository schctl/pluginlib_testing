#include "pkg_b/driver.hpp"

namespace pkg_b {

std::vector<ActuatorResponse> RobStride::read() {
  std::cout << "read was called from robstride" << std::endl;
  return {};
}

void RobStride::write(std::vector<ActuatorCommand> cmds) {
  std::cout << "write was called from robstride" << std::endl;
}

void RobStride::init(std::string interface, std::vector<ActuatorSpec> actuator_spec) {
  std::cout << "init was called from robstride" << std::endl;
}

void RobStride::stop() {
  std::cout << "stop was called from robstride" << std::endl;
}

void RobStride::set_zero(uint32_t id) {
  std::cout << "set_zero was called from robstride" << std::endl;
}

}

PLUGINLIB_EXPORT_CLASS(pkg_b::RobStride, ActuatorInterface)
