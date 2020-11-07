#pragma once
#include "HEAR_NAVIO_Interface/Navio2/Common/Util.h"
#include "HEAR_NAVIO_Interface/Navio2/ADC_Navio2.h"
#include <memory>
#include "HEAR_core/Block.hpp"
#include "HEAR_core/OutputPort.hpp"
#include "HEAR_msg/FloatMsg.hpp"

#define READ_FAILED -1
int const BATTERY_VOLTAGE_PIN = 2;
float const SCALE = 0.0108; //SCALE and OFFSET were obtained through constant measurements between Navio data and Voltimeter
float const OFFSET = 0.416;
class BatteryMonitor : public Block{

private:
    Port* _output_port_0;
    std::unique_ptr<ADC> adc;
    float results[6] = {0.0f};
    FloatMsg _voltage_reading;
public:
    enum ports_id {OP_0};
    float getVoltageReading();
    void process(DataMsg* t_msg, Port* t_port) {};
    BatteryMonitor();
    ~BatteryMonitor();
};