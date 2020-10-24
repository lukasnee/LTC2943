#ifndef LTC2943_HPP
#define LTC2943_HPP

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