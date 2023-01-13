/* -------------------------------------------------------------------
 * AdminSidon - Ecosat 2023
 * Plataforma ESP32
 * Proyecto Admin Panel Tool para el ESP32
 * -------------------------------------------------------------------
*/
//--------------------------------------------------------------------
//Funciones 
//--------------------------------------------------------------------
#include "ledBlink.hpp"

void log(String s)
{
    Serial.println(s);
}

String platform(){
// Optiene la plataforma de hardware
#ifdef ARDUINO_ESP32_DEV
    return "Sidon";
#endif
}

IPAddress CharToIP(const char *str){
    sscanf(str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
    return IPAddress(ip[0], ip[1], ip[2], ip[3]);
}

String ipStr(const IPAddress &ip){    
    String sFn = "";
    for (byte bFn = 0; bFn < 3; bFn++)
    {
        sFn += String((ip >> (8 * bFn)) & 0xFF) + ".";
    }
    sFn += String(((ip >> 8 * 3)) & 0xFF);
    return sFn;
}

//Archivo hexadecimal a string
String hexstr(const unsigned long &h,const byte &l = 8)
{
    String s;
    s = String(h,HEX);
    s.toUpperCase();
    s = ("000000000" + s).substring(s.length() + 8 - l);
    return s;
}
//Generar un ID unico
String idUnique()
{
    //retorna los ultimos 4 bytes del mac rotados
    char idunique[15];
    uint64_t chipid = ESP.getEfuseMac();
    uint16_t chip = (uint16_t)(chipid >> 32);
    snprintf(idunique,15,"%04X",chip);
    return (String)idunique;
}
String deviceID()
{
    return String(platform()) + hexstr(ESP.getEfuseMac()) + String(idUnique());
}

void settingsPines(){
    //Declaraciones de pines 
    pinMode ( RELAY1, OUTPUT);
    pinMode ( RELAY2, OUTPUT);
    pinMode ( WIFILED, OUTPUT);
    pinMode ( MQTTLED, OUTPUT);
    //Nivel logico bajo 
    digitalWrite(RELAY1, LOW);
    digitalWrite(RELAY2, LOW);
    digitalWrite(WIFILED, LOW);
    digitalWrite(MQTTLED, LOW);
}

