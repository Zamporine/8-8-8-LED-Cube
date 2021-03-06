//This program works because of adding of 
//extern "C" {} statement in launch_effect.h file
#include <cube.h>
#include <draw.h>
#include <effect.h>
#include <font.h>
#include <gameoflife.h>
#include <launch_effect.h>
#include <main.h>


#include <avr/interrupt.h>
#include <avr/eeprom.h>
//#include <main.h>
//#include <launch_effect.h>
#include <string.h>
//#include <draw.h>
//#include <effect.h>
//#include <font.h>

#define AXIS_X 1
#define AXIS_Y 2
#define AXIS_Z 3
//#define CUBE_SIZE 8
//#define CUBE_BYTES 64
//volatile unsigned char cube[8][8];

//volatile int current_layer = 0;


void setup()
{

  int i;


  for (i = 0; i < 14; i++)

    pinMode(i, OUTPUT);

  // pinMode(A0, OUTPUT) as specified in the arduino reference didn't work. So I accessed the registers directly.

  DDRC = 0xff;

  PORTC = 0x00;

  // Reset any PWM configuration that the arduino may have set up automagically!

  TCCR2A = 0x00;

  TCCR2B = 0x00;


  TCCR2A |= (0x01 << WGM21); // CTC mode. clear counter on TCNT2 == OCR2A

  OCR2A = 10; // Interrupt every 25600th cpu cycle (256*100)

  TCNT2 = 0x00; // start counting at 0

  TCCR2B |= (0x01 << CS22) | (0x01 << CS21); // Start the clock with a 256 prescaler


  TIMSK2 |= (0x01 << OCIE2A);

}



ISR (TIMER2_COMPA_vect)

{

  int i;

  // all layer selects off

  PORTC = 0x00;

  PORTB &= 0x0f;


  PORTB |= 0x08; // output enable off.


  for (i = 0; i < 8; i++)

  {

    PORTD = cube[current_layer][i];

    PORTB = (PORTB & 0xF8) | (0x07 & (i + 1));

  }


  PORTB &= 0b00110111; // Output enable on.


  if (current_layer < 6)

  {

    PORTC = (0x01 << current_layer);

  }
  else if (current_layer == 6)

  {

    digitalWrite(12, HIGH);

  }
  else

  {

    digitalWrite(13, HIGH);

  }


  current_layer++;


  if (current_layer == 8)

    current_layer = 0;

}



void loop()

{

 // int i, x, y, z;


  while (true)

  {
    int i;
  for(i=0;i<EFFECTS_TOTAL;i++)
    launch_effect(i);
  }

}//loop ends
