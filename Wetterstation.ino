/*
 * Author       : Johannes Münch 
*/

//Wird für alles benötigt
#include <Wire.h>
//Temp_Hum Sensor
#include <TH02_dev.h>
//Barometer
#include <HP20x_dev.h>
//Sonnenlicht
#include <SI114X.h>


SI114X SI1145 = SI114X();

int i = 1;

void setup()
{
  Serial.begin(9600); //Startet den Seriellen Output

  Serial.println("****Wetterstation auf Basis der Grove Sensoren**** \nEntwickelt von Johannes Muench, Code einsehbar auf GitHub \nhttps://github.com/JMLutra/Arduino_Wetterstation \n");
  //Verzögerung bis die Spannung stabil ist
  delay(150);
  
  //Setzt den Temp/Hum Sensor (TH02_dev) zurück
  TH02.begin();
  delay(100);
  //Setzt das Barometer (HP20x_dev) zurück
  HP20x.begin();
  delay(100);
  HP20x.ReadTemperature(); 
  Serial.println("Die Wetterstation ist bereit.");
  delay(5000);
}

void loop()
{
  Serial.print("Messung Nr.: ");
  Serial.println(i);
  i++;
  Serial.print("\n");

  //Temp_Hum
  float temp = TH02.ReadTemperature();
  float hum = TH02.ReadHumidity();
  //Barometer 
  
  float pres = HP20x.ReadPressure()/100.0;
  int alt = HP20x.ReadAltitude()/100;

  //Output Serieller Monitor
  /*Temp_Hum*/
  Serial.println("Temperatur: ");
  Serial.print(temp);
  Serial.println("C");
  Serial.println("Luftfeuchtigkeit: ");
  Serial.print(hum);
  Serial.println("%");
  Serial.println("-------------------");
  /*Barometer*/
  Serial.println("Luftdruck: ");
  Serial.print(pres);
  Serial.println("hPa");
  Serial.println("Hoehe ue NN: ");
  Serial.print(alt);
  Serial.println("m");
  Serial.println("~~~~~~~~~~~~~~~~~ \n");

  delay(5000);

}