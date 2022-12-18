//  using DHT11 with ESP32
//  measuring humidity and temperature
//  getting all SI units for temperature and humidity

//  including DHT library to use the sensor
#include<DHT.h>

//  declaring sensor pin
byte sensor_pin = 4;

//  macro for type of sensor used
#define sensor_type DHT11

//  making object using constructor
DHT dht_sensor(sensor_pin , sensor_type);

const byte r_pin = 25;  //  GPIO 25,26,27
const byte g_pin = 26;
const byte b_pin = 27;

//  channel
const byte r_channel = 0;
const byte g_channel = 1;
const byte b_channel = 2;

//  frequency and resolution
const int frequency = 5000;
const int resolution = 8;

void setup(){

  //  serial communication
  Serial.begin(115200);
  
  

  //  initialize the DHT sensor
  dht_sensor.begin();
  

  //  setup function
  ledcSetup(r_channel , frequency , resolution);
  ledcSetup(g_channel , frequency , resolution);
  ledcSetup(b_channel , frequency , resolution);

  //  attaching channel with pin
  ledcAttachPin(r_pin , r_channel);
  ledcAttachPin(g_pin , g_channel);
  ledcAttachPin(b_pin , b_channel);
  
}

void loop(){

  //  calculating temperature in celcius
  float temp_c = dht_sensor.readTemperature();  //  DHT works in 0 to 50 deg celcius
  float temp_f = dht_sensor.readTemperature(true);
  float temp_k = temp_c+273.15
  float hum_d = dht_sensor.readHumidity();
  float hum_dew = (temp_c-(100-hum_d)/5);
  //  calculate temperature in fahrenheit


  //  calculate temperature in kelevin


  //  calculate relative humidity


  //  calculating dew point



  //  check if temp_c and other variables are not numbers, then return
  if (isnan(temp_c) || isnan(temp_f) || isnan(hum_d)) {
    Serial.println("Can't get temperature and humidity");
    return;
  }

  //  print all the values
  Serial.print("Temperature:");
  Serial.print(temp_c);
  Serial.println("*C");
  Serial.print("Temperature:");
  Serial.print(temp_f);  
  Serial.println("*F");
  Serial.print("Temperature:");
  Serial.print(temp_k);  
  Serial.println("*K");
  Serial.print("Humidity:");
  Serial.print(hum_d);
  Serial.println("RH");
  Serial.print("Humidity");
  Serial.print(hum_dew);
  Serial.println("%RH");

  //  wait for 2 seconds
  delay(2000);  //  sensor is slow, wait for 2 sec, before taking new readings
  
}
