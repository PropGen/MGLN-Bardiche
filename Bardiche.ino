#include <PWMServo.h>
#include <Adafruit_Soundboard.h>
#include <SoftwareSerial.h>

#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Adafruit_LEDBackpack.h>

#define SFX_TX 5 //transmitter
#define SFX_RX 6 // reciever
#define SFX_RST 4 //reset

SoftwareSerial ss = SoftwareSerial(SFX_TX, SFX_RX);

Adafruit_Soundboard sfx = Adafruit_Soundboard(&ss, NULL, SFX_RST);

Adafruit_8x16matrix matrix=Adafruit_8x16matrix();
Adafruit_8x16matrix matrix2=Adafruit_8x16matrix();

static const uint8_t PROGMEM
   smile_bmp[] =
  { B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111,
    B11111111 };

int Device=13;
int Scythe=12;
int Seal=3;
int Music=2;

//---------------------LED Strips--------------------------------
int S1=8;//digital pin 8
int S2=10;//digital pin 10
int S3=11;//digital pin 11

//Servo c;
PWMServo c;
long ran;

void setup() {
  // put your setup code here, to run once:
  c.attach(9);
  c.write(0);
  randomSeed(analogRead(A0));   
  
  pinMode(Device,INPUT);
  pinMode(Scythe,INPUT);
  pinMode(Seal,INPUT);
  pinMode(Music,INPUT);
  
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  
  matrix.begin(0x70);
     
  ss.begin(9600);
  Serial.begin(115200);
  
  if (!sfx.reset()) {
    while (1);
  }
  
  digitalWrite(S1,0);
  digitalWrite(S2,0);
  digitalWrite(S3,0);
    
  matrix.setTextSize(1);
  matrix.setTextWrap(false);
  matrix.setTextColor(LED_ON);
  matrix.setRotation(1);
  
  sfx.playTrack("CONDIT~1WAV");
  
  for (int8_t x=0; x>=-125; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("  Condition All Green");
      matrix.writeDisplay();
      delay(25);
    }
    delay(500);
    sfx.reset();
    sfx.playTrack("ORDER   WAV");
    delay(1000);
    sfx.reset();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int d=digitalRead(Device);
  int sc=digitalRead(Scythe);
  int se=digitalRead(Seal);
  int m=digitalRead(Music);
  
  if(sc==HIGH){

    sfx.playTrack("YESSIR~1WAV");
    delay(950);
    sfx.reset();
    sfx.playTrack("SCYTHE~1WAV");
    
     for (int8_t x=0; x>=-125; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("      Scythe Form");
      matrix.writeDisplay();
      delay(30);
    }
    //delay(250);
    sfx.reset();
    c.write(90);
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    
    matrix.clear();
    matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
              
    sfx.reset();
  }
  if(d==HIGH){

    sfx.playTrack("YESSIR~1WAV");
    delay(950);
    sfx.reset();
    sfx.playTrack("DEVICE~1WAV");
    
    for (int8_t x=0; x>=-125; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("      Device Form");
      matrix.writeDisplay();
      delay(30);
    }
    c.write(0);
    digitalWrite(S1,0);
    digitalWrite(S2,0);
    digitalWrite(S3,0);
    sfx.reset();
  }
  if(se==HIGH){
    
    sfx.playTrack("YESSIR~1WAV");
    delay(950);
    sfx.reset();
    sfx.playTrack("SEALIN~1WAV");
    
    for (int8_t x=0; x>=-125; x--) {
      matrix.clear();
      matrix.setCursor(x,0);
      matrix.print("      Sealing Form");
      matrix.writeDisplay();
      delay(30);
    }
    
    c.write(170);
    digitalWrite(S1,HIGH);
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    
    matrix.clear();
    matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    
    sfx.reset();
    
    //sfx.playTrack("YESSIR~1WAV");//"PUTOUT~1WAV");
  }
  if(m==HIGH){
        
    sfx.playTrack("YESSIR~1WAV");
    delay(950);
    sfx.reset();
         
    ran=random(0,5);// random num from 0 to 4
    
    if(ran==0){
      uint32_t current, total;
      sfx.playTrack("FATEST~1OGG");
      while(sfx.trackTime(&current, &total)){
        for (int8_t x=0; x>=-125; x--) {
        matrix.clear();
        matrix.setCursor(x,0);
        matrix.print("      Fate's Theme");
        matrix.writeDisplay();
        delay(50);
        }
      }
      sfx.reset();      
        }
    if(ran==1){
      uint32_t current, total;
      sfx.playTrack("NANOHA~1OGG");
      
      while(sfx.trackTime(&current, &total)){
        for (int8_t x=0; x>=-125; x--) {
          matrix.clear();
          matrix.setCursor(x,0);
          matrix.print("      Nanoha's Theme");
          matrix.writeDisplay();
          delay(50);
        }
      }
      sfx.reset();
    }
    if(ran==2){
      uint32_t current, total;
      sfx.playTrack("STRIKE~1OGG");
      
      while(sfx.trackTime(&current, &total)){
        for (int8_t x=0; x>=-125; x--) {
          matrix.clear();
          matrix.setCursor(x,0);
          matrix.print("      Secret Ambition");
          matrix.writeDisplay();
          delay(50);
        }
      }
      sfx.reset();
      }
      
    
    if(ran==3){
      uint32_t current, total;
      sfx.playTrack("ASOPEN~1OGG");
      
      while(sfx.trackTime(&current, &total)){
        for (int8_t x=0; x>=-125; x--) {
          matrix.clear();
          matrix.setCursor(x,0);
          matrix.print("      Eternal Blaze");
          matrix.writeDisplay();
          delay(50);
        }
      }
      sfx.reset();
    }
    
    
    if(ran==4){
      uint32_t current, total;
      sfx.playTrack("NANOHA~2OGG");
      
      while(sfx.trackTime(&current, &total)){
        for (int8_t x=0; x>=-125; x--) {
          matrix.clear();
          matrix.setCursor(x,0);
          matrix.print("      Innocent Starter");
          matrix.writeDisplay();
          delay(50);
        }
      }
      sfx.reset();
    }
    
    sfx.playTrack("ORDER   WAV");
    delay(1000);
    sfx.reset();
  }
}
