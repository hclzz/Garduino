# Automatic Irrigation System with Arduino

## Requirements

- **Hardware:**
  - Arduino (Uno, Mega, or similar)
  - Soil moisture sensor (Analog)
  - Servo Motor (for controlling the water valve)
  - Relay (to control the water pump)
  - 12V Water Pump
  - LEDs (Green, Yellow, Red)
  - Wires and breadboard

## Pins Used

- **LEDs:**
  - Green LED: pin 3
  - Yellow LED: pin 4
  - Red LED: pin 5

- **Soil Moisture Sensor:**
  - Soil moisture sensor: pin A0

- **Servo Motor:**
  - Servo motor: pin 6

- **Relay (to control the water pump):**
  - Relay: pin 7

## Moisture Level Definitions

- **High Moisture:** The soil is moist. The Green LED turns on, and the pump is turned off.
- **Moderate Moisture:** The soil is moderately moist. The Yellow LED turns on, and the pump stays off.
- **Low Moisture:** The soil is dry. The Red LED turns on, and the pump is activated.

## Main Functions

- **LED Control:**
  - The system uses three LEDs to indicate the soil moisture status:
    - Green LED: Moist soil.
    - Yellow LED: Moderately moist soil.
    - Red LED: Dry soil.

- **Water Valve Control:**
  - The servo motor is used to open or close the water valve depending on the soil moisture level.

- **Pump Control:**
  - The water pump is controlled by the relay, turning it on or off as needed for irrigation.

## How It Works

1. The system monitors the soil moisture every second.
2. If the moisture is above the predetermined limit (600), the Green LED turns on, and the pump is turned off.
3. If the moisture is between the moderate limit (400) and the high limit, the Yellow LED turns on, and the pump remains off.
4. If the moisture is below the moderate limit, the Red LED turns on, the servo motor opens the valve, and the pump is turned on to irrigate the soil.
5. The pump is automatically turned off when the soil reaches an adequate moisture level.

## How to Use

1. Connect the hardware as per the diagram.
2. Upload the code to your Arduino using the Arduino IDE.
3. The system will automatically begin monitoring the soil moisture and control irrigation.

## Conclusion

This system automates the irrigation process, making it more efficient and preventing water waste. It can easily be adapted to different plant types and soil configurations.
