#include "ESPServo.h"

int16_t ESPServo::read() {
//return map(this->current_value, 0, 180, this->low, this->high);
    return this->current_value;
}

void ESPServo::write(int16_t value) {
    this->current_value = value;
    ledcWrite(this->channel, value);
}

int16_t ESPServo::get_low() {
    return this->low;
}

int16_t ESPServo::get_high() {
return this->high;
}

int16_t ESPServo::get_mid() {
return int16_t(this->high / 2);
}
    