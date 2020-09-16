# Air Quality Exporter

A simple Arduino program that exports PMS [1,3,5,7]003 PlanTower sensor
data to prometheus.

# Hardware
* NodeMCU ESP8266 board. You can find them online for around $5 (or less) per board.
* Plantower PMS 7003 sensor. The older 3003 and 5003 sensors should also work. You can find them online for $15 to $30 depending on where you look.

# Software
* Arduino software with ESP8266 Board Installed (select 'Board Manager' and search for ESP8266)
* VS Code w/ the Arduino plugin (not strictly required, but way better imho than the built-in arduino editor)
* Prometheus Push Gateway running somewhere in your local network.

# Set up your environment
To build this package, you'll need some standard arduino tools. If you're using Windows/Mac/Linux with a visual interface, you can download and install these tools from the [Arduino](https://www.arduino.cc/en/main/software). 

If you would like to build everything from the CLI, you can do so by installing these tools:
```
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli core update-index
arduino-cli core install esp8266:esp8266
arduino-cli lib update-index
arduino-cli lib install "PMS Library"
```

# Build & Install
You'll need to create `Secret.h` containing your WiFi credentials as well as the location of your push gateway.

Then build and install on the ESP8266 board.

You can build by executing the following commands:
```
arduino-cli compile --fqbn esp8266:esp8266:generic pms7003
```

Then you wil need to upload to the board:
```
arduino-cli upload --fqbn esp8266:esp8266:generic pms7003
```

Wire the power on the PMS 7003 to the 5v and Gnd terminals on the board, the Tx/Rx to the Rx/Tx on the board.

I have personally found that you need to disconnect the serial from the Plantower in order to flash the program (not sure why)

Watch the data flow!

# Bugs/suggestions
Very welcome!