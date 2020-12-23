#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
int main()
{
 UBRRL=51;
 UCSRB=UCSRB|(1<<TXEN);
 UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 UDR='A';
 while( (UCSRA&(1<<5))==0); //wait here till UDRE is zero
 UDR='B';
 while( (UCSRA&(1<<5))==0); //wait here till UDRE is zero


return 0;
}
