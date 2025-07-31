#include <ESP8266WiFi.h>

// Demonstrates setting default options from WiFiClient

static bool defaultNoDelay = false; // false == Nagle enabled by default

void WiFiClient::setDefaultNoDelay(bool noDelay) {
    defaultNoDelay = noDelay;
}

WiFiClient::WiFiClient(ClientContext* client)
    : _client(client), _owned(0) {
    _timeout = 5000;
    _client->ref();
    WiFiClient::_add(this);
    setNoDelay(defaultNoDelay);
}
