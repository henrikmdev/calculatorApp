#include <stdio.h>

int main() {
    int choice;
    double billAmount, tipPercentage, tipAmount, totalAmount;
    double num1, num2;
    char operator;

    printf("Welcome to the Tip Calculator and Basic Calculator Program!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Tip Calculator\n");
        printf("2. Basic Calculations (Addition, Subtraction, Multiplication, Division)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // Input validation for menu choice
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            printf("Enter your choice: ");
        }

        switch (choice) {
            case 1:
                // Tip Calculator
                printf("Enter the bill amount: ");
                while (scanf("%lf", &billAmount) != 1 || billAmount < 0) {
                    printf("Invalid input. Please enter a valid positive number for the bill amount: ");
                    while (getchar() != '\n'); // Clear input buffer
                }

                printf("Enter the tip percentage: ");
                while (scanf("%lf", &tipPercentage) != 1 || tipPercentage < 0) {
                    printf("Invalid input. Please enter a valid positive number for the tip percentage: ");
                    while (getchar() != '\n'); // Clear input buffer
                }

                tipAmount = billAmount * (tipPercentage / 100);
                totalAmount = billAmount + tipAmount;

                printf("Tip amount: $%.2f\n", tipAmount);
                printf("Total amount (including tip): $%.2f\n", totalAmount);
                break;

            case 2:
                // Basic Calculations
                printf("Enter the first number: ");
                while (scanf("%lf", &num1) != 1) {
                    printf("Invalid input. Please enter a valid number: ");
                    while (getchar() != '\n'); // Clear input buffer
                }

                printf("Enter an operator (+, -, *, /): ");
                while (scanf(" %c", &operator) != 1 || (operator != '+' && operator != '-' && operator != '*' && operator != '/')) {
                    printf("Invalid input. Please enter one of +, -, *, /: ");
                    while (getchar() != '\n'); // Clear input buffer
                }

                printf("Enter the second number: ");
                while (scanf("%lf", &num2) != 1 || (operator == '/' && num2 == 0)) {
                    if (operator == '/' && num2 == 0) {
                        printf("Error: Division by zero is not allowed. Please enter a non-zero number: ");
                    } else {
                        printf("Invalid input. Please enter a valid number: ");
                    }
                    while (getchar() != '\n'); // Clear input buffer
                }

                switch (operator) {
                    case '+':
                        printf("Result: %.2f\n", num1 + num2);
                        break;
                    case '-':
                        printf("Result: %.2f\n", num1 - num2);
                        break;
                    case '*':
                        printf("Result: %.2f\n", num1 * num2);
                        break;
                    case '/':
                        printf("Result: %.2f\n", num1 / num2);
                        break;
                    default:
                        printf("Invalid operator. Please enter one of +, -, *, /.\n");
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
