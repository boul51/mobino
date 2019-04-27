#include "sleepyshowmanager.h"

#include "ledaction.h"
#include "motoraction.h"
#include "track.h"
#include "ilogicaldevice.h"
#include "logicalleddevice.h"
#include "devicetype.h"

namespace show {

void show::SleepyShowManager::generateTracksActions(int64_t time)
{
    for (int i = 0; i < tracks.length(); i++) {
        show::Track* track = tracks.at(i);
        action::IAction* newAction = nullptr;
        action::IAction* prevAction = track->prevActiveActionAtTime(time);
        if (!track->activeActionAtTime(time)) {
            switch (track->logicalDevice->deviceType) {
            case device::DeviceType::Led:
              {
                action::LedAction* prevLedAction = static_cast<action::LedAction*>(prevAction);
                action::LedAction* newLedAction = new action::LedAction();
                device::LogicalLedDevice* ledDevice = static_cast<device::LogicalLedDevice*>(track->logicalDevice);
                if (prevLedAction)
                    newLedAction->startColor = prevLedAction->endColor;
                else
                    newLedAction->startColor = ledDevice->ledIndex % 2 ?
                                action::LedAction::RgbColor(0, 0, 0) :
                                action::LedAction::RgbColor(100, 0, 100);
                newLedAction->endColor = newLedAction->startColor.r == 0 ?
                            action::LedAction::RgbColor(100, 0, 100):
                            action::LedAction::RgbColor(0, 0, 0);
                newLedAction->startTime = time;
                newLedAction->duration = 2000;
                newAction = newLedAction;
                break;
              }
            case device::DeviceType::Motor:
              {
                action::MotorAction* prevMotorAction = static_cast<action::MotorAction*>(prevAction);
                action::MotorAction* newMotorAction = new action::MotorAction();
                if (prevMotorAction)
                    newMotorAction->startAngle = prevMotorAction->endAngle;
                else
                    newMotorAction->startAngle = 10;
                newMotorAction->endAngle = newMotorAction->startAngle == 10 ? 170: 10;
                newMotorAction->startTime = time;
                newMotorAction->duration = 5000;
                newAction = newMotorAction;
                break;
              }
            default:
                break;
            }
            if (newAction)
                track->appendAction(newAction);
        }
    }
}

} // namespace show
