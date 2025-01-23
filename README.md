
# SpotterSense - Parking Spot Availability Monitor

<img width="600" alt="image (12)" src="https://github.com/user-attachments/assets/c7dda268-8aaa-45e9-bc53-696b0145f5cf" />

## Project Overview
SpotterSense is an intelligent parking lot monitoring system designed to provide real-time parking spot availability using Arduinos, ultrasonic sensors, and Bluetooth communication. This system, coded in C++, detects whether parking spots are occupied or vacant and displays the real-time availability on an LCD panel. The project aims to simplify the parking process by helping drivers quickly locate available spots, thus saving time and reducing frustration.

## Built By
- **Javid Uddin**  
- **Jason Liang**

## Key Features
- **Real-time Parking Spot Availability**: The system updates the status of parking spots continuously, displaying whether each spot is occupied or vacant.
- **Bluetooth Communication**: Arduinos use Bluetooth to transmit data, enabling wireless communication and reducing installation complexity.
- **User-friendly Interface**: The central Arduino displays the availability of parking spots on an LCD panel, making it easy for both drivers and parking lot staff to access the data.

## System Design
1. **Parking Spot Sensors**: Each sensor-equipped Arduino checks the status of its designated parking spot using ultrasonic distance measurements. When the distance indicates a car is present, the sensor sends an "Occupied" status; otherwise, it sends a "Vacant" status.
2. **Central Hub Arduino**: Receives data from all parking spot sensors via Bluetooth and updates the total number of available spots in real-time. This data is displayed on an LCD screen.
3. **Bluetooth Communication**: The system uses Bluetooth for wireless communication between the sensors and the central hub, ensuring seamless data transfer without the need for wires.

## Materials Required
- Arduino Uno (Central Hub)
- Arduino Uno (Parking Spot Sensors)
- HC-05 Bluetooth Modules
- Ultrasonic Sensors
- LCD Displays
- Beeper/LEDs for feedback
- Breadboards, wires, and power supplies

## Set-up Instructions
- Instructions and additional information can be found in the [full project report](https://github.com/javud/spottersense/SpotterSenseReport.pdf)

## References
- [Arduino Documentation](https://www.arduino.cc/)
- [Bluetooth Communication for Arduino Projects - Instructables](https://www.instructables.com/)
- [Ultrasonic Sensors Arduino - How to Mechatronics](https://www.howtomechatronics.com/)

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
