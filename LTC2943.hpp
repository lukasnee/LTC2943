#ifndef LTC2943_HPP
#define LTC2943_HPP

/* LTC2943 datasheet: 
    analog.com/media/en/technical-documentation/data-sheets/2943fa.pdf */

class LTC2943
{
public:
    typedef enum Result 
    {
        RESULT_OK = 0,
        RESULT_FAIL,
        RESULT_INIT_FAIL,
        RESULT_DEINIT_FAIL,
        RESULT_READ_FAIL,
        RESULT_WRITE_FAIL,
        RESULT_NOT_INITIALIZED,
        RESULT_ARGUMENT_NULL
    }Result;    

    typedef enum AdcMode_
    {
        adcModeSleep = 0,
        adcModeManual,
        adcModeScan,
        adcModeAutomatic
    }AdcMode;

    typedef enum PrescalerM
    {
        prescalerMx1 = 0,
        prescalerMx4,
        prescalerMx16,
        prescalerMx64,
        prescalerMx256,
        prescalerMx1024,
        prescalerMx4096
    }PrescalerM;

    typedef enum AlccPinConfig
    {
        alccPinDisabled = 0,
        alccChargeCompleteMode,
        alccAlertMode
    }AlccPinConfig;

    Result init();
    Result getAdcMode(AdcMode &mode);
    Result setAdcMode(AdcMode mode);
    Result checkVoltageAlert(bool &isPending);
    Result checkTemperatureAlert(bool &isPending);
    Result deinit();

    LTC2943();
    ~LTC2943();
private:
    union StatusReg
    {
        struct {
            uint8_t undervoltageLockoutAlertFlag            :1;
            uint8_t voltageAlertFlag                        :1;
            uint8_t chargeAlertLow                          :1;
            uint8_t chargeAlertHigh                         :1;
            uint8_t temperatureAlert                        :1;
            uint8_t accumulatedChargeOverflowOrUnderflow    :1;
            uint8_t currentAlert                            :1;
            uint8_t _reserved                               :1;
        } regFields;
        uint8_t byte;
    };

    union ControlReg
    {
        struct {
            uint8_t shutdown                :1;
            uint8_t alccPinConfiguration    :2;
            uint8_t prescalerM              :3; // enum PrescalerM
            uint8_t adcMode                 :2;
        } fields;
        uint8_t byte;
    };
    
    Result setControl(ControlReg reg);
    Result getControl(ControlReg &reg);
    Result getStatus(StatusReg &reg);
    Result write(const uint8_t * pSrc, uint16_t dataSize);
    Result read(uint8_t * pDst, uint16_t dataSize);
    Result isIntialized();
};

#endif //LTC2943_HPP