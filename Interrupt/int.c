#define F_CPU 8000000UL
#include<avr/interrupt.h>
#include<avr/io.h>
#include<util/delay.h>
#define rs 0
#define rw 1
#define en 2
void lcd_string(char *);
void lcd_command(char );
void lcd_data(char );
void lcd_init();
void lcd_init();

int i;
ISR(INT0_vect)
{
  for(i=0;i<=2;i++)
  {
    PORTB=PORTB|(1<<0);
	_delay_ms(1000);
	PORTB=PORTB &~ (1<<0);
	_delay_ms(1000);
  }
}
void interrupt_init()
{
  GICR=GICR|(1<<INT0);
  MCUCR=MCUCR|(1<<ISC00);
  sei();
}
int main()
{
  DDRB=DDRB|(1<<0);
  DDRD=DDRD &~ (1<<2);
  DDRA=0xff;
  interrupt_init();
  lcd_init();
  while(1)
  {
    lcd_command(0x01);
    lcd_string("Welcome to Hell");
  }
return 0;
}
void lcd_init()
{
 DDRA=0xff;
 lcd_command(0x02); lcd_command(0x28); lcd_command(0x0E);
}


void lcd_command(char cmd)
{
  PORTA= cmd & 0xf0;

  PORTA=PORTA &~(1<<rs);
  PORTA=PORTA &~(1<<rw);
  PORTA=PORTA |(1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);

  PORTA= (cmd<<4)&0xf0;
  PORTA=PORTA &~(1<<rs);
  PORTA=PORTA &~(1<<rw);
  PORTA=PORTA |(1<<en);
  PORTA=PORTA &~(1<<en);

  _delay_ms(1);
}


void lcd_data(char x)
{
  PORTA= x&0xf0;
  PORTA=PORTA |(1<<rs);
  PORTA=PORTA &~(1<<rw);
  PORTA=PORTA |(1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);

   PORTA= (x<<4)&0xf0;
  PORTA=PORTA |(1<<rs);
  PORTA=PORTA &~(1<<rw);
  PORTA=PORTA |(1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);
}

void lcd_string(char *x)
{
  while(*x !='\0')
  {
    lcd_data(*x++);
	_delay_ms(100);
  }
}


