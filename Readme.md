## MPU6050 Digital Spirit Level

## Overview

This project is a digital spirit level (inclinometer) that uses an Arduino Nano, an MPU6050 accelerometer and gyroscope, and an OLED display to measure the angle of tilt along the X and Y axes. When the device is level (within 2 degrees of 0 on both axes), a buzzer and an LED will activate to provide feedback.

## Components Used

- **Arduino Nano**
- **MPU6050 Accelerometer and Gyroscope**
- **OLED Display (128x64)**
- **Buzzer**
- **LED**
- **Resistor (220Ω for the LED)**
- **Breadboard**
- **Jumper Wires**

## Wiring Instructions

### MPU6050
- **VCC** -> 3.3V or 5V (depending on your model)
- **GND** -> GND
- **SCL** -> A5 (SCL pin on Arduino Nano)
- **SDA** -> A4 (SDA pin on Arduino Nano)

### OLED Display
- **VCC** -> 5V
- **GND** -> GND
- **SCL** -> A5 (SCL pin on Arduino Nano)
- **SDA** -> A4 (SDA pin on Arduino Nano)

### Buzzer
- **Positive** -> Pin 7 on Arduino
- **Negative** -> GND

### LED
- **Anode** -> Pin 13 on Arduino (with 220Ω resistor)
- **Cathode** -> GND

## How It Works

1. **MPU6050 for Tilt Detection**: The MPU6050 sensor measures acceleration along the X, Y, and Z axes. The data is processed to calculate the angle of tilt in degrees.
2. **OLED Display**: The current tilt angles along the X and Y axes are displayed on the OLED screen in real-time.
3. **Buzzer and LED Feedback**: When the device is level (within 2 degrees of 0 degrees on both axes), the LED turns on, and the buzzer produces a sound, indicating that the surface is level.
4. **Data Processing**: The tilt angles are calculated using the `atan2()` function to convert the raw accelerometer readings into degrees.

## Features

- **Real-time Display**: Continuously shows the X and Y tilt angles on the OLED screen.
- **Level Indication**: Visual and auditory feedback when the device is perfectly level.
- **Adjustable Sensitivity**: You can modify the sensitivity for determining when the device is "level" by changing the threshold in the code (`< 2` degrees).

## Setup Instructions

1. **Connect Components**: Wire the MPU6050 sensor, OLED display, buzzer, and LED to the Arduino Nano following the wiring diagram provided above.
2. **Install Libraries**: You will need to install the following Arduino libraries:
   - `Adafruit GFX Library`
   - `Adafruit SSD1306`
   - `MPU6050`
   
   You can install these libraries via the Arduino IDE's Library Manager.
3. **Upload Code**: Open the provided code in the Arduino IDE and upload it to your Arduino Nano.
4. **Power the Device**: Once the code is uploaded, power the Arduino via USB or external power.

## Libraries Required

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
- [MPU6050 Library](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)

## Customization

- **Sensitivity**: You can adjust the level detection sensitivity by changing the tolerance in the code where the angles are compared (`if (abs(angleX) < 2 && abs(angleY) < 2)`).
- **Buzzer Tone**: The tone played when the device is level can be changed by modifying the frequency passed to the `tone()` function.
- **Display Format**: You can modify the display format to show additional information or change the text size.

## Application Ideas

- **Carpentry**: Use it to ensure surfaces are level for woodworking or construction projects.
- **Camera Mounts**: Use it to level a camera or tripod for photography.
- **Household Use**: Check whether picture frames, furniture, or appliances are level.

## License

This project is licensed under the MIT License. You are free to use, modify, and distribute this project for personal and commercial use.
