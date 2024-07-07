#include <stdio.h>
#include <stdbool.h>

bool checkLowLimit(const char* measureName, float measureValue, float lowerLimit) {
    if (measureValue < lowerLimit) {
        printf("%s is too low!\n", measureName);
        return false;
    }
    return true;
}

bool checkHighLimit(const char* measureName, float measureValue, float upperLimit) {
    if (measureValue > upperLimit) {
        printf("%s is too high!\n", measureName);
        return false;
    }
    return true;
}

bool checkMeasure(const char* measureName, float measureValue, float lowerLimit, float upperLimit) {
    return checkLowLimit(measureName, measureValue, lowerLimit) &&
           checkHighLimit(measureName, measureValue, upperLimit);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempStatus = checkMeasure("Temperature", temperature, 0, 45);
    bool socStatus = checkMeasure("State of Charge", soc, 20, 80);
    bool chargeStatus = checkMeasure("Charge Rate", chargeRate, 0, 0.8f);
    return tempStatus && socStatus && chargeStatus;
}

void runTests() {
    if (batteryIsOk(25, 70, 0.7f) != true) printf("Test 1 failed\n");
    if (batteryIsOk(50, 85, 0.0f) != false) printf("Test 2 failed\n");
    if (batteryIsOk(-1, 70, 0.7f) != false) printf("Test 3 failed\n");
    if (batteryIsOk(25, 10, 0.7f) != false) printf("Test 4 failed\n");
    if (batteryIsOk(25, 70, 0.9f) != false) printf("Test 5 failed\n");
    printf("Some more tests needed\n");
}

int main() {
    runTests();
    return 0;
}

