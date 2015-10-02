#ifndef __VRLXBrainAnalogIn_H__
#define __VRLXBrainAnalogIn_H__

#include "AP_HAL_Linux.h"
#include <AP_ADC/AP_ADC.h>

#define VRLXBRAIN_ADC_MAX_CHANNELS 6

class VRLXBrainAnalogSource: public AP_HAL::AnalogSource {
public:
    friend class VRLXBrainAnalogIn;
    VRLXBrainAnalogSource(int16_t pin);
    float read_average();
    float read_latest();
    void set_pin(uint8_t p);
    void set_stop_pin(uint8_t p) {}
    void set_settle_time(uint16_t settle_time_ms){}
    float voltage_average();
    float voltage_latest();
    float voltage_average_ratiometric();
private:
    int16_t _pin;
    float _value;
};

class VRLXBrainAnalogIn: public AP_HAL::AnalogIn {
public:
    VRLXBrainAnalogIn();
    void init(void* implspecific);
    AP_HAL::AnalogSource* channel(int16_t n);

    /* Board voltage is not available */
    float board_voltage(void) 
    { 
        return 0.0f; 
    }
private:
    AP_ADC_ADS1115 *_adc;
    VRLXBrainAnalogSource *_channels[VRLXBRAIN_ADC_MAX_CHANNELS];

    uint8_t _channels_number;

    void _update();

    uint32_t            _last_update_timestamp;
};

#endif
