/* -------------------------------------------------------------------
 * AdminSidon - Ecosat 2023
 * Plataforma ESP32
 * Proyecto Admin Panel Tool para el ESP32
 * -------------------------------------------------------------------
*/
//--------------------------------------------------------------------
// configuracion de metodo reset
//--------------------------------------------------------------------
void configResetWifi()
{
    strlcpy(id,"adminSidon",sizeof(id));
    bootcount = 0;

    wifi_staticIP= false;
    strlcpy(wifi_ssid,          "Ecosat",           sizeof(wifi_ssid));
    strlcpy(wifi_passw,         "ECOSAT2021",       sizeof(wifi_passw));
    strlcpy(wifi_ip_static,     "192.168.10.251",   sizeof(wifi_ip_static));
    strlcpy(wifi_gateway,       "192.168.10.1",     sizeof(wifi_gateway));
    strlcpy(wifi_subnet,        "255.255.255.0",    sizeof(wifi_subnet)) ;
    strlcpy(wifi_primaryDNS,    "8.8.8.8",          sizeof(wifi_primaryDNS));
    strlcpy(wifi_secondaryDNS,  "8.8.4.4",          sizeof(wifi_secondaryDNS));

    ap_accesPoint =  true;
    strlcpy(ap_name,             deviceID().c_str(),    sizeof(ap_name));
    strlcpy (ap_passwordap,     "98374252",      sizeof(ap_passwordap));
    ap_canalap =    9;
    ap_hiddenap =   false;
    ap_connect =    4;

}

