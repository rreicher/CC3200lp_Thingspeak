![CC3200LP!](/img/cc3200.png "")

## Send integers datas with CC3200-LAUNCHPAD to Thingspeak Cloud Service.
This project uses CC3200-LAUNCHXL board and is designed with Code Composer Studio 8.3.0 and CC3200SDK_1.5.0.
In main file after CC3200 device intialization and Pinmux configuration, appTskCreat() is called to:
Configure serial UART for terminal logging and I2C for TMP006 temperature sensor.

Then mainTask is created and is in charge of:
- Get the temperature from TMP006 sensor, convert in °C.
- Wifi connection to local access point.
- Etablish a TCP socket with Thingspeak service.
- Then every minute, the device send two datas using GET method tmp006Value and Data0 variables array.
- Field1 receive the onboard TMP006 temperature in °C stored in tmp006Value.
- Field2 receive tmp006Value value incremented of 10, stored in Data0.

## How to use it. 
Create a Thingspeak channel, with 2 fields.

![Thingspeak Channel settings!](/img/Thinkspeak_channel_settings.png "")

In app_conf.h, update the following define according to your wifi access point:
```
#define CC_SSID_NAME          "YOUR_WIFI_SSID"          /* AP SSID */

#define CC_SECURITY_TYPE      SL_SEC_TYPE_WPA_WPA2      /* Security type (OPEN or WEP or WPA */

#define CC_SECURITY_KEY       "YOUR_WIFI_SSID_PASSWORD" /* Password of the secured AP */
```

in app_cloud.c, update your Thingspeak API key.  
```
#define THINGSPEAK_APIKEY       "YOUR_THINGSPEAK_API_KEY"
```
Make sure jumper J2, J3 are closed.

## Result.
![Thingspeak Channel Visualization!](/img/Thinkspeak_channel.png "")
