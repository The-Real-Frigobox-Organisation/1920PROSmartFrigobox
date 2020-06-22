
const int buttonPin = 2;
const int ledPin =  13;     

int buttonState = 0;  
boolean drank1 = false;      

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    drank1 = true;
    Serial.println(drank1);
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    drank1 = false;
  }
}
