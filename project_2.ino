#include<LiquidCrystal.h>
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int i=0,j=0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("NOW LETS SEE");
}

void loop() {
  // put your main code here, to run repeatedly:
for (j=0;j<=15;j++)
{
  lcd.setCursor(j,i);
  lcd.print("NOW LETS SEE");
  delay(200);
  lcd.clear();
  }
}
