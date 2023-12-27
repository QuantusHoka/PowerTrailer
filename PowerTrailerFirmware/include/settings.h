#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>>


#define INA_MAIN_BUS_ADDR   0x40
#define INA_SOLAR_BUS_ADDR  0x44
#define INA_DC_BUS_ADDR     0x45
#define INA_SDA_PIN         SCL

#define LORA_ID             0x01



class Settings
{
    public:
    Settings(void);
    ~Settings(void);
    int save(void);
    int load(void);

    float kalman;
};

#endif