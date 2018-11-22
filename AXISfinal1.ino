// Gennady "ElectRony Tech. LTD" circuit - High
int maskfall = 96; //mask 01100000
int rezaltfall;  

int maskspeed = 28; //mask 00011100
int rezaltspeed; 
int pulse; 

int maskduty= 7; //mask 00000111
int rezaltduty; 
int duty;


//int pindos;
void setup()
{

DDRD=DDRD | B11000011 ; // set D registor bit 2,3,4,5 to input
 DDRB=DDRB | B00111000;  // set B registor bit 0,1,2 to input 
}

void pulsewidthset () //pulse value
{ 
  rezaltspeed = (PIND) & maskspeed;
if (rezaltspeed == 28) { pulse=1;}  if (rezaltspeed == 24) { pulse=3;} if (rezaltspeed == 20) { pulse=6;}  if (rezaltspeed == 16) { pulse=12;}
if (rezaltspeed == 12) { pulse=24;}  if (rezaltspeed == 8) { pulse=50;} if (rezaltspeed == 4) { pulse=100;}  if (rezaltspeed == 0) { pulse=300;} 
}
  
 void pulsespeedset () //duty value
  { 
    rezaltduty = (PINB) & maskduty;
  if (rezaltduty ==7) {duty=0;}          if (rezaltduty ==6) {duty=pulse / 2;}   if (rezaltduty==5) {duty=pulse;}  if (rezaltduty ==4) {duty=pulse * 2;} 
  if (rezaltduty ==3) {duty=pulse * 4;}  if (rezaltduty ==2) {duty = pulse * 6;} if (rezaltduty==1) {duty =pulse * 12;} if (rezaltduty ==0) {duty=pulse * 24;}    
  }

  void fall ()
  {
  rezaltfall = (PIND) & maskfall;
   //rezalt &= (~((1<<0)|(1<<1)|(1<<6)|(1<<7)));
  if (rezaltfall ==96) {PORTD = B10000000;} else { PORTD = B00000000; delay(10000);}
} 
  
void loop() 
{ 
 while (1) {
   fall ();
 PORTB = B00100000; // first pulse HIGH B5
 pulsespeedset ();
 delay(pulse);
  PORTB = B00000000;
  pulsewidthset (); 
  delay(duty);
  
  fall ();
PORTB = B00010000; // second pulse HIGH B4
 pulsespeedset ();
 delay(pulse);
  PORTB = B00000000;
  pulsewidthset (); 
  delay(duty); 
  
  fall ();
  PORTB = B00001000; //  pulse HIGH B3
 pulsespeedset ();
 delay(pulse);
  PORTB = B00000000;
  pulsewidthset (); 
  delay(duty);}
}
