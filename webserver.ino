#include <ESP8266WiFi.h>

const char* ssid = "SSID";
const char* password ="PASSWORD";


WiFiServer server(80);
WiFiClient client;



void setup() {

 

 
  Serial.begin(115200);
  
  WiFi.begin(ssid,password);
  server.setNoDelay(true);
  server.begin();  

  while (WiFi.status() != WL_CONNECTED) { delay(100); }
  
}

void loop() {

client = server.available();
if (!client) { return;} 

 String req="";
 
 int contador=0;
 while(!client.connected()) {delay(1);contador++;if(contador>10){return;}}
 contador=0;
 while(!client.available()) {delay(1);contador++;if(contador>10){return;}}

 char c;
 do{          
    c = client.read();
    req+=c; 
    //Serial.println(req);Serial.println("\r\n");       
 }while(c!='\n');
          
if(req.indexOf("/ ")!=-1){
  
  client.print("<html>HOLA CARACOLA</html>\r\n\r\n");
   
}


client.flush();
client.stop();   
client.stopAll();  

}
