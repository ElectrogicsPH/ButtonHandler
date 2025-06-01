#include <ButtonHandler.h>

ButtonHandler button(2);

void setup() {
    Serial.begin(9600);
    Serial.println("ButtonHandler Example");
}

void loop() {
    button.update();

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
            break;
    }
}
