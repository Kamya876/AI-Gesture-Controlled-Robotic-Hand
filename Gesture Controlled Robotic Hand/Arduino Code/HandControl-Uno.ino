#include <Adafruit_PWMServoDriver.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
const int NUM_SERVOS = 5;
const int SERVO_PINS[NUM_SERVOS] = {0, 1, 2, 3, 4};
const int SERVO_MIN_PULSE = 150;
const int SERVO_MAX_PULSE = 600;


char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;

int servoPinky, servoMiddle, servoIndex, servoThumb, servoRing;
int myVals[] = {0, 0, 0, 0, 0} ;

int myButton = 1;
bool portable;

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  yield();
}

void loop() {
  uint16_t pulselength = map(180, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  uint16_t pulselength2 = map(0, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  uint16_t pulselength3 = map(150, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  uint16_t pulselength4 = map(20, 0, 180, SERVO_MIN_PULSE, SERVO_MAX_PULSE);

  receiveData();
  if (servoPinky == 1) {
    pwm.setPWM(0, 0, pulselength);
    pwm.setPWM(5, 0, pulselength3);
  } else {
    pwm.setPWM(0, 0, pulselength2);
    pwm.setPWM(5, 0, pulselength4);
  }
  if (servoIndex == 1) {
    pwm.setPWM(1, 0, pulselength);
  } else {
    pwm.setPWM(1, 0, pulselength2);
  }
  if (servoMiddle == 1) {
    pwm.setPWM(2, 0, pulselength);
  } else {
    pwm.setPWM(2, 0, pulselength2);
  }
  if (servoThumb == 1) {
    pwm.setPWM(3, 0, pulselength);
  } else {
    pwm.setPWM(3, 0, pulselength2);
  }
  if (servoRing == 1) {
    pwm.setPWM(4, 0, pulselength);
  } else {
    pwm.setPWM(4, 0, pulselength2);
  }
}

void receiveData() {
  int i = 0;
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart == true )
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString + c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; stringCounterStart = false;
        servoPinky = myRevivedString.substring(1, 2).toInt();
        servoRing = myRevivedString.substring(2, 3).toInt();
        servoMiddle = myRevivedString.substring(3, 4).toInt();
        servoIndex = myRevivedString.substring(4, 5).toInt();
        servoThumb = myRevivedString.substring(5, 6).toInt();
        mySerial.println(servoPinky);
        myRevivedString = "";
      }
    }
  }
}
