void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int out = analogRead(A0);
  Serial.println(out);
  if (out >= 400)
    digitalWrite(13, HIGH);
  else
   digitalWrite(13,LOW);
}
