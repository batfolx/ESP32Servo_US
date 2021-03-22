# ESP32Servo_US

<div>
  <p>
    A small utility package that allows you to control a servo with the ESP32 with relative ease.
  </p>
  
  <p>
    There is a small example below that controls one servo.
  </p>

</div>


```
#include "ESPServo.h"

void main() {


  int8_t servo_pin = 27; // GPIO pin 27 on ESP32
  int8_t pwm_channel = 0; // select PWM channel 0
  int8_t timer_width = 16; // timer width for PWM
  int8_t hertz = 50; // default Hertz
  
  // Values for TowerPro SG90 small servos
  int16_t low = 1638;
  int16_t high = 7864;
  ESPServo servo = ESPServo(servo_pin, pwm_channel, hertz, timer_width, low, high);
  
  
  servo.write( servo.get_high() );
  delay(1000); 
  
  
  servo.write( servo.get_low() );
  delay(1000);
  
  int16_t current_value = servo.read();  
  
  
  printf("Servos current value is %d\n", current_value);

}
```


<div>
  <p>
    Here is a small exmaple controling multiple servos below.
  </p>

</div>


```
#include "ESPServo.h"

void main() {


  int8_t servo_pin_one = 27; // GPIO pin 27 on ESP32
  int8_t servo_pin_two = 26; // GPIO pin 26 on ESP32
  int8_t pwm_channel_one = 0; // select PWM channel 0 for servo_pin_one
  int8_t pwm_channel_two = 2; // select PWM channel 2 for servo_pin_one
  int8_t timer_width = 16; // timer width for PWM
  int8_t hertz = 50; // default Hertz
  
  // Values for TowerPro SG90 small servos
  int16_t low = 1638;
  int16_t high = 7864;
  ESPServo servo_one = ESPServo(servo_pin_one, pwm_channel_one, hertz, timer_width, low, high);
  ESPServo servo_two = ESPServo(servo_pin_two, pwm_channel_two, hertz, timer_width, low, high);
  
  servo_one.write( servo_one.get_high() );
  servo_two.write( servo_two.get_high() );
  delay(1000); 
  
  servo_one.write( servo_one.get_low() );
  servo_two.write( servo_two.get_low() );
  delay(1000);


}
```

