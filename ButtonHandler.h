/**
 * @file ButtonHandler.h
 * @brief Button handling library with support for debounce, short, medium, and long press detection.
 *
 * @author Electrogics PH
 * @date 2025
 *
 * This library allows you to easily detect different types of button presses
 * (short, medium, and long) with debouncing, without blocking delays.
 */

 #ifndef ButtonHandler_H
 #define ButtonHandler_H
 
 #include <Arduino.h>
 
 /**
  * @enum ButtonEvent
  * @brief Possible button events.
  */
 enum ButtonEvent
 {
     BUTTON_NONE,         ///< No event
     BUTTON_PRESSED,      ///< Button is currently pressed
     BUTTON_SHORT_PRESS,  ///< Short press detected
     BUTTON_MEDIUM_PRESS, ///< Medium press detected
     BUTTON_LONG_PRESS    ///< Long press detected
 };
 
 /**
  * @class ButtonHandler
  * @brief Handles button input with debounce and press duration detection.
  */
 class ButtonHandler
 {
 public:
     /**
      * @brief Construct a new Button Handler object
      *
      * @param pin GPIO pin connected to the button
      * @param debounceDelay Debounce time in milliseconds (default 50ms)
      * @param mediumPressTime Time in milliseconds for a medium press (default 1000ms)
      * @param longPressTime Time in milliseconds for a long press (default 3000ms)
      */
     ButtonHandler(uint8_t pin, uint32_t debounceDelay = 50, uint32_t mediumPressTime = 1000, uint32_t longPressTime = 3000);
 
     /**
      * @brief Call this function regularly (e.g. in loop) to update the button state.
      */
     void update();
 
     /**
      * @brief Get the last detected button event.
      *
      * @return ButtonEvent type indicating what kind of press occurred
      */
     ButtonEvent getEvent();
 
 private:
     uint8_t  _pin;
     uint32_t _debounceDelay;
     uint32_t _mediumPressTime;
     uint32_t _longPressTime;
 
     uint32_t _lastStateChange;
     uint32_t _pressStartTime;
 
     bool _lastState;
     bool _currentState;
     bool _releasedEventPending;
 
     ButtonEvent _event;
 
     /**
      * @brief Internal function to detect button events based on timing.
      */
     void detectEvent();
 };
 
 #endif // ButtonHandler_H
 