/* Matthias Kneidinger 2024.03.10
Arduino Firmware for a hygrometer / clock
with epaper display
*/

//#define ENABLE_GxEPD2_GFX 0
#include <GxEPD2_BW.h>
#include "DHT.h"
#include "RTClib.h"
#include "hygrometer_bitmaps.h"  // 2.9"  b/w

#define SOFTSERIAL 1

#if SOFTSERIAL == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

#define MAX_DISPLAY_BUFFER_SIZE 15000ul  // ~15k is a good compromise
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))

GxEPD2_BW<GxEPD2_290, MAX_HEIGHT(GxEPD2_290)> display(GxEPD2_290(/*CS=77*/ SS, /*DC=*/8, /*RST=*/9, /*BUSY=*/11));

const unsigned char* big_digits[] = {
  big0, big1, big2, big3, big4, 
  big5, big6, big7, big8, big9
};

const unsigned char* small_digits[] = {
  small0, small1, small2, small3, small4, 
  small5, small6, small7, small8, small9
};

const unsigned char* bmps[] = {
  points, units
};
// EPD End

// DHT Sensor
#define DHTPIN 12      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
// DHT Sensor End

// Realtime Clock
RTC_DS3231 rtc;
byte secCorrOffset = 28;  // Anzahl Sekunden um die die Zeit korrigiert werden soll

// FIXME: There are way too many globals
byte hours = 11;
byte mins = 11;
byte hum = 11;
byte temp = 11;
unsigned long lastDHT;
unsigned long lastEPDinit;
// Realtime Clock End
