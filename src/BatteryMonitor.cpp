#include "HEAR_NAVIO_Interface/BatteryMonitor.hpp"

BatteryMonitor::BatteryMonitor() {
    _output_port_0 = new OutputPort(ports_id::OP_0, this);
    adc = std::unique_ptr <ADC>{ new ADC_Navio2() };
    adc->initialize();
}

BatteryMonitor::~BatteryMonitor() {

}

float BatteryMonitor::getVoltageReading(){
    results[BATTERY_VOLTAGE_PIN] = adc->read(BATTERY_VOLTAGE_PIN);
    if (results[BATTERY_VOLTAGE_PIN] == READ_FAILED){
        return EXIT_FAILURE;
    }
    _voltage_reading.data = results[BATTERY_VOLTAGE_PIN] * SCALE + OFFSET;
    this->_output_port_0->receiveMsgData((DataMsg*)&_voltage_reading);
}