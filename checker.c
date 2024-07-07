#include <stdio.h>
#include <stdbool.h>

bool isValueInRange(const char* measureName, float value, float lowerLimit, float upperLimit) {
    if (value < lowerLimit) {
        printf("%s is too low!\n", measureName);
        return false;
    }
    if (value > upperLimit) {
        printf("%s is too high!\n", measureName);
        return false;
    }
    return true;
}

bool checkTemperature(float temperature) {
    return isValueInRange("Temperature", temperature, 0, 45);
}

bool checkSoc(float soc) {
    return isValueInRange("State of Charge", soc, 20, 80);
}

bool checkChargeRate(float chargeRate) {
    return isValueInRange("Charge Rate", chargeRate, 0, 0.8f);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool tempOk = checkTemperature(temperature);
    bool socOk = checkSoc(soc);
    bool chargeOk = checkChargeRate(chargeRate);
    return tempOk && socOk && chargeOk;
}

int main() {
    // Test cases
    if (!batteryIsOk(25, 70, 0.7f)) return 1;
    if (batteryIsOk(50, 85, 0.0f)) return 1;
    if (batteryIsOk(-1, 70, 0.7f)) return 1;
    if (batteryIsOk(25, 10, 0.7f)) return 1;
    if (batteryIsOk(25, 70, 0.9f)) return 1;
    printf("Some more tests needed\n");
    return 0;
}
