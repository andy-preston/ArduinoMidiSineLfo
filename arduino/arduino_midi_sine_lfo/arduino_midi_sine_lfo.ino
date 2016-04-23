int led = 13;
int led2 = 11;
int onOff = LOW;
int index = 0;
extern int sineTable[];

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(led2, OUTPUT);
}

void loop() {
    analogWrite(led2, sineTable[index] * 2);
    index = index + 1;
    if (index >= 1023) {
        index = 0;
        onOff = (onOff == HIGH) ? LOW : HIGH;
        digitalWrite(led, onOff);
    }
    delay (1);
}

