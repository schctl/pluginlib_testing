#ifndef PLUGUN_BASE_HPP
#define PLUGIN_BASE_HPP

/**
 * @brief Command parameters to a generic actuator.
 */
typedef struct {
  uint32_t id;
  std::string bus;
  uint8_t mode;
  double position;            // rad
  double velocity;            // rad/sec
  double feedforward_torque;  // Nm
  double kp_scale;
  double kd_scale;
  double watchdog_timeout;    // sec
  double maximum_torque;      // Nm
  double velocity_limit;      // rad/sec
  double stop_position;       // rad
} ActuatorCommand;

/**
 * @brief Feedback received from a generic actuator.
 */
typedef struct {
  uint32_t id;
  uint8_t mode;
  int8_t fault;
  double position;            // rad
  double velocity;            // rad/sec
  double torque;              // Nm
  double voltage;             // V
  double current;             // A
  double temperature;         // deg C
} ActuatorResponse;

/**
 * @brief Actuator specification, used for initialization.
 */
typedef struct {
  uint32_t id;
  uint16_t kind;
} ActuatorSpec;

class ActuatorInterface {
public:
  /// @brief Virtual destructor.
  virtual ~ActuatorInterface() = default;

  /// @brief Get feedback from available actuators.
  virtual std::vector<ActuatorResponse> read() = 0;

  /// @brief Write commands to specified actuators.
  virtual void write(std::vector<ActuatorCommand> cmds) = 0;

  /**
   * @brief Resource initializer.
   * 
   * This method should be called when the driver is ready to be used.
   * 
   * The requested interface will be claimed, and specified actuators will be configured.
   */
  virtual void init(std::string interface, std::vector<ActuatorSpec> actuators) = 0;

  /// @brief Stop all actuators.
  virtual void stop() = 0;

  /**
   * @brief Set mechanical zero of the requested actuator.
   * 
   * Will set the zero position of the actuator to its current position.
   */
  virtual void set_zero(uint32_t id) = 0;

protected:
  /// @brief Number of actuators managed by this interface.
  int _num_actuators;
};


#endif
