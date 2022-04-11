# OTABlynkCredentials
This repository contains the library and code for entering your wifi and blynk credentials over the air using your web browser


Necesaary Changes that you have to do in the code
1. Change the Erasing button pin according to your project. This button will be used to erase the data saved in EEPROM.
2. Enter SSID name and password for your ESP board acting as a server. 

Above mentioned changes will differ according to different user. If you want to see how to use this library for your Blynk projects,
then kindly watch this full tutorial video,

https://youtu.be/cjGBlEVPGBI

Remix by Embdsys Apr 10 2022
*If youre using a local Blynk server you will need to point the device to the server and port (8080 by default)*
*Look for this part in the "OTABlynkCredentials.ino"*

  if (Credentials.credentials_get())
  {  
    // If you're using a local Blynk server you have to point the device to the server and port (8080 by default)
    Blynk.config(auth_token,IPAddress(192,168,0,77),8080);
    // Else uncomment the line underneath
    //   Blynk.config(auth_token)
    connected_to_internet = 1;
  }
