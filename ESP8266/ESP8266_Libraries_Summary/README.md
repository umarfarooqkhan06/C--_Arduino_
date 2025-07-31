# ESP8266 Libraries Summary

This folder contains a brief overview of the libraries found in `ESP8266/ESP8266_Libraries`.

- **Adafruit_GFX_Library**: Graphics primitives for displays.
- **Adafruit_SSD1306**: OLED display driver.
- **DHT_kxn**: Temperature and humidity sensor library.
- **ESP8266WiFi**: WiFi client implementation.
- **FirebaseJson**: JSON helper library.

Example snippet from `Adafruit_GFX`:
```cpp
void Adafruit_GFX::writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                             uint16_t color) {
#if defined(ESP8266)
  yield();
#endif
  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    _swap_int16_t(x0, y0);
    _swap_int16_t(x1, y1);
  }
  // ...
}
```

## Example: DHT11 Sensor Data to Firebase

`DHT11Firebase.ino` shows how to read temperature and humidity from a DHT11 sensor and send the values to a Firebase Realtime Database.

```cpp
#define FIREBASE_REALTIME_URL "YOUR_FIREBASE_URL"
#define FIREBASE_REALTIME_SECRET "YOUR_DATABASE_SECRET"
#define DHTPIN 2
#define DHTTYPE DHT11
```

The sketch connects to WiFi, reads the sensor values and uses the `FirebaseRealtime` library to upload them every few seconds.
