#include <Servo.h> 

/**
* Create servo object to control a servo 
* A maximum of ei8rvo objects can be created 
*/

Servo ankle_R;
Servo ankle_L;
Servo knee_R;
Servo knee_L;

//SPEAKER (PWM pin)
int speaker_pin = 11;
//LED (Use pin 13 for built-in LED)
int led_pin = 13;

//FREQUENCIES
#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  ankle_R.attach(9);
  ankle_L.attach(10);  // attaches the servo on pin 9 to the servo object 
  knee_R.attach(5);
  knee_L.attach(6);
  
  pinMode(led_pin, OUTPUT);
  pinMode(speaker_pin, OUTPUT);
} 
 
 
void loop() 
{ 
  reset();
  confirm();
  shake(2000);
  jump(3000);
  walk_in_place(3000);
  dance(3000);
  split();
  jump(1000);
  tip_toe();
//  starwars();
  
}


void reset() {
  // Reset
  knee_R.write(90);
  knee_L.write(90);
  ankle_R.write(90);
  ankle_L.write(90);
  delay(1000);
}

void beep (int speaker_pin, int freqHz, long timeMs)
{
  digitalWrite(led_pin, HIGH);
  
  double timeDelay = (double)(1000000/freqHz);
  double timeLoop = (double)((timeMs*1000)/(timeDelay*2));
  
  for(int i = 0; i < timeLoop; i++)
  {
    digitalWrite(speaker_pin, HIGH);
    delayMicroseconds(timeDelay);
    digitalWrite(speaker_pin, LOW);
    delayMicroseconds(timeDelay);
  }
  
  digitalWrite(led_pin, LOW);
  delay(20);
}

void confirm() {
  for(pos = 45; pos < 90; pos += 1) {  
    ankle_R.write(pos); 
    ankle_L.write(180 - pos);
    delay(5);    
  }
  beep(speaker_pin, cH, 200);
  
  
  for(pos = 45; pos < 90; pos += 1) {                                    
    ankle_R.write(pos); 
    ankle_L.write(180 - pos);
    delay(5);    
  }
  beep(speaker_pin, cH, 200);
  
  delay(3000);
}

void jump(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start <= duration) {
    for(pos = 45; pos < 90; pos += 1) {                                    
      ankle_R.write(pos); 
      ankle_L.write(180 - pos);
      delay(3);    
    }
  }
  delay(1000);
}

void walk_in_place(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start <= duration) {
    for(pos = 45; pos < 90; pos += 1) {                                    
    ankle_R.write(pos); 
    delay(10);    
    }
    
    for(pos = 135; pos>=90; pos-=1) {           
      ankle_L.write(pos); 
      delay(10);    
    } 
  }
  delay(1000);
}

void shake(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start <= duration) {
    for(pos = 45; pos < 90; pos += 1) {                                 
      knee_R.write(pos);     
      ankle_R.write(pos);     
    }
    
    for(pos = 135; pos>=90; pos-=1) {       
      knee_L.write(pos);     
      ankle_L.write(pos);                           
    }
  }
  delay(1000);
}

void dance(unsigned long duration) {
  unsigned long start = millis();
  while (millis() - start <= duration) {
    // Right Up 
    for(pos = 45; pos < 90; pos += 1) {                                 
      knee_R.write(pos);     
      knee_L.write(pos);
      ankle_R.write(pos);     
      ankle_L.write(pos);
      delay(15);  
          
    }
    
    for(pos = 45; pos < 90; pos += 1) {                                 
      knee_R.write(pos);     
      knee_L.write(pos);
      ankle_R.write(pos);     
      ankle_L.write(pos);
      delay(15);  
          
    }
    
    // Left Up
    for(pos = 135; pos>=90; pos-=1) { 
      knee_R.write(pos);      
      knee_L.write(pos);  
      ankle_R.write(pos);      
      ankle_L.write(pos);      
      delay(15);                      
    } 
    
    for(pos = 135; pos>=90; pos-=1) { 
      knee_R.write(pos);      
      knee_L.write(pos);  
      ankle_R.write(pos);      
      ankle_L.write(pos);      
      delay(15);                      
    } 
    
    
    // Right-Left Up
    for(pos = 45; pos < 90; pos += 1) {                                 
      knee_R.write(pos);     
      knee_L.write(pos);
      ankle_R.write(pos);     
      ankle_L.write(pos);
      delay(15);                  
    }
    
    for(pos = 135; pos>=90; pos-=1) { 
      knee_R.write(pos);      
      knee_L.write(pos);  
      ankle_R.write(pos);      
      ankle_L.write(pos);      
      delay(15);                      
    } 
    
    for(pos = 45; pos < 90; pos += 1) {                                 
      knee_R.write(pos);     
      knee_L.write(pos);
      ankle_R.write(pos);     
      ankle_L.write(pos);
      delay(15);                  
    }
  
    for(pos = 135; pos>=90; pos-=1) { 
      knee_R.write(pos);      
      knee_L.write(pos);  
      ankle_R.write(pos);      
      ankle_L.write(pos);      
      delay(15);                      
    }
  }
  delay(1000);
}

