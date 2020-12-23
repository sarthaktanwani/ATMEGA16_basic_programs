#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#define rs 0
#define rw 1
#define en 2
void lcd_command(char );
void cmden();
void lcddata(char );
void dataen();
void lcd_init();
void display();
void lcd_string(char *);
#define row0 0
#define row1 1
#define row2 2
#define row3 3
#define col0 4
#define col1 5
#define col2 6
#define col3 7
void keyscan();

int main()
{
  DDRB=0xf0;
  PORTB=PORTB| ( (1<<0)|(1<<1)|(1<<2)|(1<<3) );
  lcd_init();
  while(1)
  {
    keyscan();
  }
}  

void lcd_string(char *x)
{
  while(*x != '\0')
  {
    lcddata(*x);
	x++;
	_delay_ms(100);
  } 
}
void lcd_init()
{
  DDRD=0xff;  
  lcd_command(0x02);
  lcd_command(0x28);
  lcd_command(0x0e);

}
void lcd_command(char x)
{
   PORTD=x&0xf0;
   cmden(); 
   PORTD=(x<<4)&0xf0;
   cmden();   
}
void cmden()
{
   PORTD=PORTD&~(1<<rs);
   PORTD=PORTD&~(1<<rw);
   PORTD=PORTD|(1<<en);
   _delay_ms(1);
   PORTD=PORTD&~(1<<en);
   _delay_ms(5);
}
void lcddata(char x)
{
   PORTD=x&0xf0;
   dataen();
   PORTD=(x<<4)&0xf0;
   dataen();
}
void dataen()
{
   PORTD=PORTD|(1<<rs);
   PORTD=PORTD&~(1<<rw);
   PORTD=PORTD|(1<<en);
   _delay_ms(1);
   PORTD=PORTD&~(1<<en);
   _delay_ms(5);
}


void keyscan()
{
  PORTB=PORTB &~ (1<<col0);
  PORTB=PORTB | (1<<col1)|(1<<col2)|(1<<col3);

  if( (PINB&(1<<0))==0)
  {
    lcd_command(0x01);
	lcd_string("key 7 is pressed");
  }
  else if( (PINB&(1<<1))==0)
  {
    lcd_command(0x01);
	lcd_string("key 4 is pressed");
  }
  else if( (PINB&(1<<2))==0)
  {
    lcd_command(0x01);
	lcd_string("key 1 is pressed");
  }
  else if( (PINB&(1<<3))==0)
  {
    lcd_command(0x01);
	lcd_string("key ON is pressed");
  }
  
  PORTB=PORTB &~ (1<<col1);
  PORTB=PORTB | (1<<col0)|(1<<col2)|(1<<col3);
  
 if( (PINB&(1<<0))==0)
  {
    lcd_command(0x01);
	lcd_string("key 8 is pressed");
  }
  else if( (PINB&(1<<1))==0)
  {
    lcd_command(0x01);
	lcd_string("key 5 is pressed");
  }
  else if( (PINB&(1<<2))==0)
  {
    lcd_command(0x01);
	lcd_string("key 2 is pressed");
  }
  else if( (PINB&(1<<3))==0)
  {
    lcd_command(0x01);
	lcd_string("key 0 is pressed");
  }


  PORTB=PORTB &~ (1<<col2);
  PORTB=PORTB | (1<<col0)|(1<<col1)|(1<<col3);
  
 if( (PINB&(1<<0))==0)
  {
    lcd_command(0x01);
	lcd_string("key 9 is pressed");
  }
  else if( (PINB&(1<<1))==0)
  {
    lcd_command(0x01);
	lcd_string("key 6 is pressed");
  }
  else if( (PINB&(1<<2))==0)
  {
    lcd_command(0x01);
	lcd_string("key 3 is pressed");
  }
  else if( (PINB&(1<<3))==0)
  {
    lcd_command(0x01);
	lcd_string("key = is pressed");
  }

PORTB=PORTB &~ (1<<col3);
  PORTB=PORTB | (1<<col0)|(1<<col1)|(1<<col2);
  
 if( (PINB&(1<<0))==0)
  {
    lcd_command(0x01);
	lcd_string("key / is pressed");
  }
  else if( (PINB&(1<<1))==0)
  {
    lcd_command(0x01);
	lcd_string("key * is pressed");
  }
  else if( (PINB&(1<<2))==0)
  {
    lcd_command(0x01);
	lcd_string("key - is pressed");
  }
  else if( (PINB&(1<<3))==0)
  {
    lcd_command(0x01);
	lcd_string("key + is pressed");
  }
}
