/*
 * Robotic Arm
 * This robotic arm was created to perform vertical and diagonal movements using a claw to grab and release objects 
 *
 * The circuit:
 * * 4 motor servos Sg90 and 2 protoboards attached to digital pins as follows:
 * ---------------------    --------------------
 * | Micro Servo Sg90 (Garra) | Arduino |    
 * ---------------------    --------------------
 * |   Vcc                    |   5V    |    
 * |   Gnd                    |   Gnd   | 
 * |   Pulse                  |    9    |   
 * --------------------    ---------------------

  ---------------------       --------------------
 * | Micro Servo Sg90 (Base)  | Arduino |    
 * ---------------------    --------------------
 * |   Vcc                    |   5V    |    
 * |   Gnd                    |   Gnd   | 
 * |   Pulse                  |    11   |   
 * --------------------    ---------------------

   ---------------------       --------------------
 * | Micro Servo Sg90 (Direito)  | Arduino |    
 * ---------------------    --------------------
 * |   Vcc                       |   5V    |    
 * |   Gnd                       |   Gnd   | 
 * |   Pulse                     |    6    |   
 * --------------------    ---------------------

   ---------------------       --------------------
 * | Micro Servo Sg90 (Esquerdo)  | Arduino |    
 * ---------------------    --------------------
 * |   Vcc                        |   5V    |    
 * |   Gnd                        |   Gnd   | 
 * |   Pulse                      |    5    |   
 * --------------------    ---------------------
 * Note: You do not obligatorily need to use the pins defined above
 * Note: For use micro servos you need to use the pwm pind,pins with this character(~)

 * IN THIS PROTOTYPE I HAVE USED 7 BUTTONS DO EXECUTE THE MOVIMENTS, YOU CAN PROGRAM THEM 
 * USING YOUR PREFERENCE PINS
 *
 * created 14 Apr 2020
 * by Carlos Henrique (github: https://www.github.com/Carlos15157)
 
 * This example code is released into the MIT License.
 */

#include <Servo.h>

#define btnGarraMais 2                       //Utilizando o define para melhor leitura do código
#define btnGarraMenos 3
#define btnBaseMais1 7
#define btnBaseMais2 13
#define btnBaseMenos 4
#define btnDirMais 10
#define btnDirMenos 12

#define servoGarra 9
#define servoBase 11
#define servoEsq 5
#define servoDir 6 

Servo garra;
Servo dir;
Servo esq;
Servo base;

int i = 0;                                      // Declarando váriavel de controle no inicio, para não precisar declara-la novamente

void setup() {
  garra.attach (servoGarra);
  base.attach (servoBase);
  esq.attach (servoEsq);
  dir.attach (servoDir);
  
  pinMode (btnGarraMais, INPUT);
  pinMode (btnGarraMenos, INPUT);
  pinMode (btnBaseMais1, INPUT);
  pinMode (btnBaseMais2, INPUT);
  pinMode (btnBaseMenos, INPUT);
  pinMode (btnDirMais, INPUT);
  pinMode (btnDirMenos, INPUT);
}

void loop() {
  if (digitalRead(btnGarraMais) ==  HIGH) {
    for (i = 0; i <= 170; i++) {
      garra.write(i);
      delay(5);
    }
  }
  if (digitalRead(btnGarraMenos) ==  HIGH) {
    for (i = 170; i >= 0; i--) {
      garra.write(i);
      delay(5);
    }
  }
  if (digitalRead(btnBaseMenos) ==  HIGH) {
    for (i = 160; i >= 0; i--) {
      base.write(i);
      delay(8);
    }
  }
  if (digitalRead(btnBaseMais1) ==  HIGH) {
    for (i = 0; i <= 160; i++) {
      base.write(i);
      delay(8);
    }
  }
  if (digitalRead(btnDirMais) ==  HIGH) {
    for (i = 50; i <= 140; i++) {

      dir.write(i);
      delay(8);
    }
  }
  if (digitalRead(btnDirMenos) ==  HIGH) {
    for (i = 140; i >= 50; i--) {

      dir.write(i);
      delay(8);
    }
  }
  if (digitalRead(btnBaseMais2) ==  HIGH) {
    for (i = 50; i <= 70; i++) {
      base.write(i);
      delay(8);
    }
  }
}
