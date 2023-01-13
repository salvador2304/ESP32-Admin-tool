/* -------------------------------------------------------------------
 * AdminSidon - Ecosat 2023
 * Plataforma ESP32
 * Proyecto Admin Panel Tool para el ESP32
 * -------------------------------------------------------------------
*/
//--------------------------------------------------------------------
//#Definiciones Generales 
//--------------------------------------------------------------------
#define RELAY1 25
#define RELAY2 33
#define WIFILED 12
#define MQTTLED 13
//-----------------------------------------
//Version del hardware
//-----------------------------------------
#define HW "ADMINSIDON v1 00000000"     //Version de hardware
//-----------------------------------------
//Configuracion general
//-----------------------------------------
char id[30];                            //Id del dispositivo
int bootcount;                          //Numero de reinicios
//-----------------------------------------
//Zona WIFI
//-----------------------------------------
bool wifi_staticIP;                     //uso de la IP estatica
char wifi_ssid[30];                     //Red Wifi
char wifi_passw[30];                    //Contrase;a de Red Wifi
char wifi_ip_static[15];                //IP estatica
char wifi_gateway[15];                  //Gateway
char wifi_subnet[15];                   //Subred
char wifi_primaryDNS[15];               //DNS primario
char wifi_secondaryDNS[15];             //DNS secundario
//-----------------------------------------
//Zona AP
//-----------------------------------------
bool ap_accesPoint;                     //uso de modo AP
char ap_name[31];                       //SSID AP
char ap_passwordap[63];                 //Contrase;a de AP
int ap_canalap;                         //Canal de AP
int ap_hiddenap;                        //Es visible o no el ap
int ap_connect;
uint8_t ip[4];                          //Variable función convertir string a IP 




