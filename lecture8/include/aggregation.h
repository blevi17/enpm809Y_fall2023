#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "sensor.h"

/**
 * @brief Namespace for the maze navigation project
 *
 */
namespace MazeNavigation {
/**
 * @brief Class for the mobile robot
 *
 */
class MobileRobot {
 private:
  // Attributes
  //<! position of the robot
  std::pair<double, double> position_;
  //<! orientation of the robot (in rad)
  double orientation_;
  //<! speed of the robot
  double speed_{0};
  //<! list of sensors for the robot
  std::vector<std::unique_ptr<MazeNavigation::Sensor>> sensors_;

 public:
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  MobileRobot() : MobileRobot(0, 0, 0) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */

  MobileRobot(double orientation) : MobileRobot(0, 0, orientation) {}
  /**
   * @brief Construct a new Mobile Robot object
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   */
  MobileRobot(double x, double y) : MobileRobot(x, y, 0) {}
  
  /**
   * @brief Construct a new Mobile Robot object
   * @note This is a delegating constructor
   * - first argument: x position
   * - second argument: y position
   * - third argument: orientation
   * - fourth argument: battery charge
   */
  MobileRobot(double x, double y, double orientation)
      : position_{x, y},
        orientation_{orientation} {}

  // ==================== accessors ====================
  /**
   * @brief Get the position of the robot
   *
   * @return std::pair<double, double>
   */
  std::pair<double, double> get_position() const { return position_; }
  /**
   * @brief Get the orientation of the robot
   *
   * @return double
   */
  double get_orientation() const { return orientation_; }
  /**
   * @brief Get the speed of the robot
   *
   * @return double
   */
  double get_speed() const { return speed_; }


  // ==================== methods ====================
  /**
   * @brief Move the robot forward by a given distance
   *
   * @param distance distance to move
   */
  void move_forward(double distance);
  /**
   * @brief Move the robot backward by a given distance
   *
   * @param distance distance to move
   */
  void move_backward(double distance);
  /**
   * @brief Rotate the robot by a given angle
   *
   * @param angle angle to rotate (in degrees)
   */
  void rotate(double angle);

  /**
   * @brief Add a sensor to the robot
   *
   * @param sensor sensor to add
   */
  void add_sensor(std::unique_ptr<MazeNavigation::Sensor> sensor);

  /**
   * @brief Get the sensor reading
   * @param period period of the sensor reading
   * @return double
   */
  double get_sensor_reading(int period) const;
};  // class MobileRobot
}  // namespace MazeNavigation
