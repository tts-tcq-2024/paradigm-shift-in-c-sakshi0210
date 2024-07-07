#include <stdio.h>
#include <stdbool.h>

bool checkMeasure(const char* measureName, float measureValue, float lowerLimit, float upperLimit) {
    bool status = true;
    if (measureValue < lowerLimit) {
        printf("%s is too low!\n", measureName);
        status = false;
    } else if (measureValue > upperLimit) {
        printf("%s is too high!\n", measureName);
        status = false;
    }
    return status;
}

bool checkTemperature(float temperature) {
    return checkMeasure("Temperature", temperature, 0, 45);
}

bool checkSoc(float soc) {
    return checkMeasure("State of Charge", soc, 20, 80);
}

bool checkChargeRate(float chargeRate) {
    return checkMeasure("Charge Rate", chargeRate, 0, 0.8f);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkTemperature(temperature) && checkSoc(soc) && checkChargeRate(chargeRate);
}

int main() {
    // Test cases
    if (batteryIsOk(25, 70, 0.7f) != true) return 1;
    if (batteryIsOk(50, 85, 0.0f) != false) return 1;
    if (batteryIsOk(-1, 70, 0.7f) != false) return 1;
    if (batteryIsOk(25, 10, 0.7f) != false) return 1;
    if (batteryIsOk(25, 70, 0.9f) != false) return 1;
    printf("Some more tests needed\n");
    return 0;
}


