#ifndef _WIRELESS_HPP_
#define _WIRELESS_HPP_

#include <Arduino.h>
#include <ESP8266WiFi.h>

class WirelessClass{
private:
    String ssid;
    String password;
    String hostname;
    bool staticip;
    IPAddress ip;
    IPAddress gateway;
    IPAddress subnet;
    WiFiMode mode;

    void setDefault();

    unsigned long interval;
    unsigned long timeout;
    unsigned long lapsed;

    wl_status_t current_status;
    wl_status_t previous_status;
    bool firstConnection;

    void (*onFirstConnection)(void);
    void (*onReconnected)(void);
    void (*onLostConnection)(void);
    void (*onDisconnected)(void);
    void (*onConnected)(void);
    void (*onTimeout)(void);

public:
    WirelessClass();
    WirelessClass(String ssid, String password);
    WirelessClass(String ssid, String password, String hostname);
    WirelessClass(String ssid, String password, String hostname, unsigned long timeout);
    ~WirelessClass();

    void setSSID(String ssid);
    void setPassword(String password);
    void setAccess(String ssid, String password);
    void setTimeout(unsigned long timeout);
    void setHostname(String hostname);
    void setModeStation();
    void setModeAP();

    void setStaticIP(String ip, String gateway, String subnet);

    String getUID();
    wl_status_t getStatus();

    void Begin();
    void Loop();

    void OnFirstConnection( void (*fn)(void) ){
        onFirstConnection = fn;
    }

    void OnReconnected( void (*fn)(void) ){
        onReconnected = fn;
    }

    void OnLostConnection( void (*fn) (void) ){
        onLostConnection = fn;
    }

    void OnDisconnected( void (*fn)(void) ){
        onDisconnected = fn;
    }

    void OnConnected( void (*fn)(void) ){
        onConnected = fn;
    }

    void OnTimeout( void (*fn)(void) ){
        onTimeout = fn;
    }


};

extern WirelessClass Wireless;

#endif