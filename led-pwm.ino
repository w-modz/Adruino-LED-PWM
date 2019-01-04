const int switchPin = 8;
const int LED = 11;
int pwmValue = 0;
int pwmStep = 5;
bool lastButton = LOW;
bool currentButton = LOW;
bool ledOn = false;

bool debounce(bool last) {
  bool current = digitalRead(switchPin);

  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }

  return current;
}

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  currentButton = debounce(lastButton);

  if (lastButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;
  }

  lastButton = currentButton;

  if (ledOn) {
    analogWrite(LED, pwmValue);
    pwmValue += pwmStep;
  
    if(pwmValue <= 0 || pwmValue >= 255) {
      pwmStep = -pwmStep;
    }
    delay(50);
  }
}
