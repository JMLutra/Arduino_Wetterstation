/*
 * Author       : Johannes Münch 
*/

//Wird für alles benötigt
#include <Wire.h>
//Temp_Hum Sensor
#include <TH02_dev.h>
//Barometer
#include <HP20x_dev.h>

int i = 0;
void setup()
{
    Serial.begin(9600); //Startet den Seriellen Output

    Serial.println("**** Wetterstation auf Basis der Grove Sensoren****\n");
    //Verzögerung bis die Spannung stabil ist
    delay(150);

    //Setzt den Temp/Hum Sensor (HP20x_dev) zurück
    TH02.begin();
    delay(100);
    //Setzt das Barometer (HP20x_dev) zurück
    HP20x.begin();
    delay(100);

    //Zeigt an ob die Wetterstaion bereit ist 
    Serial.println("Die Wetterstation ist bereit.");
    Serial.println("Folgende Module sind verfügbar: ");

    //testet Temp_Hum Sensor
    if (TH02.isAvailable())
    {
         Serial.println("Temperatur(1) \nLuftfeuchtigkeit");
    }
    //Testet Barometer
    if (HP20x.isAvailable())
    {
        Serial.println("Temperatur(2) \nLuftdruck \nHöhenanzeige");
    }
}

void loop()
{
    Serial.println("~~~~~~~~~~~~~~~~~");
    Serial.println("Messung Nr.:");
    Serial.print(i);
    i++;
    delay(250);

    //Temp_Hum
    float temp = TH02.ReadTemperature();
    float hum = TH02.ReadHumidity();

    //Barometer 
    float temp2 = HP20x.ReadTemperature()/100.0;
    float pres = HP20x.ReadPressure()/100.0;
    float alt = HP20x.ReadAltitude()/100.0;

    //Output Serieller Monitor
    /*Temp_Hum*/
    Serial.println("Temperatur 1: ");
    Serial.print(temp);
    Serial.print("C");

    Serial.println("Luftfeuchtigkeit: ");
    Serial.print(hum);
    Serial.print("%");

    Serial.println("-------------------");
    /*Barometer*/
    Serial.println("Temperatur 2: ");
    Serial.print(temp2);
    Serial.println("C. \n");

    Serial.println("Luftdruck: ");
    Serial.print(pres);
    Serial.println("hPa.\n");

    Serial.println("Höhe ü NN: ");
    Serial.print(alt);
    Serial.println("m.\n");

    delay(750);
}