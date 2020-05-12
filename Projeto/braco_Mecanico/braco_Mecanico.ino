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
Servo garra;
Servo dir;
Servo esq;
Servo base;

void setup() {
  garra.attach (9);
  base.attach (11);
  esq.attach (5);
  dir.attach (6);
  pinMode (2, INPUT);
  pinMode (3, INPUT);
  pinMode (4, INPUT);
  pinMode (7, INPUT);
  pinMode (10, INPUT);
  pinMode (12, INPUT);
  pinMode (13, INPUT);
}

void loop() {
  if (digitalRead (2) ==  HIGH) {
    for (int i = 0; i <= 170; i++) {
      garra.write(i);
      delay(5);
    }
  }
  if (digitalRead (3) ==  HIGH) {
    for (int i = 170; i >= 0; i--) {
      garra.write(i);
      delay(5);
    }
  }
  if (digitalRead (4) ==  HIGH) {
    for (int i = 160; i >= 0; i--) {
      base.write(i);
      delay(8);
    }
  }
  if (digitalRead (7) ==  HIGH) {
    for (int i = 0; i <= 160; i++) {
      base.write(i);
      delay(8);
    }
  }
  if (digitalRead (10) ==  HIGH) {
    for (int i = 50; i <= 140; i++) {

      dir.write(i);
      delay(8);
    }
  }
  if (digitalRead (12) ==  HIGH) {
    for (int i = 140; i >= 50; i--) {

      dir.write(i);
      delay(8);
    }
  }
  if (digitalRead (13) ==  HIGH) {
    for (int i = 50; i <= 70; i++) {
      base.write(i);
      delay(8);
    }
  }
}
