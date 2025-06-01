/**
 * @file ButtonHandler.cpp
 * @brief Implementation of the ButtonHandler class for debounced button press handling.
 *
 * @author Electrogics PH
 * @date 2025
 */

 #include "ButtonHandler.h"

 /**
  * @brief Construct a new ButtonHandler object.
  *
  * Initializes the pin as input with pull-up resistor and sets timing thresholds.
  *
  * @param pin GPIO pin connected to the button (assumes active-low)
  * @param debounceDelay Debounce time in milliseconds (default: 50ms)
  * @param mediumPressTime Threshold in milliseconds for a medium press (default: 1000ms)
  * @param longPressTime Threshold in milliseconds for a long press (default: 3000ms)
  */
 ButtonHandler::ButtonHandler(uint8_t pin, uint32_t debounceDelay, uint32_t mediumPressTime, uint32_t longPressTime)
     : _pin(pin)
     , _debounceDelay(debounceDelay)
     , _mediumPressTime(mediumPressTime)
     , _longPressTime(longPressTime)
 {
     pinMode(_pin, INPUT_PULLUP); // Assume active-low button
     _lastState       = digitalRead(_pin);
     _currentState    = _lastState;
     _lastStateChange = millis();
     _event           = BUTTON_NONE;
 }
 
 /**
  * @brief Call this regularly in loop() to update and process button state.
  */
 void ButtonHandler::update()
 {
     bool reading = digitalRead(_pin);
 
     // Debounce logic
     if(reading != _lastState)
     {
         _lastStateChange = millis(); // Reset the debounce timer
     }
 
     if((millis() - _lastStateChange) > _debounceDelay)
     {
         if(reading != _currentState)
         {
             _currentState = reading;
 
             if(!_currentState)
             { // Button pressed
                 _pressStartTime = millis();
                 _event          = BUTTON_PRESSED;
             }
             else
             {                  // Button released
                 detectEvent(); // Call the separated event detection logic
             }
         }
     }
 
     _lastState = reading;
 }
 
 /**
  * @brief Internal method to classify the press as short, medium, or long.
  */
 void ButtonHandler::detectEvent()
 {
     uint32_t pressDuration = millis() - _pressStartTime;
 
     if(pressDuration < _mediumPressTime)
     {
         _event = BUTTON_SHORT_PRESS;
     }
     else if(pressDuration < _longPressTime)
     {
         _event = BUTTON_MEDIUM_PRESS;
     }
     else
     {
         _event = BUTTON_LONG_PRESS;
     }
 }
 
 /**
  * @brief Get the last button event and reset it to BUTTON_NONE.
  *
  * @return ButtonEvent The last detected event
  */
 ButtonEvent ButtonHandler::getEvent()
 {
     ButtonEvent temp = _event;
     _event           = BUTTON_NONE; // Reset the event to avoid duplicate readings
     return temp;
 }
 