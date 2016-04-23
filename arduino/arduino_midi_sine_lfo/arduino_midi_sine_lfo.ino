#define ledPin 13
#define pwmPin 11
#define potPin 0

int onOff;
int index;

extern unsigned char sineTable[];

void setup() {
  Serial.begin (31250);
  delay(10);
  pinMode(ledPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  delay(10);
  index = 0;
  onOff = LOW;
}

void ControlChange(unsigned char channel, unsigned char controller, unsigned char value) {
  Serial.write(0xb0 + (channel - 1));
  Serial.write(controller);
  Serial.write(value);
}

void pause() {
    int d, knob;
    d = 0;
    do {
      knob = 1 + (analogRead(potPin) / 90);
      d = d + 1;
      // this is a rubbish delay loop
      // fix it based on old midi_lfo sketch
      delay(1);
    } while (d < knob);
}

void loop() {
    unsigned char v = sineTable[index];
    analogWrite(pwmPin, v * 2);
    ControlChange(1, 2, v);
    ControlChange(1, 3, v);
    index = index + 1;
    if (index >= 1023) {
        index = 0;
        onOff = (onOff == HIGH) ? LOW : HIGH;
        digitalWrite(ledPin, onOff);
    }
    pause();
}

