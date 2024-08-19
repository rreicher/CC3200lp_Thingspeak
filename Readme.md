## Send integer datas with CC3200-LAUNCHPAD to Thingspeak.
This project uses CC3200-LAUNCHXL board. After intialization and wifi AP connection, a TCP socket is etablished with Thingspeak service.
Then every minute, the device send two datas using GET method.
Thingspeak Field1 receive onboard TMP006 temperature in °C.
Thingspeak Field1 receive a basic value incremented of 10.

## How to use it. 
Create a Thingspeak channel, with 2 field.
In app_conf.h, update the following constant according to your wifi access point:
#define CC_SSID_NAME          "YOUR_WIFI_SSID"          /* AP SSID */
#define CC_SECURITY_TYPE      SL_SEC_TYPE_WPA_WPA2      /* Security type (OPEN or WEP or WPA */
#define CC_SECURITY_KEY       "YOUR_WIFI_SSID_PASSWORD" /* Password of the secured AP */
#define CC_SSID_LEN_MAX       32
#define CC_BSSID_LEN_MAX      6

in app_cloud.c, update your Thingspeak API key.  
#define THINGSPEAK_APIKEY       "YOUR_THINGSPEAK_API_KEY"
