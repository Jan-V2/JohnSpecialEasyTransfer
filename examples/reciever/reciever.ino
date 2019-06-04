//idp code
//motoraansturing en bluetooth ontvanger

//adres van de slave: 98d3:31:fd1781

//liberaries
#include "JohnsSpecialEasyTransfer.h"

JohnsSpecialEasyTransfer conn;

void setup() {
    Serial.begin(38400);
    Serial1.begin(38400);
    conn.begin(&Serial1);
    conn.add_recieve_int("J1_Xas", 512);
    conn.add_recieve_int("J1_Yas", 512);
    conn.add_recieve_int("bla", 0);
}

void loop() {
  conn.update();
  int x_as = conn.get_int("J1_Xas");
  int y_as = conn.get_int("J1_Yas");
  Serial.println("x_as:" + String(x_as));
  Serial.println("y_as:" + String(y_as));
  Serial.println("bla" + String(conn.get_int("bla")));
  Serial.println("");
	delay(5);
}
