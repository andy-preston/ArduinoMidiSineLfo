int led = 13;
int led2 = 11;
int brightness = 0;
int fadeAmount = 1;
int onOff = HIGH;

void setup() {                
  pinMode(led, OUTPUT);     
  pinMode(led2, OUTPUT);     
}

void loop() {
  digitalWrite(led, onOff);
  onOff = (onOff == HIGH) ? LOW : HIGH;
  analogWrite(led2, brightness * 2);    
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 127) {
    fadeAmount = -fadeAmount ; 
  }
  delay(50);
}

