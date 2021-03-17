#include <stdint.h>
#include "esp32-hal-adc.h"

class ESPServo {
  private:
    int8_t pin;
    int8_t channel;
    int8_t hz;
    int8_t timer_width;
    int16_t current_value;
    int16_t low;
    int16_t high;
  public:
    ESPServo(int8_t pin, int8_t channel, int8_t hz, int8_t timer_width, int16_t low, int16_t high) {

      this->pin = pin;
      this->channel = channel;
      this->hz = hz;
      if ( timer_width == 0 ) {
        this->timer_width = 16; 
      } else {
        this->timer_width = timer_width;
      }
      this->low = low;
      this->high = high;
      this->current_value = 0;
      ledcSetup(channel, this->hz, this->timer_width);
      ledcAttachPin(this->pin, this->channel);
      
      
    }
  void write(int16_t value) ;
  int16_t read() ;
  int16_t get_low();
  int16_t get_high();
  int16_t get_mid();
    
    
};