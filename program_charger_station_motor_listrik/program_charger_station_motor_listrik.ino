
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLMLSzXxfH"
#define BLYNK_DEVICE_NAME "Prototype Charging Baterai Kendaraan Listrik"
#define BLYNK_AUTH_TOKEN "3d1U38NFOgeYXcMSIAcXLBXDjPmWqVtN"
#include <PZEM004Tv30.h>
#include <ESP8266WiFi.h> // include library
#include <BlynkSimpleEsp8266.h> // include library
char auth[] = BLYNK_AUTH_TOKEN ; //Auth Token
char ssid[] = "Tetangga sebelah"; //nama hotspot yang digunakan
char pass[] = "jandabolong123"; //password hotspot yang digunakan
//BlynkTimer timer;
PZEM004Tv30 pzem(14, 12);
float harga_KWh = 1.467; //harga per KWh
int sensorPin = A0;
int sensorValue = 0;

void setup() {
Serial.begin(115200);
pinMode(D6, OUTPUT); 
pinMode(D7, OUTPUT);
pinMode(D8, OUTPUT);// LED sebagai output
Blynk.begin(auth, ssid, pass); //memulai Blynk 
//timer.setInterval(1000L, sendSensor);                                      
}
  void loop() {
 Blynk.run(); 
// timer.run();
    sensorValue=analogRead(sensorPin); //Membaca nilai analog dari pin A5
//    Serial.println (sensorValue); //Mencetak hasil pada monitor serial
    float Voltage =sensorValue * (5.0/1023.0);
   Serial.println(Voltage);
   Serial.print("STATUS = ");
      if(Voltage<=1){ //Ambang batas yang saya gunakan disini adalah bernilai 1
        digitalWrite (D6, HIGH);
        digitalWrite (D7, HIGH);
        digitalWrite (D8, LOW);
        Serial.println("CHARGER");}
      else{
        digitalWrite(D7, LOW);
        digitalWrite (D6, LOW);
        digitalWrite (D8, HIGH);
         Serial.println("FULL");
         
      }
  float voltage = pzem.voltage();
  float current = pzem.current();
  float power = pzem.power();
  float energy = pzem.energy();
  float frequency = pzem.frequency();
  float pf = pzem.pf();
  if (isnan(voltage) ) {
     voltage = 0;
  }
  if (isnan(current) ) {
     current = 0;
  }
  if (isnan(power) ) {
     power = 0;
  }
  if (isnan(energy) ) {
    energy = 0;
        pzem.resetEnergy();
        delay(1000);
  }
  
  float totalHarga = energy * harga_KWh;
  Serial.print("Voltage = ");
  Serial.print(voltage);
  Serial.println("v");
  Serial.print("Current = ");
  Serial.print(current, 2);
  Serial.println("A");
  Serial.print("Frequency: ");    
  Serial.print(frequency, 1); 
  Serial.println("Hz");
  Serial.print("PF: ");           
  Serial.println(pf);
  Serial.print("Watt = ");
  Serial.print(power);
  Serial.println("watt");
  Serial.print("KWh = ");
  Serial.print(energy, 1);
  Serial.println("KWh");
  Serial.print("Harga = Rp ");
  Serial.print(totalHarga, 3); 
  Serial.println();                                                                                                                             
  delay(10);
  Blynk.virtualWrite(V1, voltage); //mengirimkan data temperatur ke Virtual pin VO di Blynk Cloud
  Blynk.virtualWrite(V2, current); //mengirimkan data kelemaban ke Virtual pin V1 di Blynk Cloud
  Blynk.virtualWrite(V0, power); //mengirimkan data temperatur ke Virtual pin VO di Blynk Cloud
  Blynk.virtualWrite(V7, energy); //mengirimkan data kelemaban ke Virtual pin V1 di Blynk Cloud
  Blynk.virtualWrite(V8, totalHarga); //mengirimkan data temperatur ke Virtual pin VO di Blynk Cloud

}  
