#pragma once

#include <unistd.h>
#include <memory>
#include "NAVIO_Interface/Navio2/PWM.h"
#include "NAVIO_Interface/Navio2/RCOutput_Navio2.h"
#include "NAVIO_Interface/Navio2/Common/Util.h"
#include "HEAR_actuation/Actuator.hpp"

class ESCMotor : public Actuator {
private:
    int _pwmPin;
    int _freq;
    RCOutput* _pwm;
public:
    bool initialize();
    void applyCommand(int command);
    RCOutput* get_rcout();
    ESCMotor(int, int);
};