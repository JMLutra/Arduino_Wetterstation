/*
 * Author       : Johannes Münch 
*/
#include <TH02_dev.h>
#include <Wire.h>

void setup()
{
    Serial.begin(9600); //Startet den Seriellen Output

    Serial.println("**** Wetterstation auf Basis der Grove Sensoren****\n");
    //Verzögerung bis die Spannung stabil ist
    delay(150);

    //Setzt den Temp/Hum Sensor (HP20x_dev) zurück
    TH02.begin();
    delay(100);

    //Zeigt an ob die Wetterstaion bereit ist 
    Serial.println("Die Wetterstation ist bereit"); 
}

void loop()
{
    Serial.println("------------------");
    delay(250);

    float temp = TH02.ReadTemperature();
    float hum = TH02.ReadHumidity();

    Serial.println("Temperatur: ");
    Serial.print(temp);
    Serial.print("C");
    Serial.println("Luftfeuchtigkeit: ");
    Serial.print(hum);
    Serial.print("%");
    delay(750);
}