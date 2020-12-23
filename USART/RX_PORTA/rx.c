 #define F_CPU 8000000UL
 #include<avr/io.h>
 #include<util/delay.h>
 void usart_init();
 int main()
 {
   DDRC=0xff;
   usart_init();
   while(1)
   {
     while( (UCSRA&(1<<RXC))==0);
	 PORTC=UDR;
   }
 }
 
 
 void usart_init()
 {
 	UBRRL=51;
 	UCSRB=UCSRB|(1<<RXEN);
 	UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 }
