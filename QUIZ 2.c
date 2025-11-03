/*
NAME: KEITH BARRACK
REG NO: PA106/G/29044/25
DESCRIPTION:  PROGRAM TO DISPLAY NUMERICS
*/
#include <stdio.h>

int main() {
    float hours, wage;
    float grossPay, tax, netPay;
    int result;

    // Input hours
    printf("Enter hours worked in a week: ");
    while ((result = scanf("%f", &hours)) != 1 || hours < 0) {
        if (result != 1) {
            printf("Invalid input. Please enter a numeric value: ");
            while (getchar() != '\n'); // Clear invalid input
        } else {
            printf("Hours cannot be negative. Try again: ");
        }
    }

    // Input wage
    printf("Enter hourly wage: ");
    while ((result = scanf("%f", &wage)) != 1 || wage < 0) {
        if (result != 1) {
            printf("Invalid input. Please enter a numeric value: ");
            while (getchar() != '\n');
        } else {
            printf("Wage cannot be negative. Try again: ");
        }
    }

    // Calculate gross pay with overtime
    if (hours > 40) {
        grossPay = (40 * wage) + ((hours - 40) * wage * 1.5);
    } else {
        grossPay = hours * wage;
    }

    // Calculate tax
    if (grossPay <= 600) {
        tax = grossPay * 0.15;
    } else {
        tax = (600 * 0.15) + ((grossPay - 600) * 0.20);
    }

    // Calculate net pay
    netPay = grossPay - tax;

    // Output
    printf("\nGross Pay: $%.2f\n", grossPay);
    printf("Taxes: $%.2f\n", tax);
    printf("Net Pay: $%.2f\n", netPay);

    return 0;
}