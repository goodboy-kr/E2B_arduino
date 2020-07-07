#include "E2B.h"
E2B E2B;

void setup() {
  Serial.begin(9600);

  //please m_init to initialize character(a~z, 1~0 , ', ! ? ...' )
  E2B.m_init();

  //a -> braille
  int a[6] = {1, 0, 0, 0, 0, 0}; //a
  Serial.println(E2B.B_E(a));

  //, -> braille
  int x[6] = {0, 1, 0, 0, 0, 0}; //,
  Serial.println(E2B.B_E(x));

  //A -> braille
  int cap[6] = {0, 0, 0, 0, 0, 1};//cap
  int cap_a[6] = {1, 0, 0, 0, 0, 0}; //a
  Serial.println(E2B.B_E(cap));// ' '
  Serial.println(E2B.B_E(cap_a));// A

  //1 -> braille
  int num[6] = {0, 0, 1, 1, 1, 1};//num
  int num_1[6] = { 1, 0, 0, 0, 0, 0};//1
  Serial.println(E2B.B_E(num));// ' '  
  Serial.println(E2B.B_E(num_1));//'1'  
}

void loop() {
  if (Serial.available()) {
    Serial.println(E2B.E_B(Serial.read()));
  }
}
