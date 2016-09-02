int pinOUT = 13; 
int redLED = 7;
int greenLED = 8;
int state = 0;
int flag = 0; 
 
void setup() {
 pinMode(13, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(7,OUTPUT);
 digitalWrite(pinOUT, LOW);
 digitalWrite(redLED, HIGH);
 digitalWrite(greenLED, LOW);
 Serial.begin(9600); // Default connection rate for my BT module
}
 
void loop() {

 if(Serial.available() > 0){
 state = Serial.read();
 flag=0;
 }

 if (state == '0') {
 digitalWrite(pinOUT, LOW);
 digitalWrite(redLED, HIGH);
 digitalWrite(greenLED, LOW);
 if(flag == 0){
 Serial.println("Relay: off, Red: on");
 flag = 1;
 }
 }

 else if (state == '1') {
 digitalWrite(pinOUT, HIGH);
 digitalWrite(greenLED, HIGH);
 digitalWrite(redLED, LOW);
 if(flag == 0){
 Serial.println("Relay: on, Green: on");
 flag = 1;
 }
 }
}
