# ButtonHandler

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Arduino Library](https://img.shields.io/badge/Arduino-Library-blue)](https://www.arduino.cc/en/Reference/Libraries)

**A simple Arduino library for detecting button presses with debounce and press duration classification (short, medium, long).**

---

## Features

- Debounce handling with configurable delay  
- Detects button press events:  
  - Pressed  
  - Short press  
  - Medium press  
  - Long press  
- Non-blocking update function to call frequently in `loop()`  
- Supports active-low buttons with internal pull-ups  

---

## Installation

### Using Arduino Library Manager (recommended)

Search for **ButtonHandler** in the Arduino IDE Library Manager and install.

### Manual installation

1. Download the ZIP archive from the [releases page](#) or clone this repo  
2. Extract to your Arduino libraries folder  
3. Restart the Arduino IDE  

---

## Usage

```cpp
#include <ButtonHandler.h>

// Initialize button on pin 2
ButtonHandler button(2);

void setup() {
    Serial.begin(9600);
    Serial.println("ButtonHandler Example");
}

void loop() {
    // Call update frequently to process button state
    button.update();

    // Get event, returns BUTTON_NONE if no event
    ButtonEvent event = button.getEvent();

    switch (event) {
        case BUTTON_PRESSED:
            Serial.println("Button Pressed");
            break;
        case BUTTON_SHORT_PRESS:
            Serial.println("Short Press Detected");
            break;
        case BUTTON_MEDIUM_PRESS:
            Serial.println("Medium Press Detected");
            break;
        case BUTTON_LONG_PRESS:
            Serial.println("Long Press Detected");
            break;
        default:
            // No event
            break;
    }
}
```

---

## Constructor

```cpp
ButtonHandler(uint8_t pin, uint32_t debounceDelay = 50, uint32_t mediumPressTime = 1000, uint32_t longPressTime = 3000);
```

- `pin`: Arduino pin number connected to button (active low)  
- `debounceDelay`: Debounce time in milliseconds (default 50)  
- `mediumPressTime`: Threshold for medium press duration in milliseconds (default 1000)  
- `longPressTime`: Threshold for long press duration in milliseconds (default 3000)  

---

## API

| Method             | Description                                  |
|--------------------|----------------------------------------------|
| `void update()`    | Call frequently to read and debounce button. |
| `ButtonEvent getEvent()` | Returns the latest button event and resets it. |

---

## Contributing

Contributions are welcome! To contribute:

1. Fork the repository  
2. Create your feature branch (`git checkout -b feature/my-feature`)  
3. Commit your changes (`git commit -am 'Add some feature'`)  
4. Push to the branch (`git push origin feature/my-feature`)  
5. Open a Pull Request

Please ensure your code follows the existing style and includes comments.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## Author

Created by **Electrogics PH** — [GitHub](https://github.com/electrogicsph)
