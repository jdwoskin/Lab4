#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temperature;
    int input_scale, target_scale;

    printf("Enter the temperature value: ");
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    printf("Choose the temperature scale of the input value (1: Fahrenheit, 2: Celsius, 3: Kelvin): ");
    if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        return 1;
    }

    printf("Choose the conversion target (1: Fahrenheit, 2: Celsius, 3: Kelvin): ");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        return 1;
    }

    if (input_scale == target_scale) {
        printf("Input scale and target scale are the same. No conversion needed.\n");
        return 1;
    }

    // Convert the input temperature to the target scale
    switch (input_scale) {
        case 1: // Fahrenheit
            if (target_scale == 2) {
                converted_temperature = fahrenheit_to_celsius(temperature);
            } else {
                converted_temperature = fahrenheit_to_kelvin(temperature);
            }
            break;
        case 2: // Celsius
            if (target_scale == 1) {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else {
                converted_temperature = celsius_to_kelvin(temperature);
            }
            break;
        case 3: // Kelvin
            if (temperature < 0) {
                printf("Invalid temperature value. Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_scale == 1) {
                converted_temperature = kelvin_to_fahrenheit(temperature);
            } else {
                converted_temperature = kelvin_to_celsius(temperature);
            }
            break;
    }

    printf("Converted temperature: %.2f\n", converted_temperature);

    // Categorize the temperature based on Celsius value
    float celsius_value;
    if (target_scale == 1) {
        celsius_value = fahrenheit_to_celsius(converted_temperature);
    } else if (target_scale == 2) {
        celsius_value = converted_temperature;
    } else {
        celsius_value = kelvin_to_celsius(converted_temperature);
    }

    categorize_temperature(celsius_value);

    return 0;
}

// Function definitions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Wear a heavy coat.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Category: Comfortable\nAdvisory: Enjoy the weather.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Category: Hot\nAdvisory: Stay hydrated.\n");
    } else {
        printf("Category: Extreme Heat\nAdvisory: Stay indoors and stay cool.\n");
    }
}