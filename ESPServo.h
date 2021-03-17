#include <stdint.h>
#include "esp32-hal-adc.h"

// Values for TowerPro SG90 small servos; adjust if needed
#define COUNT_LOW 1638
#define COUNT_HIGH 7864
#define COUNT_MID COUNT_HIGH / 2
#define TIMER_WIDTH 16
#define HZ_US 50
#define DELAY 50



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

      if ( hz == 0 ) {
        this->hz = HZ_US;
      } else {
        this->hz = hz;
      }
      if ( timer_width == 0 ) {
        this->timer_width = 16; 
      } else {
        this->timer_width = timer_width;
      }

      if ( low == -1 ) {
         this->low = COUNT_LOW;
      } else {
        this->low = low;  
      }

      if ( high == -1 ) {
         this->high = COUNT_HIGH;
      } else {
         this->high = high;  
      }
      
      
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