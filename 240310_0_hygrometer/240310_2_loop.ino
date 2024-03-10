void loop() {

  DateTime now = (rtc.now() + secCorrOffset);

  if (hours != now.hour()) {
    hours = now.hour();
    drawHour(hours);
  }

  if (mins != now.minute()) {
    mins = now.minute();
    drawMinute(mins);
  }

  if (millis() - lastDHT > 3000) {
    //    debugln(millis()-lastDHT);
    if (temp != round(dht.readTemperature())) {
      temp = round(dht.readTemperature());
      drawTemp(temp);
    }

    if (hum != round(dht.readHumidity())) {

      if (dht.readHumidity() > 99) {
        hum = 99;
        debug(F("Humidity is 100%!"));
      } else {
        hum = round(dht.readHumidity());
      }
      drawHumid(hum);
    }
    lastDHT = millis();
  }

  if (millis() - lastEPDinit > 3600000) {
    // FIXME: Create a fullRedraw function
    initEPD();
    lastEPDinit = millis();
  }

  delay(500);
}
