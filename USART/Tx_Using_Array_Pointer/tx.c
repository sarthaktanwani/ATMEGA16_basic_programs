
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
char msg1[]="GOD IS ONE\r";
char msg2[]="BUT WHO BELIEVES?\r";
void tx(char *);
int main()
{
 UBRRL=51;
 UCSRB=UCSRB|(1<<TXEN);
 UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 
 tx(msg1);//2000
 tx(msg2);//3000


return 0;
}



void tx(char *x)// x==2000,*x='G'
{
  while(*x !='\0')
  {
    UDR=*x;
	while( (UCSRA&(1<<UDRE))==0);
	x++;//2001//2002
  }
}











