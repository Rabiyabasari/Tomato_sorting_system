const int stepPin = 5; // define pin for step
const int dirPin = 6;  // define pin for direction
const int Enable = 7;
const int IR1 = 8;
void setup() {
 pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(Enable, OUTPUT);
  
}

void loop() {
  digitalWrite(dirPin, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
 
 for(int x = 0; x<200; x++) { // loop for 200 steps
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(6000);
  digitalWrite(stepPin,LOW); 
  delayMicroseconds(6000);
 }

}
