/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
char msg[]="DUCAT INDIA PVT LTD";
int i;
int main()
{
 UBRRL=51;
 UCSRB=UCSRB|(1<<TXEN);
 UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 for(i=0;i<=18;i++)
 {
 	UDR=msg[i];
 	while( (UCSRA&(1<<UDRE))==0); //wait here till UDRE is zero
 }


return 0;
}
*/


//**************using NUL Char*************
/*
#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
char msg[]="DUCAT INDIA PVT LTD BEHIND MACD";
int i;
int main()
{
 UBRRL=51;
 UCSRB=UCSRB|(1<<TXEN);
 UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 for(i=0;msg[i]!='\0';i++)
 {
 	UDR=msg[i];
 	while( (UCSRA&(1<<UDRE))==0); //wait here till UDRE is zero
 }


return 0;
}
*/

#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
char msg1[]="DUCAT INDIA PVT LTD BEHIND MACD\r";
char msg2[]="EMBEDDED SYSTEMS TRAINIGN\r";
int i;
int main()
{
 UBRRL=51;
 UCSRB=UCSRB|(1<<TXEN);
 UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
 for(i=0;msg1[i]!='\0';i++)
 {
 	UDR=msg1[i];
 	while( (UCSRA&(1<<UDRE))==0); //wait here till UDRE is zero
 }
 for(i=0;msg2[i]!='\0';i++)
 {
 	UDR=msg2[i];
 	while( (UCSRA&(1<<UDRE))==0); //wait here till UDRE is zero
 }


return 0;
}
