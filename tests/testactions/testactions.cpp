#include <QObject>
#include <QtTest/QtTest>

#include "ledaction.h"
#include "motoraction.h"

class TestActions: public QObject {
    Q_OBJECT
public:

private slots:
    void testInterpolate();
    void testInterpolateBeforeStart();
    void testInterpolateAfterEnd();
    void testInterpolateZeroDuration();
    void testInterpolateColor();
    void testInterpolateMotorAngle();
};

void TestActions::testInterpolate()
{
    action::LedAction l;

    int startValue = 10;
    int endValue = 12;
    int64_t startTime = 2;
    int64_t duration = 2;

    int64_t curTime = 3;

    int expectedValue = 11;

    int actualValue = l.interpolateValue(startValue, endValue, startTime, duration, curTime);

    QVERIFY2(expectedValue == actualValue, "Wrong value from interpolate");
}

void TestActions::testInterpolateBeforeStart()
{
    action::LedAction l;

    float startValue = 1.;
    float endValue = 2.;
    int64_t startTime = 2;
    int64_t duration = 1;

    int64_t curTime = startTime - 1;

    float expectedValue = startValue;

    float actualValue = l.interpolateValue(startValue, endValue, startTime, duration, curTime);

    QVERIFY2(expectedValue == actualValue, "Wrong value before start");
}

void TestActions::testInterpolateAfterEnd()
{
    action::LedAction l;

    float startValue = 1.;
    float endValue = 2.;
    int64_t startTime = 2;
    int64_t duration = 1;

    int64_t curTime = startTime + duration + 1;

    float expectedValue = endValue;

    float actualValue = l.interpolateValue(startValue, endValue, startTime, duration, curTime);

    QVERIFY2(expectedValue == actualValue, "Wrong value after end");
}

void TestActions::testInterpolateZeroDuration()
{
    action::LedAction l;

    float startValue = 1.;
    float endValue = 2.;
    int64_t startTime = 2;
    int64_t duration = 0;

    int64_t curTime = startTime + duration + 1;

    float expectedValue = endValue;

    float actualValue = l.interpolateValue(startValue, endValue, startTime, duration, curTime);

    QVERIFY2(expectedValue == actualValue, "Wrong value for zero duration");
}

void TestActions::testInterpolateColor()
{
    action::LedAction l;

    l.startTime = 0;
    l.duration = 1000;

    l.startColor = action::LedAction::RgbColor{0, 50, 100};
    l.endColor = action::LedAction::RgbColor{100, 150, 200};

    l.playAtTime(500);

    action::LedAction::RgbColor expectedColor{50, 100, 150};

    QVERIFY2(expectedColor == l.currentColor, "Wrong color after interpolation");
}

void TestActions::testInterpolateMotorAngle()
{
    action::MotorAction m;

    m.startAngle = 60;
    m.endAngle = 80;

    m.startTime = 0;
    m.duration = 1000;

    m.playAtTime(500);

    QVERIFY2(m.currentAngle == 70, "Wrong angle after interpolation");
}

QTEST_MAIN(TestActions)

#include "testactions.moc"
