#include<Servo.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

Servo servo1;
Servo servo2;
int function= 0;
int redtomato =0;
int halfripetomato =0;
int i=0;
int j=0;
int k=0;
int l=0;
#define S0 2 //colour sensor pins
#define S1 3 //colour sensor pins
#define S2 4 //colour sensor pins
#define S3 5 //colour sensor pins
#define sensorOut 6  //colour sensor pins
const int IR1 =7; //sensor 1  which is near to colour sensor
const int IR2 =8; //sensor 2  which is near to Servo 1
const int IR3 =9; //sensor 3  which is near to Servo 2
int redfrequency = 0; // colour sensor function
int greenfrequency = 0; // colour sensor function
int bluefrequency = 0; // colour sensor function
/*#define half()
#define Total()
#define Ripe()
#define Unripe()*/
void setup() {

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR2, INPUT);
  
  lcd.init();
  lcd.backlight();

  lcd.setCursor(1,1);
  lcd.print("Welcome To Tomato");

  lcd.setCursor(1,0);
  lcd.print("Sorting Machine");

  lcd.clear();
  
  servo1.attach(10);  
  servo1.write(0); 

  servo2.attach(11);  
  servo2.write(0); 


  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Pulse Width scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Setup Serial Monitor
  Serial.begin(9600);
  delay(500);
  Serial.println("Conveyor Started");
}
void loop() {
  
  int sensor2 = digitalRead(IR2);
  int Sensor1 = digitalRead(IR1);
  int sensor3 = digitalRead(IR3);

  if (Sensor1 == LOW)
  {     
   function = 1;
  }
  
  if(function == 1)
  {
    delay(10);
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
   redfrequency = pulseIn(sensorOut, LOW);
   Serial.print(redfrequency);
   Serial.print("    ");
   delay(100);
  
   // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
 Serial.print(greenfrequency);
 Serial.println("    ");

  delay(100);
  }
 /* // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
Serial.print(bluefrequency);
 Serial.println("    ");*/

  
if (redfrequency >=50 && redfrequency <= 70 && function ==1 )//&& greenfrequency >=100 && greenfrequency >=150)
  {
     redtomato =1;
     Serial.println("ripe tomato");
     delay(50);
     function =0;
  }
  
if (redfrequency >=80 && redfrequency <= 100 && function ==1)//&& greenfrequency >=120 && greenfrequency >=150)
  {
    halfripetomato =1;
    Serial.println("half ripe tomato");
    delay(50);
    function =0; 
  }
  if (redfrequency >=180 && redfrequency <= 220 && function ==1)// && greenfrequency >=180 && greenfrequency >=220)
  {  
    half();
    Total();
    Serial.println("unripe tomato");
    delay(50);
    function =0;
 
  }
  if(redtomato ==1 && sensor2 == LOW){
    delay(700); 
    servo1.write(180);
    delay(1000);
    servo1.write(0);
    
    Ripe();
    Total();
    delay(700);
    redtomato =0;
 
  } 
  if(halfripetomato ==1 && sensor3 == LOW){
    delay(800); 
    servo2.write(180);
    delay(1000);
    servo2.write(0);
    
    halfripe();
    Total();
    delay(700);
    halfripetomato =0;
 
  }
  }


 

