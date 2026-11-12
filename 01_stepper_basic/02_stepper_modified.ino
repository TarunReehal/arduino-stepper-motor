const int pinA1 = 4;   // coil A, end 1
const int pinA2 = 5;   // coil A, end 2
const int pinB1 = 6;   // coil B, end 1
const int pinB2 = 7;   // coil B, end 2

const int stepsPerRev = 400;          // NEW
const float rpm = 200;                 // NEW: change this to set speed
unsigned long stepDelayUs;            // NEW: replaces the old const int stepDelayUs = 1000;

const int repeats = 50;         // 50 repeats x 4 steps = 200 steps = 1 revolution

// NEW: converts RPM to delay per step
unsigned long rpmToDelayUs(float rpm) {
  return 60000000UL / (stepsPerRev * rpm);
}

void setup() {
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);

  stepDelayUs = rpmToDelayUs(rpm);    // NEW: must come before the for loop

  for (int i = 0; i < repeats; i++)   // now uses the constant instead of 50
  {
    digitalWrite(pinA1, HIGH);
    digitaldWrite(pinA2, LOW);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
    delayMicroseconds(stepDelayUs);

    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
    delayMicroseconds(stepDelayUs);
  }
}

void loop()
{
  digitalWrite(pinA1, LOW);
  digitalWrite(pinA2, LOW);
  digitalWrite(pinB1, LOW);
  digitalWrite(pinB2, LOW);
  delayMicroseconds(stepDelayUs);
}
