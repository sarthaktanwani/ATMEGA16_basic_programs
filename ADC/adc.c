#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define rs 0
#define rw 1
#define en 2
void lcd_command(char );
void lcd_data(char );
void lcd_init();
void bin2asc(int );
int main()
{
  //DDRA=0x01;//0
  DDRB=0xf7;
  lcd_init();
  ADMUX=0xc0;
  ADCSRA=0xa7;
  while(1)
  {
   ADCSRA=ADCSRA|(1<<ADSC);//1
   while( (ADCSRA&(1<<ADIF))==0){}
   bin2asc(ADC/4);//123
  
  }
}
void bin2asc(int a)
{
  int i,a1=0;char pos=0x85;
  for(i=0;i<=2;i++)
  {
    a1=a%10;//3//2//1
	a=a/10; //12
	lcd_command(pos);
	lcd_data(a1+48);
	pos--;
  }

}
void lcd_init()
{
 lcd_command(0x02);
 lcd_command(0x28);
 lcd_command(0x0E);
}
void lcd_command(char x)
{
  PORTB=x&0xf0;
  PORTB=PORTB&~(1<<rs);
  PORTB=PORTB&~(1<<rw);
  PORTB=PORTB|(1<<en);
  PORTB=PORTB&~(1<<en);
  _delay_ms(1);
  PORTB=(x<<4)&0xf0;
  PORTB=PORTB&~(1<<rs);
  PORTB=PORTB&~(1<<rw);
  PORTB=PORTB|(1<<en);
  PORTB=PORTB&~(1<<en);
  _delay_ms(1);
}
void lcd_data(char x)//ascii or char '0'
{
  PORTB=x&0xf0;
  PORTB=PORTB|(1<<rs);
  PORTB=PORTB&~(1<<rw);
  PORTB=PORTB|(1<<en);
  PORTB=PORTB&~(1<<en);
  _delay_ms(1);
  PORTB=(x<<4)&0xf0;
  PORTB=PORTB|(1<<rs);
  PORTB=PORTB&~(1<<rw);
  PORTB=PORTB|(1<<en);
  PORTB=PORTB&~(1<<en);
  _delay_ms(1);
}
