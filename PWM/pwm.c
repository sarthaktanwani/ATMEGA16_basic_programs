/*
#define F_CPU 800000UL
#include<avr/io.h>
#include<util/delay.h>
int main()
{
  DDRB=DDRB|(1<<3); 
  TCNT0=0;
  OCR0=9;
  TCCR0=0x69;

}
*/
//asli pwm
/*
#define F_CPU 800000UL
#include<avr/io.h>
#include<util/delay.h>
int i;
int main()
{
  DDRB=DDRB|(1<<3); 
  TCNT0=0;
  TCCR0=0x69;
  while(1)
  {
  	for(i=0;i<=255;i++)
  	{
     OCR0=i;
	 _delay_ms(10);
  	}
  }
	
}
*/

#define F_CPU 800000UL
#include<avr/io.h>
#include<util/delay.h>
int i;
int main()
{
  DDRB=DDRB|(1<<3); 
  TCNT2=0;
  TCCR2=0x69;
  while(1)
  {
  	for(i=0;i<=255;i++)
  	{
     OCR2=i;
	 _delay_ms(30);
  	}
  }
	
}
