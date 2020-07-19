#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
//We initialize the variables of the channels
const int CH_2_PIN = 11;
//here we initialize de deadzone
const int deadzone = 20;

void setup(){
  Serial.begin(9600);
}
void loop () {
  //initialize channel
  int ch_2 = pulseIn(CH_2_PIN, HIGH, 25000);
  // Convert to PWM value (-255 to 255)
  ch_2 = pulseToPWM(ch_2);
  Serial.println(ch_2);
}
void forwardBackward(int channel){
  //we convert the pulse to PWD
  int pulse = pulseToPWM(channel);
  if(pulse >= 0){
    motor1.setSpeed(pulse);
    motor2.setSpeed(pulse);
    motor3.setSpeed(pulse);
    motor4.setSpeed(pulse);
    //here It goes forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  else{
    pulse = abs(pulse);
    motor1.setSpeed(pulse);
    motor2.setSpeed(pulse);
    motor3.setSpeed(pulse);
    motor4.setSpeed(pulse);
    //here it goes backward
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
  
}
int pulseToPWM(int pulse) {
  
  // If we're receiving numbers, convert them to motor PWM
  if ( pulse > 1000 ) {
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255, 255);
  } else {
    pulse = 0;
  }

  // Anything in deadzone should stop the motor
  if ( abs(pulse) <= deadzone ) {
    pulse = 0;
  }

  return pulse;
}

