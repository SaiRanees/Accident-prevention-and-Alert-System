# Accident-prevention-and-Alert-System


This project is an Arduino-based system designed to prevent accidents and alert nearby individuals or authorities when a potential accident is detected. The system uses ultrasonic sensors to monitor distances in the front and back of a vehicle and a vibration sensor to detect collisions or impact. If an accident is detected, it triggers an alert by activating a buzzer and sending an SMS message.

Features
Accident Detection: Monitors the distance between objects and detects potential accidents using ultrasonic sensors and a vibration sensor.

Buzzer Alert: When an object is detected too close to the vehicle or when a vibration is detected, a buzzer is triggered to alert the driver.

SMS Notification: Sends an SMS notification to a predefined number in case of an accident or a dangerous situation.

Real-time Monitoring: Displays sensor readings (distance and vibration status) on an LCD screen for real-time monitoring.


Components Used
Arduino Uno: The main microcontroller for handling sensor data and controlling the outputs.

Ultrasonic Sensors: Measures distances from objects in front and behind the vehicle.

Vibration Sensor: Detects collisions or impacts.

LCD Display: Shows real-time sensor readings (distances and vibration status).

Buzzer: Alerts the user when a critical situation is detected.

Motor Control: Controls motor movement based on detected obstacles.

GSM Module: Used to send SMS alerts in case of an accident.


How the System Works

Distance Monitoring: The system uses two ultrasonic sensors to measure the distance between the vehicle and any objects in front or behind. If the distance is below a predefined threshold (e.g., less than 10 cm), an alert is triggered.

Vibration Detection: The system constantly monitors the vibration sensor to detect a collision or impact. If the sensor is triggered, the system assumes an accident has occurred.

Alert Mechanism:

If a dangerous situation is detected (i.e., an obstacle is too close or a vibration is detected), the buzzer sounds to warn the driver.
Simultaneously, an SMS message is sent to a predefined number, alerting about the accident.
Motor Control: The system also controls the movement of the vehicle's motors. If a critical situation occurs (e.g., an accident), the motors are stopped immediately.

Circuit Diagram


Ultrasonic Sensors:
Front sensor: Trigger connected to A1, Echo connected to A0.

Rear sensor: Trigger connected to pin 7, Echo connected to pin 6.

Motors:

Controlled by pins A2, A3, A4, and A5 for forward and reverse movements.

Buzzer: Connected to pin 3.

Vibration Sensor: Connected to pin 4.

LCD Display: Connected to pins 8, 9, 10, 11, 12, and 13.


Code Explanation

Distance Measurement:

The dist() and dist1() functions handle the ultrasonic sensors to measure the distance to obstacles in front and behind the vehicle.
If the distance is less than 10 cm, the buzzer is activated, and the vehicle's movement is stopped.

Accident Detection:

If the vibration sensor detects a collision (vibration reading is 0), the system concludes that an accident has occurred.
The message "ACCIDENT DETECTED" is displayed on the LCD, and the system halts all motor movements.

SMS Alert:

The send_sms() function is responsible for sending an SMS to a predefined number using the GSM module.
The message contains an alert about the accident and is sent twice for redundancy.

Motor Control:

The motors are controlled through pins A2, A3, A4, and A5. They are responsible for forward and reverse movements.
If a danger is detected, the motors are stopped to prevent further movement.


Usage

1. Hardware Setup

Connect the ultrasonic sensors, vibration sensor, motors, LCD, and GSM module to the Arduino as per the circuit diagram.
Ensure that the GSM module is properly configured and can send SMS messages.

2. Running the Code
   
Upload the provided Arduino code to the Arduino Uno.
Power the system and place it on the vehicle or simulation setup.
Monitor the real-time distance and vibration readings on the LCD.
4. System Behavior

The buzzer will sound if the distance in front or back is less than 10 cm or if a vibration is detected.
The motors will stop in case of a critical event, and an SMS will be sent to the predefined phone number.


Example SMS

Alert: Accident detected


Future Enhancements

Integration of GPS for precise location tracking in case of an accident.

More advanced obstacle avoidance algorithms to improve system accuracy.

Addition of emergency contact list to send SMS to multiple recipients.