void tip_toe() {    
  ankle_L.write(150);         
  ankle_R.write(30);     
  delay(1000);  
}

void split() {    
  ankle_L.write(0);         
  ankle_R.write(180);     
  delay(1000);  
}

void starwars() {
  beep(speaker_pin, a, 500); 
  beep(speaker_pin, a, 500);
  beep(speaker_pin, a, 500);
  beep(speaker_pin, f, 350);
  beep(speaker_pin, cH, 150);
  
  beep(speaker_pin, a, 500);
  beep(speaker_pin, f, 350);
  beep(speaker_pin, cH, 150);
  beep(speaker_pin, a, 1000);
  beep(speaker_pin, eH, 500);
  
  beep(speaker_pin, eH, 500);
  beep(speaker_pin, eH, 500);
  beep(speaker_pin, fH, 350);
  beep(speaker_pin, cH, 150);
  beep(speaker_pin, gS, 500);
  
  beep(speaker_pin, f, 350);
  beep(speaker_pin, cH, 150);
  beep(speaker_pin, a, 1000);
  beep(speaker_pin, aH, 500);
  beep(speaker_pin, a, 350);
  
  beep(speaker_pin, a, 150);
  beep(speaker_pin, aH, 500);
  beep(speaker_pin, gHS, 250);
  beep(speaker_pin, gH, 250);
  beep(speaker_pin, fHS, 125);
  
  beep(speaker_pin, fH, 125);
  beep(speaker_pin, fHS, 250);
  
  delay(250);
  
  beep(speaker_pin, aS, 250);
  beep(speaker_pin, dHS, 500);
  beep(speaker_pin, dH, 250);
  beep(speaker_pin, cHS, 250);
  beep(speaker_pin, cH, 125);
  
  beep(speaker_pin, b, 125);
  beep(speaker_pin, cH, 250);
  
  delay(250);
  
  beep(speaker_pin, f, 125);
  beep(speaker_pin, gS, 500);
  beep(speaker_pin, f, 375);
  beep(speaker_pin, a, 125);
  beep(speaker_pin, cH, 500);
  
  beep(speaker_pin, a, 375);
  beep(speaker_pin, cH, 125);
  beep(speaker_pin, eH, 1000);
  beep(speaker_pin, aH, 500);
  beep(speaker_pin, a, 350);
  
  beep(speaker_pin, a, 150);
  beep(speaker_pin, aH, 500);
  beep(speaker_pin, gHS, 250);
  beep(speaker_pin, gH, 250);
  beep(speaker_pin, fHS, 125);
  
  beep(speaker_pin, fH, 125);
  beep(speaker_pin, fHS, 250);
  
  delay(250);
  
  beep(speaker_pin, aS, 250);
  beep(speaker_pin, dHS, 500);
  beep(speaker_pin, dH, 250);
  beep(speaker_pin, cHS, 250);
  beep(speaker_pin, cH, 125);
  
  beep(speaker_pin, b, 125);
  beep(speaker_pin, cH, 250);
  
  delay(250);
  
  beep(speaker_pin, f, 250);
  beep(speaker_pin, gS, 500);
  beep(speaker_pin, f, 375);
  beep(speaker_pin, cH, 125);
  beep(speaker_pin, a, 500);
  
  beep(speaker_pin, f, 375);
  beep(speaker_pin, c, 125);
  beep(speaker_pin, a, 1000);
}
