/* -------------------------------------------------------------------
 * AdminSidon - Ecosat 2023
 * Plataforma ESP32
 * Proyecto Admin Panel Tool para el ESP32
 * -------------------------------------------------------------------
*/
// -------------------------------------------------------------------
// Leer configuraciones de los Parametros WIFI
// -------------------------------------------------------------------
bool settingReadWifi()
{

    StaticJsonDocument<500> jsonConfig;

    File file = SPIFFS.open("/ConfigWifi.json","r");

    if(deserializeJson(jsonConfig,file))
    {
        //si falla la lectura inicia valores por defecto
        configResetWifi();
        log("Error: fallo la lectura de la configuracion WIFI, tomando valores por defecto");
        return false;
    }
    else
    {
        /*-------------------------------------------GENERAL---------------------------------------------------*/
        strlcpy(id, jsonConfig["id"], sizeof(id));
        bootcount = jsonConfig["boot"];
       
        /*-------------------------------------------CLIENTE--------------------------------------------------*/
        wifi_staticIP =             jsonConfig["wifi_staticIP"];
        strlcpy(wifi_ssid,          jsonConfig["wifi_ssid"],        sizeof(wifi_ssid));
        strlcpy(wifi_passw,         jsonConfig["wifi_passw"],       sizeof(wifi_passw));
        strlcpy(wifi_ip_static,     jsonConfig["wifi_ip_static"],   sizeof(wifi_ip_static));
        strlcpy(wifi_gateway,       jsonConfig["wifi_gateway"],     sizeof(wifi_gateway));
        strlcpy(wifi_subnet,        jsonConfig["wifi_subnet"],      sizeof(wifi_subnet)) ;
        strlcpy(wifi_primaryDNS,    jsonConfig["wifi_primaryDNS"],  sizeof(wifi_primaryDNS));
        strlcpy(wifi_secondaryDNS,  jsonConfig["wifi_secondaryDNS"],sizeof(wifi_secondaryDNS));
        /*----------------------------------------------- AP -------------------------------------------------*/
        ap_accesPoint =         jsonConfig["ap_accesPoint"];
        strlcpy(ap_name,        jsonConfig["ap_name"], sizeof(ap_name));
        strlcpy (ap_passwordap, jsonConfig["ap_passwordap"], sizeof(ap_passwordap));
        ap_canalap =            jsonConfig["ap_canalap"];
        ap_hiddenap =           jsonConfig["ap_hiddenap"];
        ap_connect =            jsonConfig["ap_connect"];
        file.close();
        log("info: Lectura configuracidn wiri correcta");
        return true;
    }
}

