Controlling 5 LEDs on XAMPP with ESP32, PHPMyAdmin, and MySQL Database

This project demonstrates how to control 5 LEDs using an ESP32 microcontroller with PHPMyAdmin and a MySQL database hosted on XAMPP.

## Introduction

Controlling devices remotely over a network offers convenience and flexibility. This project utilizes an ESP32 microcontroller to control 5 LEDs connected to it via Wi-Fi communication. PHPMyAdmin and MySQL database on XAMPP are used for managing LED states.

## How it Works

The ESP32 connects to the local network and communicates with PHPMyAdmin using HTTP requests. The LED states (on/off) are stored in a MySQL database. Users can control the LEDs by sending commands through a web interface hosted on XAMPP.

## Getting Started

To get started with controlling 5 LEDs on XAMPP using ESP32:

- Set up XAMPP on your computer and ensure PHPMyAdmin is accessible.
- Create a MySQL database to store LED states.
- Configure the ESP32 to connect to the Wi-Fi network and send HTTP requests to PHPMyAdmin.

## Steps

Follow these steps to implement the project:

1. Set up the MySQL database schema to store LED states.
2. Configure the ESP32 to connect to the local Wi-Fi network and establish communication with PHPMyAdmin.
3. Write code to send HTTP requests to PHPMyAdmin to update LED states based on user commands.
4. Implement a web interface on XAMPP to send commands to the ESP32 for controlling the LEDs.
5. Test the system by accessing the web interface and observing the LED states change accordingly.

## Connection

The ESP32 communicates with PHPMyAdmin through HTTP requests to update LED states in the MySQL database. The LEDs are connected to GPIO pins on the ESP32 for control.

## Output

Once the system is set up and running, users can control the LEDs through the web interface hosted on XAMPP. The ESP32 updates the LED states in the MySQL database based on user commands.

## Code

Sample code for ESP32 firmware, PHP scripts for database interaction, and HTML/CSS for the web interface can be found in the `code` directory.

## Pictures



## Conclusion

Controlling devices over a network using ESP32, PHPMyAdmin, and MySQL database offers a scalable and accessible solution for home automation and remote control projects. By hosting a web interface on XAMPP, users can easily interact with and control the connected devices from anywhere within the local network.
