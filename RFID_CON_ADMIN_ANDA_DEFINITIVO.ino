#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9         
#define SS_PIN          10         

MFRC522 mfrc522(SS_PIN, RST_PIN);  
byte LecturaUID[4];
byte Admin[4]={0xFC, 0x12, 0xFC, 0x38};
byte Usuario1[4];
byte Usuario2[4];
byte Usuario3[4];
byte Usuario4[4];
byte Usuario5[4];
uint8_t serial[1];
int n;
void setup() {
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();   
  Serial.println("listo");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
for(byte i=0;i<mfrc522.uid.size;i++){
  LecturaUID[i]=mfrc522.uid.uidByte[i];
}
  if(ComparaUID(LecturaUID,Admin)){
    Serial.println("Ingrese Usuario a cargar"); 
    while(!Serial.available());
    n=Serial.readBytes(serial,1);
    if(n==1){
    switch(serial[0]){
      case '1':
        if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
      for(byte i=0;i<mfrc522.uid.size;i++){
       LecturaUID[i]=mfrc522.uid.uidByte[i];
       Usuario1[i]=LecturaUID[i];
      }
      break;
      case '2':
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
      for(byte i=0;i<mfrc522.uid.size;i++){
       LecturaUID[i]=mfrc522.uid.uidByte[i];
       Usuario2[i]=LecturaUID[i];
      }
      break;
      case '3':
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
      for(byte i=0;i<mfrc522.uid.size;i++){
       LecturaUID[i]=mfrc522.uid.uidByte[i];
       Usuario3[i]=LecturaUID[i];
      }
      break;
      case 4:
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
      for(byte i=0;i<mfrc522.uid.size;i++){
       LecturaUID[i]=mfrc522.uid.uidByte[i];
       Usuario4[i]=LecturaUID[i];
      }
      break;
      case 5:
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
      for(byte i=0;i<mfrc522.uid.size;i++){
       LecturaUID[i]=mfrc522.uid.uidByte[i];
       Usuario5[i]=LecturaUID[i];
      }
      break;
    }
  }
  }
if(ComparaUID(LecturaUID,Admin)){
    Serial.println("Bienvenido admin");//lcd
}
 else if(ComparaUID(LecturaUID,Usuario1)){
    Serial.println("Bienvenido Usuario 1");//lcd
  }
   else if(ComparaUID(LecturaUID,Usuario2)){
    Serial.println("Bienvenido Usuario 2");//lcd
  }
    else if(ComparaUID(LecturaUID,Usuario3)){
    Serial.println("Bienvenido Usuario 3");//lcd
  }
   else if(ComparaUID(LecturaUID,Usuario4)){
    Serial.println("Bienvenido Usuario 4");//lcd
  }
     else if(ComparaUID(LecturaUID,Usuario5)){
    Serial.println("Bienvenido Usuario 5");//lcd
  }
  else{
    Serial.println("No registrado");
  }
  mfrc522.PICC_HaltA();
}
boolean ComparaUID(byte Lectura[],byte Usuario[]){
for(byte i=0;i<mfrc522.uid.size;i++){
  if(Lectura[i]!=Usuario[i]){
    return (false);
  }
}
return (true);
}
