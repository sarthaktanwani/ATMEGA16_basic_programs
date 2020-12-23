#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void usart_init();
void i2c_start();
void i2c_address();
void i2c_data();
int main()
{
  
  usart_init();
  i2c_start();
  i2c_address();
  while(1)
  {
   i2c_data();
   }
}
void usart_init()
{
  UBRRL=51;
  UCSRB=UCSRB|(1<<TXEN);
  UCSRC=UCSRC|(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}
void ack(char *x)
{
  while( *x != '\0')
  {
    UDR=*x++;
	while( (UCSRA&(1<<UDRE))==0);
    _delay_ms(1);
  }
}

void i2c_start()
{
  TWBR=8;
  TWCR=TWCR|(1<<TWINT)|(1<<TWEA)|(1<<TWEN)|(1<<TWSTA);
  while( (TWCR&(1<<TWINT))==0);
  if( (TWSR&0xf8)==0x08)
  ack("A START condition has been transmitted\r");
  else
  ack("Error in START condition \r");
}

void i2c_address()
{
  TWDR=0x40;
  TWCR=TWCR|(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
  while( (TWCR&(1<<TWINT))==0);
  if( (TWSR&0xf8)==0x18)
  ack("SLA+W has been transmitted,ACK has been received\r");
  else
  ack("Error in SLA+W  \r");
}
void i2c_data()
{
 int i;
 for(i=0;i<=7;i++)
 {
	  TWDR=(1<<i);
	  TWCR=TWCR|(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	  while( (TWCR&(1<<TWINT))==0);
	  if( (TWSR&0xf8)==0x28)
	  ack("Data byte has been transmitted,ACK has been received\r");
	  else
	  ack("Error it Data writing\r");
	 _delay_ms(100);
 }
 
}













