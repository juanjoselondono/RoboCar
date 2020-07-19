
//We initialize the variables of the channels
const int CH_2_PIN = 11;
const int deadzone = 20;

void setup(){
  Serial.begin(9600);
}
void loop () {
  int ch_2 = pulseIn(CH_2_PIN, HIGH, 25000);
  Serial.println(pulseToPWM(ch_2));
  delay(50);
}
// Convert RC pulse value to motor PWM value
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


