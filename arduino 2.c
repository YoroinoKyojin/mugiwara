#include <SoftwareSerial.h>

#define TX_PIN 2
#define RX_PIN 3

SoftwareSerial transceiver(TX_PIN, RX_PIN);

void setup()
{
  Serial.begin(9600);
  transceiver.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    char data = Serial.read();
    transceiver.write(data);
  }

  if (transceiver.available())
  {
    char data = transceiver.read();
    Serial.print("Received data: ");
    Serial.println(data);
  }
}
