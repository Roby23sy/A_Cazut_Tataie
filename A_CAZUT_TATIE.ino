
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int buzzPin= 7; // I/O-pin from buzzer connects here 
int redpin = 13; //select the pin for the red LED
int bluepin =11; // select the pin for the  blue LED
int greenpin =12;// select the pin for the green LED

void setup()
{
    pinMode(buzzPin,OUTPUT); // Set buzzer-pin as output
    pinMode(redpin, OUTPUT);
    pinMode(bluepin, OUTPUT);
    pinMode(greenpin, OUTPUT);
    Serial.begin(115200);

  Serial.println("Initialize MPU6050");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  // If you want, you can set accelerometer offsets
  // mpu.setAccelOffsetX();
  // mpu.setAccelOffsetY();
  // mpu.setAccelOffsetZ();
  
  checkSettings();
}

void checkSettings()
{
  Serial.println();
  
  Serial.print(" * Sleep Mode:            ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");
  
  Serial.print(" * Clock Source:          ");
  switch(mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }
  
  Serial.print(" * Accelerometer:         ");
  switch(mpu.getRange())
  {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }  

  Serial.print(" * Accelerometer offsets: ");
  Serial.print(mpu.getAccelOffsetX());
  Serial.print(" / ");
  Serial.print(mpu.getAccelOffsetY());
  Serial.print(" / ");
  Serial.println(mpu.getAccelOffsetZ());
  
  Serial.println();
}

void loop()
{
   digitalWrite(buzzPin, HIGH);

  float vector;
  
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  
  vector = sqrt ( normAccel.XAxis*normAccel.XAxis + normAccel.YAxis*normAccel.YAxis +normAccel.ZAxis*normAccel.ZAxis ) - 9.7;

  if(vector < 0.1) vector = 0;
  
  if(vector <5) {
    analogWrite(redpin, 0);
   analogWrite(bluepin, 0);
   analogWrite(greenpin, 100);
    }
  if(vector >= 5 && vector < 15) {
    analogWrite(redpin, 100);
   analogWrite(bluepin, 0);
   analogWrite(greenpin, 100);
   delay(10);
    }

    if(vector >= 15 && vector <= 20) {
    analogWrite(redpin, 204);
   analogWrite(bluepin, 204);
   analogWrite(greenpin, 0);
   delay(10);
    }
    
  if(vector > 20){
  Serial.print(" G_FORCE = ");
  Serial.println(vector);
   alarm();
  }
  delay(10);
  
}

void alarm(){
    
   digitalWrite(buzzPin,LOW);

 
   
   analogWrite(redpin, 255);
   analogWrite(bluepin, 0);
   analogWrite(greenpin, 0);

    
  Serial.println("  Asteptam sa se Ridice tataia :( ");
  
  delay(1000);

  analogWrite(redpin, 0);
   analogWrite(bluepin, 255);
   analogWrite(greenpin, 0);

  delay(1000);
   
   analogWrite(redpin, 255);
   analogWrite(bluepin, 0);
   analogWrite(greenpin, 0); 

  delay(1000);

  analogWrite(redpin, 0);
   analogWrite(bluepin, 255);
   analogWrite(greenpin, 0);


   
  digitalWrite(buzzPin,HIGH);

  
  Serial.println("  Asteptam sa  Cada tataia :D ");
  
return;
}
