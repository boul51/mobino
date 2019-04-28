#ifndef ACTION_LED_ACTION_H
#define ACTION_LED_ACTION_H

#include "iaction.h"

namespace action {

class LedAction: public IAction {
public:
    void playAtTime(uint32_t time);
    void updateLogicalDevice(device::ILogicalDevice *logicalDevice) override;

    struct RgbColor {
        uint8_t r = 0;
        uint8_t g = 0;
        uint8_t b = 0;
        RgbColor (uint8_t r, uint8_t g, uint8_t b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        bool operator==(const RgbColor& other) {
            return r == other.r && g == other.g && b == other.b;
        }
    };

    RgbColor startColor = {0, 0, 0};
    RgbColor endColor = {0, 0, 0};
    RgbColor currentColor = {0, 0, 0};
};

} // name space action

#endif // ACTION_LED_ACTION_H
