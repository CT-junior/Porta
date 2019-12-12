#include "WifiManager.h"

WifiManager::WifiManager()
{

}

void WifiManager::init()
{	
	Serial.print("Connecting to ");
	Serial.print(WIFI_SSID);
	Serial.print("\n");

	WiFi.mode(WIFI_STA);
	WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	
	Serial.println("");
	Serial.println("WiFi connected..!");
	Serial.print("Got IP: ");  
	Serial.print(WiFi.localIP());
	Serial.print("\n");
}