void initEPD() {
  display.setRotation(3);

  display.setFullWindow();
  //  display.setPartialWindow(98, 13, 198, 102);
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);

    display.drawInvertedBitmap(98, 35, points, 10, 59, GxEPD_BLACK);
    //    display.setPartialWindow(262, 13, 30, 102);
    display.drawInvertedBitmap(260, 13, units, 30, 102, GxEPD_BLACK);
  } while (display.nextPage());

  // FIXME: Timer should no be called directly from here
  DateTime now = (rtc.now() + secCorrOffset);
  drawHour(now.hour());
  drawMinute(now.minute());
  drawTemp(round(dht.readTemperature()));
  drawHumid(round(dht.readHumidity()));
}

void drawHour(byte th) {
  debug(F("Stunde: "));
  debug(th);
  debug(F(", "));
  byte th1;
  byte th2;
  th1 = th / 10;
  th2 = th % 10;
  debug(th1);
  debug(F(", "));
  debugln(th2);

  //  display.setPartialWindow(x, y, w, h);
  display.setPartialWindow(4, 9, 89, 110);

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(4, 9, big_digits[th1], 43, 110, GxEPD_BLACK);
    display.drawInvertedBitmap(50, 9, big_digits[th2], 43, 110, GxEPD_BLACK);
  } while (display.nextPage());

  debug(F("Es wurde eine Stundenanzeige von "));
  debug(th);
  debugln(F(" dargestellt."));
}

void drawMinute(byte tm) {
  debug(F("Minute: "));
  debug(tm);
  debug(F(", "));
  byte tm1;
  byte tm2;
  tm1 = tm / 10;
  tm2 = tm % 10;
  debug(tm1);
  debug(F(", "));
  debugln(tm2);

  display.setPartialWindow(114, 9, 89, 112);

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(114, 9, big_digits[tm1], 43, 110, GxEPD_BLACK);
    display.drawInvertedBitmap(160, 9, big_digits[tm2], 43, 110, GxEPD_BLACK);
  } while (display.nextPage());

  debug(F("Es wurde eine Minutenanzeige von "));
  debug(tm);
  debugln(F(" dargestellt."));
}

void drawTemp(byte temp) {
  debug(F("Temperatur: "));
  debug(temp);
  debug(F(", "));
  byte temp1;
  byte temp2;
  temp1 = temp / 10;
  temp2 = temp % 10;
  debug(temp1);
  debug(F(", "));
  debugln(temp2);

  //  display.setPartialWindow(x, y, w, h);
  display.setPartialWindow(216, 13, 39, 46);

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(216, 13, small_digits[temp1], 18, 46, GxEPD_BLACK);
    display.drawInvertedBitmap(237, 13, small_digits[temp2], 18, 46, GxEPD_BLACK);
  } while (display.nextPage());

  debug(F("Es wurde eine Temperatur von "));
  debug(temp);
  debugln(F(" dargestellt."));
}

void drawHumid(byte hum) {
  debug(F("Luftfeuchte: "));
  debug(hum);
  debug(F(", "));
  byte hum1;
  byte hum2;
  hum1 = hum / 10;
  hum2 = hum % 10;
  debug(hum1);
  debug(F(", "));
  debugln(hum2);

  //  display.setPartialWindow(x, y, w, h);
  display.setPartialWindow(216, 69, 39, 46);

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(216, 69, small_digits[hum1], 18, 46, GxEPD_BLACK);
    display.drawInvertedBitmap(237, 69, small_digits[hum2], 18, 46, GxEPD_BLACK);
  } while (display.nextPage());

  debug(F("Es wurde eine Luftfeuchte von "));
  debug(hum);
  debugln(F(" dargestellt."));
}

// display.drawInvertedBitmap(0, 0, Bitmap3c200x200_red, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_RED);
