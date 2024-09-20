#include <Gyver433.h>
#include <EncButton.h>
Button btn1(11);
Gyver433_TX<2> tx;
Gyver433_RX<3> rx;


void setup() {
  Serial.begin(9600);
  attachInterrupt(0, isr, CHANGE);
}

void isr() {
  rx.tickISR();
}

void loop() {
  btn1.tick();
  if (rx.gotData()) {
    Serial.write(rx.buffer, rx.size);
    Serial.println();
  }
  if (btn1.click()) {
    tx.sendData("OFXIEW ON THE TOP");
    Serial.print("Sended");
  }
}
