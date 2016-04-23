#define ledPin 13
#define pwmPin 11
#define potPin 0

int onOff;
int index;

extern unsigned char sineTable[];

void setup() {                
  pinMode(ledPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  delay(100);
  index = 0;
  onOff = LOW;
}

void pause() {
    int d, knob;
    d = 0;
    do {
      knob = 1 + (analogRead(potPin) / 90);
      d = d + 1;
      delay(1);
    } while (d < knob);
}

void loop() {
    unsigned char v = sineTable[index];
    analogWrite(pwmPin, v * 2);
    index = index + 1;
    if (index >= 1023) {
        index = 0;
        onOff = (onOff == HIGH) ? LOW : HIGH;
        digitalWrite(ledPin, onOff);
    }
    pause();
}

