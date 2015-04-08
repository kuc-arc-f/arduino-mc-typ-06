/*
 mc-typ-06 ver :1.0
*/

#include <MsTimer2.h>

String MC_ID ="0";

#define SENSOR 0
#define SENSOR_1 1
#define SENSOR_2 2
#define SENSOR_3 3

String get_zeroStr(String sStr, int nWidth){
  String ret="";
  String buf="000000";
  buf=buf + sStr;
  int nLen = buf.length();  
  int nPos= nLen -nWidth;
  ret=buf.substring(nPos);
  return ret;
}
void timer_func() {
    proc_start();
}

void proc_start() {
  int iSen =0;
  int iSen2=0;
  int iSen3=0;
  int iSen4=0;  
  iSen=analogRead(SENSOR);
  iSen2 =analogRead(SENSOR_1);
  iSen3 =analogRead(SENSOR_2);
  iSen4 =analogRead(SENSOR_3);
  
  String sSen  = String(iSen);
  String sSen2  = String(iSen2);
  String sSen3  = String(iSen3);
  String sSen4  = String(iSen4);  
  sSen  = get_zeroStr(sSen ,4);
  sSen2 = get_zeroStr(sSen2 ,4);
  sSen3 = get_zeroStr(sSen3 ,4);
  sSen4 = get_zeroStr(sSen4 ,4);
  String sMc_id = get_zeroStr(MC_ID, 4);
  
  String sPut="put_dat=";
  sPut.concat(sMc_id); //mc
  sPut.concat(sSen);
  sPut.concat(sSen2);
  sPut.concat(sSen3);
  sPut.concat(sSen4);  
  sPut.concat("0000");
  Serial.println(sPut);
}

void setup() {
  pinMode(SENSOR ,INPUT);
  pinMode(SENSOR_1 ,INPUT);  
  pinMode(SENSOR_2 ,INPUT);
  pinMode(SENSOR_3 ,INPUT); 
  Serial.begin(9600);
  
  MsTimer2::set( 10000, timer_func); 
  MsTimer2::start();  
}

void loop() {
}



