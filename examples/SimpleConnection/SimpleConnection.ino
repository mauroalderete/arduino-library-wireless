#include <Wireless.h>
#include <Flicker.h>

Flicker hasConnection(LED_BUILTIN, 1000);
Flicker lostConnection(LED_BUILTIN, 100);

String hostname;

void setup() {
  Serial.begin(115200);
  
  hostname = "myESP-" + Wireless.getUID();
  Wireless = WirelessClass("myRouter", "myPassword", hostname, 10000);
  Wireless.setModeStation();

  Wireless.OnDisconnected([]() {
    lostConnection.Loop();
  });

  Wireless.OnConnected([]() {
    hasConnection.Loop();
  });

  Wireless.Begin();

  hasConnection.Start();
  lostConnection.Start();
}

void loop() {
  Wireless.Loop();
}