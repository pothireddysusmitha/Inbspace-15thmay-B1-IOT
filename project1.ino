void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
tone(10,500);
delay(2000);
noTone(10);
delay(2000);
tone(10,1000);
delay(5000);
noTone(10);
delay(5000);
tone(10,1500);
delay(8000);
noTone(10);
delay(8000);
}
