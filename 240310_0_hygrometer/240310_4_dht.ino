void getTempHum() {

  if (dht.readHumidity() > 99) {
    hum = 99;
    debug(F("Humidity is 100%!"));
  } else {
    hum = round(dht.readHumidity());
  }
  temp = round(dht.readTemperature());
  debug(F(",  Temperature: "));
  debug(temp);
  debug(F("°C,  Humidity: "));
  debug(hum);
  debugln(F("%"));
}

byte checkHumid() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Check if any reads failed and exit early (to try again).
  if (isnan(dht.readHumidity())) {
    debugln(F("Failed to read from DHT sensor!"));
    return 2;
  }

  if (hum != round(dht.readHumidity())) {
    debug(F("Humidity: "));
    debug(round(dht.readHumidity()));
    debugln(F("%"));
    hum = round(dht.readHumidity());
    return 1;
  } else {
    return 0;
  }
}

byte checkTemp() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Check if any reads failed and exit early (to try again).
  if (isnan(dht.readTemperature())) {
    debugln(F("Failed to read from DHT sensor!"));
    return 2;
  }

  if (temp != round(dht.readTemperature())) {
    debug(F("Temperature: "));
    debug(round(dht.readTemperature()));
    debugln(F("°C "));
    temp = round(dht.readTemperature());
    return 1;
  } else {
    return 0;
  }
}
