const int LED = 11;
int pwmValue = 0;
int pwmStep = 5;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  analogWrite(LED, pwmValue);
  pwmValue += pwmStep;

  if(pwmValue <= 0 || pwmValue >= 255) {
    pwmStep = -pwmStep;
  }
  delay(50);
}
