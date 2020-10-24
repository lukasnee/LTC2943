#ifndef LTC2943_HPP
#define LTC2943_HPP

/* LTC2943 datasheet: 
    analog.com/media/en/technical-documentation/data-sheets/2943fa.pdf */

class LTC2943
{
public:
    LTC2943();
    ~LTC2943();
    bool process();

private:
    bool init();
    bool deinit();
};

#endif //LTC2943_HPP