#include  <Servo.h>            //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 90; 
int ledPin = 13;
int cmd = -1;
int flag = 0;

const int led = 9; // set ledPin to on-board LED
bool currentLEDValue = false;


void setup() {
  pinMode(ledPin,OUTPUT);

  Serial.begin(9600);
 //  servo_test.attach(9); 
}

void loop() {
  if (Serial.available() > 0) {
    cmd = Serial.read();
    flag = 1;
  }

  if (flag == 1) {
    
     if (cmd == '0'){
      servo_test.write(0);
      Serial.println("Rotating to 0");
    }
    else if (cmd == '1'){
digitalWrite(led,HIGH);
Serial.println("Rotating to 30");
    
    }
    else if (cmd == '2'){
      digitalWrite(led,LOW);
    servo_test.write(60);
    Serial.println("Rotating to 60");
    }
    else if (cmd == '3'){
    servo_test.write(90);
    Serial.println("Rotating to 90");
    }
    else if (cmd == '4'){
    servo_test.write(120);
    Serial.println("Rotating to 120");
    }
    else if (cmd == '5'){
    servo_test.write(150);
    Serial.println("Rotating to 150");
    }
    else if (cmd == '6'){
    servo_test.write(180);
        Serial.println("LED on");
      digitalWrite(led, HIGH);
      currentLEDValue = true;
    Serial.println("Rotating to 180");
    }
   
    else {
      Serial.print("unknown command: ");
      Serial.write(cmd);
      Serial.print(" (");
      Serial.print(cmd, DEC);
      Serial.print(")");

      Serial.println();
    }

    flag = 0;    
    cmd = 65;
  }

  Serial.flush();
  delay(100);
}
