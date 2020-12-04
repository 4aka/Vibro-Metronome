




// -----------------------------------------BETA----------------------------------//

#define MOTOR_PIN_A1 5
#define MOTOR_PIN_A2 6

int metronome = 170; // default speed
//int buttonState = 0;
//const int BUTTON_HIGH = 4;
//const int BUTTON_LOW  = 3;

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR_PIN_A1, OUTPUT);
  pinMode(MOTOR_PIN_A2, OUTPUT);

  digitalWrite(MOTOR_PIN_A1, LOW);
  digitalWrite(MOTOR_PIN_A2, LOW);

  //  pinMode(BUTTON_HIGH, INPUT);
  //  pinMode(BUTTON_LOW, INPUT);
}

//int checkButtonState() {
//  buttonState = digitalRead(BUTTON_HIGH);
//  buttonState = digitalRead(BUTTON_LOW);
//
//  if (BUTTON_HIGH == HIGH) {
//    metronome += 5.00;
//    return metronome;
//  } else if (BUTTON_LOW == HIGH) {
//    metronome -= 5.00;
//    return metronome;
//  }
//}

void set_motor_power(int power)
{
  if (power > 0) {
    digitalWrite(MOTOR_PIN_A1, HIGH);
    analogWrite(MOTOR_PIN_A2, power);

  } else if (power = 0) {
    digitalWrite(MOTOR_PIN_A1, LOW);
    analogWrite(MOTOR_PIN_A2, 0);
  }
}

/**
   delay(wait) got a half time of waiting.

   full timeout for cadence - (60sec * 1000ms)/cadence

   ex. cadence 180
   timeout = 60000/180 = 333ms

   ex. cadence 170
   timeout = 60000/170 = 352ms

   it works if it is set:
    - half timeout,
    - turn on vibro,
    - half timeout,
    - turn of vibro.
*/
void vibro(int wait) {
  delay(wait);
  set_motor_power(100); // 100 motor current. 255 MAX.
  delay(wait);
  set_motor_power(0); // 0 - turn off motor
}

//void doVibro() {
//  int metronome = checkButtonState();
//
//  if (metronome = 160) {
//    Serial.println(metronome);
//    vibro(186);
//
//  } else if (metronome = 165) {
//    Serial.println(metronome);
//    vibro(181);
//
//  } else if (metronome = 170) {
//    Serial.println(metronome);
//    vibro(176);
//
//  } else if (metronome = 175) {
//    Serial.println(metronome);
//    vibro(171);
//
//  } else if (metronome = 180) {
//    Serial.println(metronome);
//    vibro(166);
//
//  } else if (metronome = 185) {
//    Serial.println(metronome);
//    vibro(161);
//  }
//}

void loop() {
  //  checkButtonState();
  vibro(176); // half waiting for cadence 170.
}
