#include <Arduino.h>
#include <HX711.h>

float calibration = 83.5;

HX711 pedal_1;
HX711 pedal_2;
HX711 pedal_3;

void setup() {

  Serial.begin(57600);
  pedal_1.begin(PB11, PB10);
  pedal_2.begin(PB12, PB13);
  pedal_3.begin(PB14, PB15);

  pedal_1.set_scale(calibration);
  pedal_2.set_scale(calibration);
  pedal_3.set_scale(calibration);

  pedal_1.tare();
  pedal_2.tare();
  pedal_3.tare();

  Serial.print("Resultados:");
}

void loop() {

  Serial.print("\n\nPedal 1:");
  Serial.print(pedal_1.get_units(), 1);
  Serial.print("\nPedal 2:");
  Serial.print(pedal_2.get_units(), 1);
  Serial.print("\nPedal 3:");
  Serial.print(pedal_3.get_units(), 1);
  delay(5000);
}
