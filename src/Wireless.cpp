#include "Wireless.h"

WirelessClass::WirelessClass(){
    setDefault();
}

WirelessClass::WirelessClass(String ssid, String password){
    setDefault();

    setSSID(ssid);
    setPassword(password);
}

WirelessClass::WirelessClass(String ssid, String password, String hostname){
    setDefault();

    setSSID(ssid);
    setPassword(password);
    setHostname(hostname);
}

WirelessClass::WirelessClass(String ssid, String password, String hostname, unsigned long timeout){
    setDefault();

    setSSID(ssid);
    setPassword(password);
    setHostname(hostname);
    setTimeout(timeout);
}

void WirelessClass::setDefault(){
    ssid = "";
    password = "";
    hostname = "ESP8266";
    mode = WIFI_AP;
    ip = IPAddress(192, 168, 0, 2);
    gateway = IPAddress(192, 168, 0, 1);
    subnet = IPAddress(255, 255, 255, 0);
    staticip = false;
    timeout = 5000;
    current_status = WL_IDLE_STATUS;
    previous_status = WL_IDLE_STATUS;
}

WirelessClass::~WirelessClass(){
    
}

void WirelessClass::setSSID(String ssid){
    this->ssid = ssid;
}

void WirelessClass::setPassword(String password){
    this->password = password;
}

void WirelessClass::setAccess(String ssid, String password){
    setSSID(ssid);
    setPassword(password);
}

void WirelessClass::setTimeout(unsigned long timeout){
    this->timeout = timeout;
}

void WirelessClass::setHostname(String hostname){
    this->hostname = hostname;
}

void WirelessClass::setModeStation(){
    mode = WIFI_STA;
}

void WirelessClass::setModeAP(){
    mode = WIFI_AP;
}

void WirelessClass::setStaticIP(String ip, String gateway, String subnet){
    this->ip.fromString( ip.c_str() );
    this->gateway.fromString( gateway.c_str() );
    this->subnet.fromString( subnet.c_str() );
    staticip = true;
}

String WirelessClass::getUID(){
    return WiFi.macAddress();
}

wl_status_t void WirelessClass::getStatus(){
    return current_status;
}

void WirelessClass::Begin(){
    WiFi.mode(mode);
    if(hostname!=""){
        WiFi.hostname(hostname);
    }
    WiFi.begin(ssid, password);
    if(staticip){
        WiFi.config(ip, gateway, subnet);
    }

    interval = 0;
}

void WirelessClass::Loop(){
    current_status = WiFi.status();

    if( current_status != previous_status ){
        //hubo un cambio en el estado de coneccion;
        if( current_status == WL_CONNECTED ){
            //recupero la conexion
        }
        if( previous_status == WL_CONNECTED){
            //acaba de perder la conexion
            interval == millis();
        }
    }

    if (WiFi.status() == WL_CONNECTED){

    } else {
        unsigned long current = millis();
        if( current - interval >= timeout ){
            //se acabo el tiempo de espera para reintentar conectar
            interval = current;
        }
    }

    previous_status = current_status;
}

WirelessClass Wireless;