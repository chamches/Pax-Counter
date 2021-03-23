

#include <ESP8266WiFi.h>
#include "./functions.h"

#include "ESP8266HTTPClient.h"


extern String Mac[100];

String Data1;
String Data2;
String Data3;



#define DELAY 10
#define disable 0
#define enable  1
unsigned int channel = 1;

unsigned int x = 0;

void setup() {
  Serial.begin(57600);
  Serial.printf("\n\nSDK version:%s\n\r", system_get_sdk_version());
  Serial.println(F("Pax-Counter"));


  Data1 = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n<command id=\"read data\">\n<data>\n";
  Data3 = "</data>\n</command>\n";
 
  
  wifi_set_opmode(STATION_MODE);            // Promiscuous works only with station mode
  wifi_set_channel(channel);
  wifi_promiscuous_enable(disable);
  wifi_set_promiscuous_rx_cb(promisc_cb);   // Set up promiscuous callback
  wifi_promiscuous_enable(enable);
}

void loop() {
  
  channel = 1;
  wifi_set_channel(channel);
  while (true) {
    nothing_new++;                          // Array is not finite, check bounds and adjust if required
    if (nothing_new > 100) {
      nothing_new = 0;
      channel++;
      if (channel == 15) break;             // Only scan channels 1 to 14
      wifi_set_channel(channel);
    }
    delay(1);  // critical processing timeslice for NONOS SDK! No delay(0) yield()
  
  x++;
  if(x >= 10000)
  {




  wifi_promiscuous_enable(disable);

  
    WiFi.begin("OnePlus 6T", "12345678");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  WiFiClient client;
  if(client.connect("192.168.43.194",8080)){

    
    client.print(Data1);


    for(int i = 0; i<=100;i++){
      delay(DELAY);
      client.print("<mac>:" + Mac[i+1] + "</mac>\n");
  
  
      if(Mac[i+1] == ""){
        break;
      }
    }
       
    Data2 = "";
    delay(DELAY);
    client.print(Data3);
    delay(DELAY);
    client.print("exit");

    client.stop();
  }
  x = 0;

//Mac leeren
for(int m = 0; m<100;m++)
{
Mac[m] = "";
}


  wifi_promiscuous_enable(enable);
}

    
  }

        
      }

  
