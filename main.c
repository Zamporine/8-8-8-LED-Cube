//auxillary main.c file
#include "cube.h"
#include "main.h"
#include "draw.h"
#include "effect.h"


unsigned int bootwait (void)
{
  // All the LED_PORT... code blinks the red and green status LEDs.

  unsigned int x = 0;
  while (1)
  {
        x++; // increment x by one.
    srand(x); // use counter x as random seed
    
    delay_ms(1000);
    // Listen for button presses and return with the
    // apropriate number.
    if (!(PINA & 0x20))//on PA5 i.e. Digital PIN27
      return 2;

    if (!(PINA & 0x10))//on PA4 i.e. Digital PIN26
      return 1;
    
    delay_ms(1000);
    // Same as above. I do it twise because there are two delays
    // in this loop, used for the red and green led blinking..
    if (!(PINA & 0x20))
      return 2;

    if (!(PINA & 0x10))
      return 1;
  }
}

void rs232(void)
{
  int tempval;
  int x = 0;
  int y = 0;
    int escape = 0;
  
  while (1)
  { 
    // Wait until a byte has been received
    while ( !(UCSR0A & (1<<0x80)) ); //0b10000000 = RXC0
    // Load the received byte from rs232 into a buffer.
    tempval = UDR0;

    // Uncommet this to echo data back to the computer
    // for debugging purposes.
    UDR0 = tempval;

    // Every time the cube receives a 0xff byte,
    // it goes into sync escape mode.
    // if a 0x00 byte is then received, the x and y counters
    // are reset to 0. This way the x and y counters are
    // always the same on the computer and in the cube.
    // To send an 0xff byte, you have to send it twice!

    // Go into sync escape mode
    if (tempval == 0xff)
    {
      // Wait for the next byte
       while ( !(UCSR0A & (1<<0x80)) );
       // Get the next byte
       tempval = UDR0;

       // Sync signal is received.
       // Reset x and y counters to 0.
       if (tempval == 0x00)
       {
        x = 0;
        y = 0;
                escape = 1;
       }
       // if no 0x00 byte is received, proceed with
       // the byte we just received.
    }
      if (escape == 0)
        {
    // Load data into the current position in the buffer
    fb[x][y] = tempval;

        // Check if we have reached the limits of the buffer array.
        if (y == 7)
        {
          if (x == 7)
          {
            // All data is loaded. Reset both counters
            y = 0;
            x = 0;
                    // Copy the data onto the cube.
            tmp2cube();
          } else
          {
            // A layer is loaded, reset y and increment x.
            x++;
            y = 0;
          }
        } else
        {
          // We are in the middle of loading a layer. increment y.
          y++;
        }
  
      } else
        {
            escape = 0;
        }
    }
}

