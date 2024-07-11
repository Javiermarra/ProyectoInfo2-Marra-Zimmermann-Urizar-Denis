#include <SPI.h>
#include <SD.h>
#include <string.h>
 typedef struct usuario {           //creacion de estructura de nombre USUARIO, que contenga tres cadenas donde se guarden los datos.
    char nombre[15];
    byte tarjeta[4];
    char contrasenia[10];
}USUARIO;
File myFile;
USUARIO uno, dos, tres; //creacion de usuarios

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  strcpy(uno.tarjeta, "1234567890ABCDEF"); // Ejemplo de RFID
    strcpy(uno.contrasenia, "1234");         // Ejemplo de contraseña
    strcpy(uno.nombre, "Juan Ignacio");     // Ejemplo de nombre

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("inicializando tarjeta SD...");

  if (!SD.begin(4)) {
    Serial.println("inicializacion fallo!");
    while (1);
  }
  Serial.println("inicializacion correcta.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("usuarios.dat", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("escribiendo usuarios.dat...");
    myFile.write((const uint8_t *)&uno, sizeof(USUARIO));
    // close the file:
    myFile.close();
    Serial.println("HECHO.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error abriendo archivo");
  }

}
void loop() {
  // put your main code here, to run repeatedly:

}
