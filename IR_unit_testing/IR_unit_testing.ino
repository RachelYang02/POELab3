int r1 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
r1 = analogRead(A0);
Serial.println(r1);
delay(25);
}
