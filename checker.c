#include <stdio.h>
#include <stdbool.h>

bool isTooLow(const char* measureName, float measureValue, float lowerLimit) {
    if (measureValue < lowerLimit) {
        printf("%s is too low!\n", measureName);
        return true;
    }
    return false;
}

bool isTooHigh(const char* measureName, float measureValue, float upperLimit) {
    if (measureValue > upperLimit) {
        printf("%s is too high!\n", measureName);
        return true;
    }
    return false;
}

bool checkTemperature(float temperature) {
    return !isTooLow("Temperature", temperature, 0) && !isTooHigh("Temperature", temperature, 45);
}

bool checkSoc(float soc) {
    return !isTooLow("State of Charge", soc, 20) && !isTooHigh("State of Charge", soc, 80);
}

bool checkChargeRate(float chargeRate) {
    return !isTooLow("Charge Rate", chargeRate, 0) && !isTooHigh("Charge Rate", chargeRate, 0.8f);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(chargeRate);
}

void runTests() {
    if (!batteryIsOk(25, 70, 0.7f)) printf("Test 1 failed\n");
    if (batteryIsOk(50, 85, 0.0f)) printf("Test 2 failed\n");
    if (batteryIsOk(-1, 70, 0.7f)) printf("Test 3 failed\n");
    if (batteryIsOk(25, 10, 0.7f)) printf("Test 4 failed\n");
    if (batteryIsOk(25, 70, 0.9f)) printf("Test 5 failed\n");
    printf("Some more tests needed\n");
}

int main() {
    runTests();
    return 0;
}

