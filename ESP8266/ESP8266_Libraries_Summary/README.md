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
