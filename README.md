
# Autonomous Arduino Obstacle-Avoiding Robot
An autonomous Arduino-based robot designed to navigate and avoid obstacles using ultrasonic sensors, servo motors, and the Adafruit Motor Shield. This project showcases the integration of sensors and intelligent decision-making in robotics.

## Overview
This project involves an autonomous robot built using Arduino, Adafruit Motor Shield, and various sensors. The robot is designed to navigate its environment independently, avoiding obstacles and making decisions based on sensor input. The project is an excellent example of integrating multiple hardware components with Arduino to create a functional and intelligent robotic system.

### Key Features
- **Obstacle Detection:** The robot uses an ultrasonic sensor to detect obstacles and navigate accordingly. The sensor provides real-time distance measurements, enabling the robot to make quick decisions to avoid collisions.
- **Servo Motor Control:** A servo motor is used to rotate the ultrasonic sensor, allowing the robot to scan its surroundings and make informed decisions based on a wider field of view.
- **Motor Control:** The robot is powered by four DC motors, controlled via the Adafruit Motor Shield, enabling smooth and responsive movements in all directions, including forward, backward, left, and right.
- **Intelligent Decision Making:** The robot can decide which direction to turn based on the distance measured by the ultrasonic sensor, ensuring efficient navigation and obstacle avoidance. The decision-making process is governed by a simple yet effective algorithm that compares distances and selects the optimal path.

## Components Used
- **Arduino Uno:** The brain of the robot, responsible for processing sensor data and controlling the motors.
- **Adafruit Motor Shield:** A motor driver shield that simplifies the connection and control of the DC motors.
- **Servo Motor:** Used to rotate the ultrasonic sensor, providing a dynamic range of obstacle detection.
- **Ultrasonic Sensor (HC-SR04):** Measures the distance to objects in front of the robot, enabling obstacle detection.
- **DC Motors:** Provide the movement for the robot, controlled via the motor shield.
- **Wheels and Chassis:** The physical structure of the robot, providing mobility and housing for all components.
- **Battery Pack:** Powers the Arduino and motors, ensuring the robot can operate autonomously without being tethered to an external power source.

## Code Explanation
The code provided controls the robot's movement and decision-making process. It uses the `Servo.h` library to control the servo motor and the `AFMotor.h` library for the DC motors. The robot scans its surroundings using an ultrasonic sensor and makes decisions to avoid obstacles by turning left or right.

### How it Works
1. **Initialization:** The servo motor is set to its center position, and the motors are initialized. This ensures that the robot starts in a known state and is ready to begin scanning its environment.
2. **Obstacle Detection:** The ultrasonic sensor continuously measures the distance to objects in front of the robot. If an object is detected within a predefined range, the robot stops to avoid a collision.
3. **Decision Making:** 
   - If an obstacle is detected, the robot stops and begins scanning to the left and right using the servo-mounted ultrasonic sensor.
   - The robot compares the distances measured in each direction.
   - Based on the comparison, the robot decides whether to turn left or right, selecting the direction with the most clearance.
4. **Movement:** Once a decision is made, the robot moves in the chosen direction to avoid the obstacle. If the path is clear, it continues moving forward.

## Setup Instructions
1. **Hardware Setup:**
   - Connect the DC motors to the Adafruit Motor Shield, ensuring that the motors are correctly wired to the appropriate terminals.
   - Attach the servo motor to the robot’s chassis and connect it to the designated PWM pin on the Arduino (typically pin 9).
   - Connect the ultrasonic sensor to the Arduino, with the Trigger pin connected to A0 and the Echo pin connected to A1.
   - Power the Arduino using a battery pack that is capable of providing sufficient current for both the Arduino and the motors.

2. **Software Setup:**
   - Install the `Servo.h` and `AFMotor.h` libraries in your Arduino IDE. These libraries provide the necessary functions to control the servo motor and the DC motors, respectively.
   - Upload the provided code to the Arduino Uno using the Arduino IDE. Ensure that the correct board and port are selected before uploading.

3. **Running the Robot:**
   - Place the robot on a flat surface free of obstacles to start.
   - Turn on the power and observe as it navigates its environment autonomously, avoiding obstacles and making decisions in real-time.
   - If needed, adjust the sensitivity of the obstacle detection by modifying the threshold distance in the code.

## Demo Video
For a quick demonstration of the robot in action, click on the image below to watch the YouTube Shorts video:

[![Autonomous Arduino Robot](https://img.youtube.com/vi/uUEYNIDuD2Q/0.jpg)](https://www.youtube.com/shorts/uUEYNIDuD2Q)

## Future Enhancements
- **Add More Sensors:** Implement additional sensors (e.g., infrared, camera) for better obstacle detection and decision-making. This will allow the robot to navigate more complex environments and improve its autonomy.
- **Improve Algorithm:** Enhance the decision-making algorithm to handle more complex environments, such as those with dynamic obstacles or narrow passages.
- **Remote Control:** Add Bluetooth or Wi-Fi capability for remote control and monitoring, allowing users to override autonomous decisions and manually control the robot when necessary.
- **Energy Efficiency:** Optimize the power consumption of the robot by implementing power-saving features when the robot is idle or not in motion.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing
Contributions are welcome! Please feel free to submit a Pull Request or open an Issue for any suggestions or improvements.
