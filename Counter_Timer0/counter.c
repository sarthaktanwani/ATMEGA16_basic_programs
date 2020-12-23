/*
#define F_CPU 1000000UL
#include<avr/io.h>
void main()
{
  DDRA=0xff;
  DDRB=DDRB|(1<<0);
  TCCR0=0b00000110;
  TCNT0=0;
  while(1)
  {
    do
	{ 
	  PORTA=TCNT0;
	}while( (TIFR&(1<<TOV0))==0);
  }
}
*/


#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#define rs 0
#define rw 1
#define en 2
#define lcd   PORTD

void lcd_command(char );
void lcd_data(char );
void lcd_init();
void b2a(int );
void counter_init();
void lcd_init();
void main()
{
  
  DDRB=DDRB|(1<<0);
  lcd_init();
  counter_init();
  
  while(1)
  {
    do
	{ 
	  b2a(TCNT0);
	}while( (TIFR&(1<<TOV0))==0);
  }
}
void b2a(int a)//254
{
  int a1,i=0;char pos=0x82;
  for(i=0;i<=2;i++)
  {
     a1=a%10;//   4//5//2
	 a=a/10; //   25 //2//0
   	 lcd_command(pos);
     lcd_data(a1+48);
	 pos--;//0x81//0x80
  }
}
void counter_init()
{
  TCCR0=0b00000110;
  TCNT0=0;
}
void lcd_init()
{
 DDRD=0xff;
 lcd_command(0x02); lcd_command(0x28); lcd_command(0x0E);
}


void lcd_command(char cmd)
{
  PORTD= cmd & 0xf0;

  PORTD=PORTD &~(1<<rs);
  PORTD=PORTD &~(1<<rw);
  PORTD=PORTD |(1<<en);
  PORTD=PORTD &~(1<<en);
  _delay_ms(1);

  PORTD= (cmd<<4)&0xf0;
  PORTD=PORTD &~(1<<rs);
  PORTD=PORTD &~(1<<rw);
  PORTD=PORTD |(1<<en);
  PORTD=PORTD &~(1<<en);

  _delay_ms(1);
}


void lcd_data(char x)
{
  PORTD= x&0xf0;
  PORTD=PORTD |(1<<rs);
  PORTD=PORTD &~(1<<rw);
  PORTD=PORTD |(1<<en);
  PORTD=PORTD &~(1<<en);
  _delay_ms(1);

   PORTD= (x<<4)&0xf0;
  PORTD=PORTD |(1<<rs);
  PORTD=PORTD &~(1<<rw);
  PORTD=PORTD |(1<<en);
  PORTD=PORTD &~(1<<en);
  _delay_ms(1);
}







