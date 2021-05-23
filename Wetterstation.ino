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

    //
}

void loop()
{

}