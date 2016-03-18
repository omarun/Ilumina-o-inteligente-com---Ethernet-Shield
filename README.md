#Iluminação Inteligente
Automação com Arduino e Ethernet Shield W5100 : Luzes e Iluminação.

Com o Ethernet Shield, é possível conectar o Arduino a uma rede ethernet e montar projetos que envolvam o envio ou recebimento de informações via rede ou internet. O dispositivo, juntamente com a biblioteca de controle, permite o projeto de aplicações para rede de forma fácil. Não é necessário se preocupar com os esquemas complicados de sinalização em redes ethernet já que todo o controle e conexão são feitos por rotinas da biblioteca. Após estabelecida a conexão, basta ler ou escrever dados através dela, de forma semelhante à uma conexão serial convencional.

Segue um exemplo de um projeto para a disponibilização de uma página web que permite ligar ou desligar um LED através da rede local ou da internet. Em uma aplicação prática, o projeto poderia ser utilizado para controlar uma lâmpada de sua casa, servindo como uma boa aplicação “Hello World” de automação residencial com Arduino. Aqui, a ideia é se concentrar no projeto de software necessário para tal aplicação. Por isso, vamos considerar a ligação de um led à porta do Arduino e mostrar uma das formas mais caras de acender um led que podem ser propostas.

Neste projeto, foi utilizado o Ethernet Shield baseado no chip Wiznet W5100. Esse chip provê toda a pilha TCP/IP de forma transparente, facilitando o projeto, já que não é necessário se preocupar com os esquemas de sinalização e controles do TCP/IP. Vale lembrar que existem outros shields ethernet, mais simples e mais baratos, que utilizam chips que exigem que os controles e a sinalização TCP/IP sejam implementados no sketch Arduino.

A configuração de harware para este projeto é muito simples: basta conectar o Ethernet Shield ao Arduino e ligar um led em série com um resistor de 220 entre o pino 4 do Shield e o terra (GND).

