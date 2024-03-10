void setup() {
  Serial.begin(115200);
  debugln(F("Serial initialisiert."));
  delay(100);
  //epaper Start
  display.init(115200);

  //DHT Start
  dht.begin();

  //RTC Start
  if (!rtc.begin()) {
    debugln(F("Couldn't find RTC"));
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println(F("RTC lost power, lets set the time!"));
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    debugln(F("Time set."));
  }

  getFullTime();
  getTempHum();
  initEPD();

  lastDHT = millis();
  lastEPDinit = millis();
}
