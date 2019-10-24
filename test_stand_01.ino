// Spindle Motor Driver
// Gennady N "ElectRony LTD"
// 1/12/2014

int pulsePin1 = 5;
int pulsePin2 = 6;
int pulsePin3 = 7;
int programmbutton=4;
int speedbutton001 = 10;
int speedbutton010 = 11;
int speedbutton100 = 12;
int pulsespeed = 1;
int pulsewidth =7;
 int buttonState001=0;
 int buttonState010=0;
 int buttonState100=0;
 int  buttonStateProg=0;
void setup()
{
 // Serial.begin(9600);
  
pinMode(pulsePin1, OUTPUT);
pinMode(pulsePin2, OUTPUT);
pinMode(pulsePin3, OUTPUT);
pinMode(speedbutton001, INPUT);
pinMode(speedbutton010, INPUT);
pinMode(speedbutton100, INPUT);
pinMode( programmbutton, INPUT);
//digitalWrite(speedbutton001, LOW);
//digitalWrite(speedbutton010, LOW);
//digitalWrite(speedbutton100, LOW);
//digitalWrite( programmPin, LOW);

/*switch (var) {
 case label:
    // код для выполнения
    break;*/
buttonStateProg = digitalRead(programmbutton);
buttonState001 = digitalRead(speedbutton001);
buttonState010 = digitalRead(speedbutton010);
buttonState100 = digitalRead(speedbutton100);

if ( buttonState001==LOW  && buttonState010==LOW && buttonState100 ==LOW ) {pulsewidth = 1000;} else
if ( buttonState001==LOW && buttonState010==LOW  && buttonState100 ==HIGH ) {pulsewidth = 500;} else
if ( buttonState001==LOW  && buttonState010== HIGH  && buttonState100 == LOW ) {pulsewidth = 300;} else
if ( buttonState001==LOW  && buttonState010==HIGH  && buttonState100 == HIGH ) {pulsewidth = 100;} else
if ( buttonState001== HIGH  && buttonState010==LOW && buttonState100 ==LOW) {pulsewidth = 30;} else
if ( buttonState001==HIGH  && buttonState010==LOW  && buttonState100 ==HIGH ) {pulsewidth = 10;} else
if ( buttonState001==HIGH  && buttonState010==HIGH  && buttonState100 ==LOW ) {pulsewidth = 3;} else
if ( buttonState001==HIGH  && buttonState010==HIGH  && buttonState100 ==HIGH ) {pulsewidth = 1;} 

 //pulsespeed = pulsewidth ;


  //if (programmPin==HIGH) {goto power;}

  
}
  

  
  
void loop()
{
 
//buttonStateProg = digitalRead(programmbutton);
if (buttonStateProg =LOW) {goto power;} else
toppi:
// speedbuttonPin = LOW;
digitalWrite(pulsePin1, HIGH); 
 digitalWrite(pulsePin2, LOW); 
 digitalWrite(pulsePin3, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin1, HIGH);
 digitalWrite(pulsePin2, LOW);
 digitalWrite(pulsePin3, LOW);
delay(pulsewidth);
digitalWrite(pulsePin1, HIGH);
 digitalWrite(pulsePin2, HIGH);
 digitalWrite(pulsePin3, LOW);
delay(pulsewidth);
digitalWrite(pulsePin1, LOW);
 digitalWrite(pulsePin2, HIGH);
 digitalWrite(pulsePin3, LOW);
delay(pulsewidth);
digitalWrite(pulsePin1, LOW);
 digitalWrite(pulsePin2, HIGH);
 digitalWrite(pulsePin3, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin1, LOW);
 digitalWrite(pulsePin2, LOW);
 digitalWrite(pulsePin3, HIGH);
delay(pulsewidth);

 //Serial.println(pulsewidth);
 // delay(1);  
{goto toppi;}
power:

//void loop()
//{
pulsespeed=pulsewidth;

digitalWrite(pulsePin1, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin1, LOW);
delay(pulsespeed); digitalWrite(pulsePin2, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin2, LOW);
delay(pulsespeed); digitalWrite(pulsePin3, HIGH);
delay(pulsewidth);
digitalWrite(pulsePin3, LOW);
delay(pulsespeed);
}
