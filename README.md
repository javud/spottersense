
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

## Materials Required
- Arduino Uno (Central Hub)
- Arduino Uno (Parking Spot Sensors)
- HC-05 Bluetooth Modules
- Ultrasonic Sensors
- LCD Displays
- Beeper/LEDs for feedback
- Breadboards, wires, and power supplies

## Set-up 
- Instructions for set-up and additional information can be found in the [full project report](https://github.com/javud/spottersense/SpotterSenseReport.pdf)
- You will need to download and run the file SERVER.ino on the Central Hub Arduino and the file CLIENT.ino on the Parking Spot Sensor(s) Arduino

## References
- [Arduino Documentation](https://www.arduino.cc/)
- [Bluetooth Communication for Arduino Projects - Instructables](https://www.instructables.com/)
- [Ultrasonic Sensors Arduino - How to Mechatronics](https://www.howtomechatronics.com/)

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
