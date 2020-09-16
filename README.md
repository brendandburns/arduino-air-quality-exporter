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

# Build & Install
You'll need to create `Secret.h` containing your WiFi credentials as well as the location of your push gateway.

Then build and install on the ESP8266 board.

Wire the power on the PMS 7003 to the 5v and Gnd terminals on the board, the Tx/Rx to the Rx/Tx on the board.

I have personally found that you need to disconnect the serial from the Plantower in order to flash the program (not sure why)

Watch the data flow!

# Bugs/suggestions
Very welcome!