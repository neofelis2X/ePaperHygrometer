byte checkHours() {
  DateTime now = (rtc.now() + secCorrOffset);
  if (hours != now.hour()) {

    // Stunden
    if (now.hour() <= 9) {
      debug('0');
      // Serial.print(now.hour(), DEC);
      debug(now.hour());
    } else {
      debug(now.hour());
    }

    debug(':');

    // Minuten
    if (now.minute() <= 9) {
      debug('0');
      debugln(now.minute());
    } else {
      debugln(now.minute());
    }
    hours = now.hour();
    mins = now.minute();
    return 1;

  } else {
    return 0;
  }
}

byte checkMins() {
  DateTime now = (rtc.now() + secCorrOffset);
  if (mins != now.minute()) {

    // Stunden
    if (now.hour() <= 9) {
      debug('0');
      debug(now.hour());
    } else {
      debug(now.hour());
    }

    debug(':');

    // Minuten
    if (now.minute() <= 9) {
      debug('0');
      debugln(now.minute());
    } else {
      debugln(now.minute());
    }
    hours = now.hour();
    mins = now.minute();
    return 1;

  } else {
    return 0;
  }
}

void getFullTime() {
  DateTime now = (rtc.now() + secCorrOffset);

  // Jahre
  debug(now.year());

  debug('/');

  // Monate
  if (now.month() <= 9) {
    debug('0');
    debug(now.month());
  } else {
    debug(now.month());
  }

  debug('/');

  // Tage
  if (now.day() <= 9) {
    debug('0');
    debug(now.day());
  } else {
    debug(now.day());
  }

  debug(", ");

  // Stunden
  if (now.hour() <= 9) {
    debug('0');
    debug(now.hour());
  } else {
    debug(now.hour());
  }

  debug(':');

  // Minuten
  if (now.minute() <= 9) {
    debug('0');
    debug(now.minute());
  } else {
    debug(now.minute());
  }

  debug(':');

  // Sekunden
  if (now.second() <= 9) {
    debug('0');
    debug(now.second());
  } else {
    debug(now.second());
  }

  hours = now.hour();
  mins = now.minute();
}
