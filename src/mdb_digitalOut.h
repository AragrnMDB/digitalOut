#ifndef mdb_digitalOut_h
#define mdb_digitalOut_h

#include "mdb_timer.h"

class mdb_digitalOut {
   public:
      mdb_digitalOut(uint8_t output, unsigned long onDuration=500, unsigned long offDuration=500, uint8_t initialState=LOW)
         : _output(output), _onDuration(onDuration), _offDuration(offDuration), _initialState(initialState) {}
      void begin();                                 // Set up and start the digital output
      void startBlink();                            // Start the blink
      bool processBlink();                          // Process blinking
      void adjustBlink(unsigned long onDuration, unsigned long offDuration); // Sets the new onDuration and offDuration
      void holdBlink();                             // Hold blinking
      void startFlash();                            // Start the flash
      bool processFlash();                          // If the duration is up, turn off the output. Return the state of the output.
      void adjustFlash(unsigned long onDuration);   // Sets the new onDuration
   private:
      uint8_t       _output;                        // The output pin to control
      unsigned long _onDuration;                    // Duration of the on part of the blink or flash
      unsigned long _offDuration;                   // Duration of the off part of the blink
      uint8_t       _initialState;                  // Starting state of the output
      uint8_t       _currentState;                  // Current state of the output
      bool          _flashFlag;                     // True if currently flashing (HIGH)
      mdb_timer     _outputTimer;                   // mdb_timer object to time the on and off parts of the blink or flash
};

#endif