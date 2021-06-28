#include<avr/io.h>
#include<util/delay.h>
void lcdcmd(unsigned char a)
{
PORTD=a;PORTC=0b00000100;
_delay_ms(100);
PORTC=0b00000000;
_delay_ms(100);
}
void lcddata(unsigned char a)
{ PORTD=a; PORTC=0b00000101;
_delay_ms(100);
PORTC=0b00000001;
_delay_ms(100);
}
void refresh()
{ lcdcmd(0x01);lcdcmd(0x80);
lcddata('E');lcddata('n');lcddata('t');lcddata('e');lcddata('r');lcddata(' ');
lcddata('c');lcddata('a');lcddata('r');lcddata(' ');
lcddata('n');lcddata('o');lcddata('.');lcddata(':');lcddata(' ');
}
void warning()
{ lcdcmd(0x01);lcdcmd(0x80);
lcddata('I');lcddata('n');lcddata('v');lcddata('a');lcddata('l');lcddata('i');
lcddata('d');lcddata(' ');
lcddata('c');lcddata('a');lcddata('r');lcddata(' ');
lcddata('n');lcddata('o');lcddata('.');lcddata('.');lcddata('.');
_delay_ms(500);
refresh();
}
void parkingfull()
{
lcdcmd(0x01);
lcdcmd(0x80);
lcddata('P');
lcddata('a');
lcddata('r');
lcddata('k');
lcddata('i');
lcddata('n');
lcddata('g');
lcddata(' ');
lcddata('i');
lcddata('s');
lcddata(' ');
lcddata('f');
lcddata('u');
lcddata('l');
lcddata('l');
lcddata('!');
}
void success(unsigned char a)
{
lcdcmd(0x01);lcdcmd(0x80);
lcddata('S');lcddata('l');lcddata('o');lcddata('t');//lcddata(':');
lcddata(a);
lcddata(' ');
lcddata('a');lcddata('l');lcddata('l');lcddata('o');lcddata('t');lcddata('e');
lcddata('d');
_delay_ms(5000);
}
int main()
{
int carcount=0;
int a[4][4];
int count=0,i=0,j=0;
DDRB = 0x00; 
PORTB = 0x0F;  
DDRC=0xFF;
DDRD=0xFF;
lcdcmd(0x38); 
lcdcmd(0x0E); 
lcdcmd(0x01);
lcdcmd(0x80);
refresh();
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
a[i][j]=0;
}
}
while (1) //loop key check forever
 { 
 if(carcount<4)
 {
//first column
 
 _delay_ms(50);
 if (!(PINB & 0x01)){ lcddata('1');a[carcount][count]=1;count++;}
 if (!(PINB & 0x02)){lcddata('4');a[carcount][count]=4;count++;}
 if (!(PINB & 0x04)){lcddata('7');a[carcount][count]=7;count++;}
if (!(PINB & 0x08)) {refresh();
for(j=0;j<4;j++){
a[carcount][j]=0;}
count=0;
}
 //second column
 
 _delay_ms(50);
 if (!(PINB & 0x01)){lcddata('2');a[carcount][count]=2;count++;}
 if (!(PINB & 0x02)){lcddata('5');a[carcount][count]=5;count++;}
 if (!(PINB & 0x04)){lcddata('8');a[carcount][count]=8;count++;}
 if (!(PINB & 0x08)){lcddata('0');a[carcount][count]=0;count++;}
 //third column
 
 _delay_ms(50);
 if (!(PINB & 0x01)){lcddata('3');a[carcount][count]=3;count++;}
 if (!(PINB & 0x02)){lcddata('6');a[carcount][count]=6;count++;}
 if (!(PINB & 0x04)){lcddata('9');a[carcount][count]=9;count++;}
if (!(PINB & 0x08)){//lcddata('#');
if(count>4||count<3){
warning();
count=0;
}
else{
carcount++;
success(carcount+48);
refresh();
}
}
}
else{
parkingfull();
}
}
}
