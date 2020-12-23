
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void tx(char *);
int main()
{
 UBRRL=51;
 UCSRB=UCSRB|(1<<TXEN);
 UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 while(1)
 {
	 tx("GOD IS ONE\r");//2000
	 tx("BUT WHO BELIEVES?\r");//3000
	 tx("OHHH GODDDDDD!!!!\r");
	 tx("NO ONE!!!!!!!\r");
 }

return 0;
}



void tx(char *x)// x==2000,*x='G'
{
  while(*x !='\0')
  {
    UDR=*x++;
	while( (UCSRA&(1<<UDRE))==0);
	_delay_ms(100);
  }
}











