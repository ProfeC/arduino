// Libraries
#include "Arduino.h"

void handleTemperature() {
  float currentTemp = hdc.readTemperature();
  String out = "";
  out += "{\"temperature\":{\"celsius\":";
  out += currentTemp;
  out += ",\"fahrenheit\":";
  out += currentTemp * 9/5 + 32;
  out += ",\"kelvin\":";
  out += currentTemp + 273.15;
  out += "}}";
  server.send ( 200, "application/json", out );
}

void handleTemperatureC() {
  float currentTemp = hdc.readTemperature();
  String out = "";
  out += "{\"temperature\":{\"celsius\":";
  out += currentTemp;
  out += "}}";
  server.send ( 200, "application/json", out );
}

void handleTemperatureF() {
  float currentTemp = hdc.readTemperature();
  String out = "";
  out += "{\"temperature\":{\"fahrenheit\":";
  out += currentTemp * 9/5 + 32;
  out += "}}";
  server.send ( 200, "application/json", out );
}

void handleTemperatureK() {
  float currentTemp = hdc.readTemperature();
  String out = "";
  out += "{\"temperature\":{\"kelvin\":";
  out += currentTemp + 273.15;
  out += "}}";
  server.send ( 200, "application/json", out );
}

