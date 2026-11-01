# PodiumStopLight
ESP32-Based LED Controlled by an App

The Podium Stoplight was a priest's quorum activity for the MetroWest ward during the fall of 2026. Its purpose was to teach basics of microcontrollers, coding, and app development.

## Electronics
The heart of the project is an ESP32 module connected to a multicolor LED, though multiple single-color LEDs are also suitable. The goal was to make the electronics portion a simple as possible. For this reason, there are many features common in commercial products that are not in the project, such as a pairing button or pairing indicator, auto reconnect, etc.

The electronics are powered using a USB connector to the ESP32 dev board

## Code
All code was written in Arduino IDE using the official Espressif ESP32 library. I used this tutorial: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

The code was meant to be as basic as possible. There are all kinds of possibilities for expanding and improving it.

## Mobile App
The mobile app was created using MIT App Inventor 2 and provides some basic features, including light control, a timer function while status is yellow, and auto reset of timer when yellow is started again. The .aia source file is included for others to freely use and/or remix

## 3D Models
I have included two 3D .STL files for printing. One is a housing for the LED using a basic 5mm plastic bezel and the other is an enclosure for the ESP32 module that I mounted to a piece of perf board using headers to keep the footprint small. It has holes for screw mounting and wide flanges for mounting with double sided tape (which is what we did)
