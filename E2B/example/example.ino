#include "E2B.h"
E2B E2B;

int Braille[6];



void setup() {
  Serial.begin(9600);

  //please m_init to initialize character(a~z, 1~0 , ', ! ? ...' )
  E2B.m_init();
}

void loop() {
  if(Serial.available()){
    Serial.println(E2B.E_B(Serial.read()));
  }
}
