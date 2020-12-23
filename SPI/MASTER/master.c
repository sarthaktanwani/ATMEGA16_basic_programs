#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void spi_init();
void tx();
int main()
{
  
  spi_init();
   while(1)
  {
	 tx();
  }

}
void spi_init()
{
  DDRB=DDRB|(1<<7)|(1<<5)|(1<<4);//Output
  DDRB=DDRB &~ (1<<6);//Input
  SPCR=SPCR|(1<<SPE)|(1<<DORD)|(1<<MSTR);
 

}
void tx()
{
      SPDR='A';
	  while( (SPSR&(1<<SPIF))==0);
	  _delay_ms(2000);
	  SPDR='B';
	  while( (SPSR&(1<<SPIF))==0);
	  _delay_ms(2000);
	  SPDR='C';
	  while( (SPSR&(1<<SPIF))==0);
	  _delay_ms(2000);
}
