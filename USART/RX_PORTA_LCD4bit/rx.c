 #define F_CPU 8000000UL
 #include<avr/io.h>
 #include<util/delay.h>

 #define rs 0
 #define rw 1
 #define en 2
 void usart_init();
 void lcd_init();
 void lcd_command(char );
 void lcd_data(char );
 int i=0;
 int main()
 {
   DDRA=0xff;
   usart_init();
   lcd_init();
   while(1)
   {
     while( (UCSRA&(1<<RXC))==0);
	 lcd_data(UDR);
	 i++;
	 if(i>16)
	 {
	 i=0;
	 lcd_init();
	 }
   }
 }
void lcd_init()
{
 lcd_command(0x02);
 lcd_command(0x28);
 lcd_command(0x0E);
}
 void usart_init()
 {
 	UBRRL=51;
 	UCSRB=UCSRB|(1<<RXEN);
 	UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 }
void lcd_data(char x)
{
  PORTA=x&0xf0;
  PORTA=PORTA | (1<<rs);
  PORTA=PORTA &~ (1<<rw);
  PORTA=PORTA | (1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);
  PORTA=(x<<4)&0xf0;
  PORTA=PORTA | (1<<rs);
  PORTA=PORTA &~ (1<<rw);
  PORTA=PORTA | (1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);
}
void lcd_command(char x)
{
  PORTA=x&0xf0;
  PORTA=PORTA &~ (1<<rs);
  PORTA=PORTA &~ (1<<rw);
  PORTA=PORTA | (1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);
  PORTA=(x<<4)&0xf0;
  PORTA=PORTA &~ (1<<rs);
  PORTA=PORTA &~ (1<<rw);
  PORTA=PORTA | (1<<en);
  PORTA=PORTA &~(1<<en);
  _delay_ms(1);
}
