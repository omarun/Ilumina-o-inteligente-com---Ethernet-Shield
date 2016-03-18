/*
* Automação com Arduino e Ethernet Shield W5100 : Luzes e Iluminação.
*RaFa NaTuRaL - https://github.com/theanonybay
*/

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };    // Endereço do Mac Físico.
byte ip[] = { 192, 168, 0, 177 };                       // Ip Lan (É o que você precisa para fazer a comunicação com seu browser. ( "192.168.1.178 é o PADRÃO").
byte gateway[] = { 192, 168, 0, 1 };                   // internet access via router.
byte subnet[] = { 255, 255, 255, 0 };                  // máscara de sub-rede.

EthernetServer server(80); // porta do servidor.
  
String readString;
int Pin = 4; // Porta aonde se encontra o LED.
 
void setup(){
  
  pinMode(Pin, OUTPUT);
  Ethernet.begin(mac, ip);
  server.begin();

}
  
void loop(){

  //Cria uma conexão de cliente.
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
  //Ler caractere por caractere pedido em HTTP.
        if (readString.length() < 100) {
  // armazena caracteres para string.
          readString += c;        
  //Serial.print(c);     
        }
 
        if (c == '\n') {
          Serial.println(readString); //imprimir para o monitor o serial para depuração.
          client.println("HTTP/1.1 200 OK"); //Enviar uma nova pagina
          client.println("Content-Type: text/html");
          client.println();
           
          client.println("<HTML>");
          client.println("<BODY>");
          client.println("<link rel='stylesheet' type='text/css' href=\"http://globocom.github.io/bootstrap/assets/css/bootstrap.css\" />");
          client.println("<hr />");
          client.println("<br />");
          client.println("<div class=\"row-fluid\">");
          client.println("<center><H1><img src=\"http://i.imgur.com/KqPiHyC.png\"></H1>");
 
          client.println("<a href=\"/?ledon\" class=\"btn btn-success\"><i class=\"icon-play\"></i> Ligar o led</a>");
          client.println("<a href=\"/?ledoff\" class=\"btn btn-danger\" > <i class=\"icon-stop\"></i> Desligar o led</a><br />");   
           
          client.println("</BODY>");
          client.println("</HTML>");
           
          delay(1);
          client.stop();
           //Controlando o Arduino ao pressionar os botões
          if(readString.indexOf("?ledon") > 0)
          {
            digitalWrite(Pin, HIGH);
          }
          else {
            if(readString.indexOf("?ledoff") > 0)
            {
              digitalWrite(Pin, LOW);
            }
          }
          //Sequência de compensação para próxima leitura
          readString="";    
        }
      }
    }
  }
}
