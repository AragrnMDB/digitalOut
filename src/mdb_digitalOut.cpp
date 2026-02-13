#include "Arduino.h"
#include "mdb_digitalOut.h"
#include "mdb_timer.h"

void mdb_digitalOut::begin() {
  _outputTimer.begin();
  _currentState = _initialState;                                // Set the Current State as the Initial State
  _flashFlag = false;                                           // Turn off the flash flag
	pinMode(_output, OUTPUT);                                     // Set up the output pin
  digitalWrite(_output, _initialState);                         // Write the Initial State to the output pin
}

void mdb_digitalOut::startBlink() {                             // Function to start a blinker
    _outputTimer.resetTimer();                                  // Reset the blink timer
}

bool mdb_digitalOut::processBlink() {                           // Function to process a blinker
  if (_currentState == HIGH) {                                  // If the blinker is High
    if (_outputTimer.timeElapsed(_onDuration)) {                // If the blink ON time has elapsed (blink timer resets if true)
      _currentState = LOW;                                      // Set the Current State of the blinker to Low
      digitalWrite(_output, _currentState);                     // Turn off the output
    }
  } else {                                                      // Or the blinker is Low
    if (_outputTimer.timeElapsed(_offDuration)) {               // If the blink OFF time has elapsed (blink timer resets if true)
      _currentState = HIGH;                                     // Set the Current Stae of the blinker to High
      digitalWrite(_output, _currentState);                     // Turn off the output
    }
  }
  return (_currentState);                                       // Return the Current State of the blinker output
}

void mdb_digitalOut::adjustBlink(unsigned long onDuration, unsigned long offDuration) {
  _onDuration = onDuration;
  _offDuration = offDuration;
}

void mdb_digitalOut::holdBlink() {                              // Function that pauses blinking
  _outputTimer.resetTimer();                                    // Reset the blink timer
}

void mdb_digitalOut::startFlash() {
    digitalWrite(_output, HIGH);                                // Turn on the output
    _flashFlag = true;                                          // Show that we're flashing
    _outputTimer.resetTimer();                                  // Reset the flash timer
}

bool mdb_digitalOut::processFlash() {
  if (_flashFlag) {                                             // If we're timing the flash output
    if (_outputTimer.timeElapsed(_onDuration)) {                // If the flash time has elapsed
      digitalWrite(_output, LOW);                               // Turn off the output
      _flashFlag = false;                                       // Turn off the flash flag
    }
  }
  return (_flashFlag);                                          // Return the flash flag
}

void mdb_digitalOut::adjustFlash(unsigned long onDuration) {
  _onDuration = onDuration;
}
