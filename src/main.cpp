/* -------------------------------------------------------------------
 * AdminSidon - Ecosat 2023
 * Plataforma ESP32
 * Proyecto Admin Panel Tool para el ESP32
 * -------------------------------------------------------------------
*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <SPIFFS.h>
#include "settings.hpp"
#include "functions.hpp"
#include "settingsReset.hpp"
#include "settingsRead.hpp"
#include "settingsSave.hpp"
#include "sidon_wifi.hpp"

void setup() {
  // Velocidad de serial 
  Serial.begin(115200);
  //Asignar frecuencia de CPU 
  setCpuFrequencyMhz(240);
  // inicio de log por serial
  log("\nInfo: Iniciando setup");
  //configurar los pines
  settingsPines(); 
  //Inicio de SPIFFS
  SPIFFS.format();
  if (!SPIFFS.begin()){
    log (F("Error: fallo en la inicializacion del SPIFFS"));
    while(true);
  }
  //Leer configuracion wifi
  settingReadWifi();
  //Configurar wifi
  WiFi.disconnect(true);
  delay(1000);
  //Setup del wifi
  wifi_setup();
}

void loop() {
      yield();
    // -------------------------------------------------------------------
    // WIFI
    // -------------------------------------------------------------------
    if (wifi_mode == WIFI_STA){
        wifiLoop();
    }else if (wifi_mode == WIFI_AP){
        wifiAPLoop();
    } 
}