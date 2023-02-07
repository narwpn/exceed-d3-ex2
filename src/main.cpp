#include <Arduino.h>

#define BLUE 5
int delay_time = 0;

void setup(){
    Serial.begin(115200);
    pinMode(BLUE, OUTPUT);

    xTaskCreatePinnedToCore(loop, "loop", 1000, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(GET_delay, "GET_delay", 1000, NULL, 1, NULL, 1);
}
void loop() {
    digitalWrite(BLUE, HIGH);
    delay(delay_time);
    digitalWrite(BLUE, LOW);
    delay(delay_time);
}