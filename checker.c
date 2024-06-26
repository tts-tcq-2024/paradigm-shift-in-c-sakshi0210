#include <stdio.h>
#include <assert.h>

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_SOC 20
#define MAX_SOC 80
#define MAX_CHARGE_RATE 0.8

// Function to check if temperature is within the acceptable range
int isTemperatureWithinRange(float temperature) {
    return (temperature >= MIN_TEMPERATURE && temperature <= MAX_TEMPERATURE);
}

// Function to check if State of Charge (SOC) is within the acceptable range
int isSocWithinRange(float soc) {
    return (soc >= MIN_SOC && soc <= MAX_SOC);
}

// Function to check if charge rate is within the acceptable range
int isChargeRateWithinRange(float chargeRate) {
    return (chargeRate <= MAX_CHARGE_RATE);
}

// Function to check the specific error condition for temperature
void checkTemperatureError(float temperature) {
    if (temperature < MIN_TEMPERATURE) {
        printf("Temperature too low!\n");
    } else if (temperature > MAX_TEMPERATURE) {
        printf("Temperature too high!\n");
    }
}

// Function to check the specific error condition for SOC
void checkSocError(float soc) {
    if (soc < MIN_SOC) {
        printf("State of Charge too low!\n");
    } else if (soc > MAX_SOC) {
        printf("State of Charge too high!\n");
    }
}

// Function to check the specific error condition for charge rate
void checkChargeRateError(float chargeRate) {
    if (chargeRate > MAX_CHARGE_RATE) {
        printf("Charge Rate too high!\n");
    }
}

// Function to check if the battery parameters are all within acceptable ranges
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int temperatureOk = isTemperatureWithinRange(temperature);
    int socOk = isSocWithinRange(soc);
    int chargeRateOk = isChargeRateWithinRange(chargeRate);

    if (!temperatureOk) {
        checkTemperatureError(temperature);
    }
    if (!socOk) {
        checkSocError(soc);
    }
    if (!chargeRateOk) {
        checkChargeRateError(chargeRate);
    }

    return temperatureOk && socOk && chargeRateOk;
}

// Function to run tests on batteryIsOk function using assertions
void runTests() {
    // Test with all parameters within range
    assert(batteryIsOk(25, 70, 0.7));

    // Test with temperature out of range and SOC out of range
    assert(!batteryIsOk(50, 85, 0)); // Should fail: Temperature too high and SOC too high

    // Test with temperature too low
    assert(!batteryIsOk(-1, 50, 0.5)); // Should fail: Temperature too low

    // Test with SOC too high
    assert(!batteryIsOk(25, 85, 0.5)); // Should fail: SOC too high

    // Test with SOC too low
    assert(!batteryIsOk(25, 15, 0.5)); // Should fail: SOC too low

    // Test with charge rate too high
    assert(!batteryIsOk(25, 50, 0.9)); // Should fail: Charge Rate too high

    // Edge case: Test with parameters on the lower edge
    assert(batteryIsOk(0, 20, 0.79)); // Should pass: Edge case, but everything within range

    // Edge case: Test with temperature just above high range
    assert(!batteryIsOk(45.1, 80, 0.8)); // Should fail: Temperature just above high range

    // Edge case: Test with parameters just within the valid range
    assert(batteryIsOk(0, 20, 0.79)); // Should pass: All parameters on the lower edge
}

int main() {
    runTests(); // Run all test cases
    printf("All tests passed!\n"); // Print message if all tests pass
    return 0; // Return success status
}


