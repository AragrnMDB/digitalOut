# mdb_digitalOut

This is an Arduino library that implements digital outputs (blinking and flashing) without using the delay() function.  
Blinking is a repeating pattern of On, Off, On, Off, ... . Flashing happens once, On then off until started again.

To use the functions in the library include the file mdb_digitalOut.h.  

## Constructors

There is one constructor that you can use to instantiate your digitalOut.
- mdb_digitalOut(uint8_t output, unsigned long onDuration=500, unsigned long offDuration=500, uint8_t initialState=LOW)
         : _output(output), _onDuration(onDuration), _offDuration(offDuration), _initialState(initialState) {}


## Functions

There are six public functions available for your blinking or flashing output.
- void begin();                                 // Set up and start the digital output
- void startBlink();                            // Start the blink
- bool processBlink();                          // Process blinking
- void adjustBlink(unsigned long onDuration, unsigned long offDuration); // Change the onDuration and offDuration for blinking
- void holdBlink();                             // Hold blinking
- void startFlash();                            // Start the flash
- bool processFlash();                          // If the duration is up, turn off the output. Return the state of the output.
- void adjustFlash(unsigned long onDuration);   // Change the onDuration for flashing

## Note:

The mdb_digitalOut library uses (depends on) the mdb_timer library.  

## Sample code (blinks the on-board led once per second)

```` c++

    // Include for mdb_digitalOut
    #include <mdb_digitalOut.h>

    uint8_t led               = 13;
    unsigned long onDuration  = 500;
    unsigned long offDuration = 500;
    uint8_t initialState      = LOW;

    // Create the blinker instance
    mdb_digitalOut mdbBlink(led, onDuration, offDuration, initialState);

    void setup() {
      mdbBlink.begin();
      mdbBlink.startBlink();
      mdbBlink.adjustBlink(250, 250);
    }

    void loop() {
      mdbBlink.processBlink();
    }
````

## Remote repository

The remote repository for this project is hosted on GitHub at the following address: https://github.com/AragrnMDB/mdb_digitalOut  
