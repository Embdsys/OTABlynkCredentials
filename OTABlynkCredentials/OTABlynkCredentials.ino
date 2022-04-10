#include "OTABlynkCredentials.h"

#ifdef ESP8266
#include <BlynkSimpleEsp8266.h>
#elif defined(ESP32)
#include <BlynkSimpleEsp32.h>
#else
#error "Board not found"
#endif

credentials Credentials;



//Variables
char auth_token[33];
bool connected_to_internet = 0;
const int Erasing_button = 2;


//Provide credentials for your ESP server
char* esp_ssid = "techiesms";
char* esp_pass = "";

//
//
// .     Add your variables 
//
// .             HERE
// .
//
//





void setup()

{

  Serial.begin(115200);
  pinMode(Erasing_button, INPUT);


  for (uint8_t t = 4; t > 0; t--) {
    Serial.println(t);
    delay(1000);
  }

  // Press and hold the button to erase all the credentials
  if (digitalRead(Erasing_button) == LOW)
  {
    Credentials.Erase_eeprom();

  }

  String auth_string = Credentials.EEPROM_Config();
  auth_string.toCharArray(auth_token, 33);

  if (Credentials.credentials_get())
  {
    // If you're using a local Blynk server you have to point the device to the server and port (8080 by default)
    Blynk.config(auth_token,IPAddress(192,168,0,77),8080);
    // Else uncomment the line underneath
    //   Blynk.config(auth_token)
    connected_to_internet = 1;

  }
  else
  {
    Credentials.setupAP(esp_ssid, esp_pass);
    connected_to_internet = 0;
  }


  if (connected_to_internet)
  {

    //
    //
    // .  Write the setup part of your code
    //
    // .             HERE
    // .
    //
    //

  }



}



void loop()
{
  Credentials.server_loops();

  if (connected_to_internet)
  {


    //
    //
    // .  Write the loop part of your code
    //
    // .             HERE
    // .
    //
    //


    Blynk.run();
  }
}
