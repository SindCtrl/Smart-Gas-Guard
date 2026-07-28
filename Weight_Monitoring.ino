#include <HX711.h>

// HX711 Pins
#define DOUT 11
#define CLK 13

// Calibration Factor
float calibration_factor = -11200;

// HX711 Object
HX711 scale;

void setup()
{
  Serial.begin(9600);

  Serial.println("HX711 Calibration");
  Serial.println("Press '+' to increase calibration factor.");
  Serial.println("Press '-' to decrease calibration factor.");

  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare();

  Serial.println("Scale is ready.");
}

void loop()
{
  scale.set_scale(calibration_factor);

  float weight = scale.get_units() * 0.453592;

  Serial.print("Weight: ");
  Serial.print(weight, 1);
  Serial.print(" Kg");

  Serial.print(" | Calibration Factor: ");
  Serial.println(calibration_factor);

  if (Serial.available())
  {
    char temp = Serial.read();

    if (temp == '+')
      calibration_factor += 20;

    else if (temp == '-')
      calibration_factor -= 20;
  }

  delay(500);
}
