/*https://www.analog.com/media/en/technical-documentation/data-sheets/2943fa.pdf */

#define LTC2943_I2C_ADDRESS 0b1100100

////////////////////////////////////////////////////////////////////////////////
// register map
////////////////////////////////////////////////////////////////////////////////
//      NAME    ADDRESS     REGISTER DESCRIPTION            R/W     DEFAULT
#define REG_A   0x00        // Status                       R
#define REG_B   0x01        // Control                      R/W     3Ch
#define REG_C   0x02        // Accumulated Charge MSB       R/W     7Fh
#define REG_D   0x03        // Accumulated Charge LSB       R/W     FFh
#define REG_E   0x04        // Charge Threshold High MSB    R/W     FFh
#define REG_F   0x05        // Charge Threshold High LSB    R/W     FFh
#define REG_G   0x06        // Charge Threshold Low MSB     R/W     00h
#define REG_H   0x07        // Charge Threshold Low LSB     R/W     00h
#define REG_I   0x08        // Voltage MSB                  R       00h
#define REG_J   0x09        // Voltage LSB                  R       00h
#define REG_K   0x0A        // Voltage Threshold High MSB   R/W     FFh
#define REG_L   0x0B        // Voltage Threshold High LSB   R/W     FFh
#define REG_M   0x0C        // Voltage Threshold Low MSB    R/W     00h
#define REG_N   0x0D        // Voltage Threshold Low LSB    R/W     00h
#define REG_O   0x0E        // Current MSB                  R       00h
#define REG_P   0x0F        // Current LSB                  R       00h
#define REG_Q   0x10        // Current Threshold High MSB   R/W     FFh
#define REG_R   0x11        // Current Threshold High LSB   R/W     FFh
#define REG_S   0x12        // Current Threshold Low MSB    R/W     00h
#define REG_T   0x13        // Current Threshold Low LSB    R/W     00h
#define REG_U   0x14        // Temperature MSB              R       00h
#define REG_V   0x15        // Temperature LSB              R       00h
#define REG_W   0x16        // Temperature Threshold High   R/W     FFh
#define REG_X   0x17        // Temperature Threshold Low    R/W     00h
    
////////////////////////////////////////////////////////////////////////////////
// Status register REG_A flags
////////////////////////////////////////////////////////////////////////////////
#define STATUS_REG_BIT_7 (1 << 7) // Reserved
#define STATUS_REG_BIT_6 (1 << 6) // Current Alert
#define STATUS_REG_BIT_5 (1 << 5) // Accumulated Charge Overflow/Underflow
#define STATUS_REG_BIT_4 (1 << 4) // Temperature Alert
#define STATUS_REG_BIT_3 (1 << 3) // Charge Alert High
#define STATUS_REG_BIT_2 (1 << 2) // Charge ALert Low
#define STATUS_REG_BIT_1 (1 << 1) // Voltage Alert
#define STATUS_REG_BIT_0 (1 << 0) // Undervoltage Lockout Alert

////////////////////////////////////////////////////////////////////////////////
// Control register REG_B fields
////////////////////////////////////////////////////////////////////////////////
#define CONTROL_REG_ADC_MODE_POS            6
#define CONTROL_REG_ADC_MODE_BITWIDTH       2
#define CONTROL_REG_ADC_MODE_MASK           0b11000000

#define CONTROL_REG_PRESCALER_M_POS         3 
#define CONTROL_REG_PRESCALER_M_BITWIDTH    3
#define CONTROL_REG_PRESCALER_M_MASK        0b00111000

#define CONTROL_REG_ALCC_POS                1 
#define CONTROL_REG_ALCC_BITWIDTH           2 
#define CONTROL_REG_ALCC_MASK               0b00000110

#define CONTROL_REG_SHUTDOWN_POS            1 
#define CONTROL_REG_SHUTDOWN_BITWIDTH       1
#define CONTROL_REG_SHUTDOWN_MASK           0b00000001
