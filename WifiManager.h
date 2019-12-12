#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h> //lib para configuração do Wifi
#include <ESPmDNS.h> //lib necessária para comunicação network
#include <WiFiUdp.h> //lib necessária para comunicação network

#define WIFI_SSID "AP_CTJUNIOR"
#define WIFI_PASSWORD "kamikaze150"

class WifiManager
{
public:
	WifiManager();
	void init();
};

#endif
