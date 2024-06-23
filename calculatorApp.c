#include <stdio.h>

// Function prototypes
void displayMenu();
int getMenuChoice();
void tipCalculator();
void basicCalculator();
double getPositiveDoubleInput(const char *prompt);
char getOperator();
double performCalculation(double num1, char operator, double num2);

int main() {
    int choice;

    printf("Welcome to the Tip Calculator and Basic Calculator Program!\n");

    while (1) {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                tipCalculator();
                break;

            case 2:
                basicCalculator();
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

void displayMenu() {
    printf("\nSelect an option:\n");
    printf("1. Tip Calculator\n");
    printf("2. Basic Calculations (Addition, Subtraction, Multiplication, Division)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int getMenuChoice() {
    int choice;
    while (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); // Clear input buffer
        displayMenu();
    }
    return choice;
}

void tipCalculator() {
    double billAmount, tipPercentage, tipAmount, totalAmount;

    billAmount = getPositiveDoubleInput("Enter the bill amount: ");
    tipPercentage = getPositiveDoubleInput("Enter the tip percentage: ");

    tipAmount = billAmount * (tipPercentage / 100);
    totalAmount = billAmount + tipAmount;

    printf("Tip amount: $%.2f\n", tipAmount);
    printf("Total amount (including tip): $%.2f\n", totalAmount);
}

void basicCalculator() {
    double num1, num2;
    char operator;
    double result;

    num1 = getPositiveDoubleInput("Enter the first number: ");
    operator = getOperator();
    num2 = getPositiveDoubleInput("Enter the second number: ");

    result = performCalculation(num1, operator, num2);

    printf("Result: %.2f\n", result);
}

double getPositiveDoubleInput(const char *prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1 || value < 0) {
        printf("Invalid input. Please enter a valid positive number: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    return value;
}

char getOperator() {
    char op;
    printf("Enter an operator (+, -, *, /): ");
    while (scanf(" %c", &op) != 1 || (op != '+' && op != '-' && op != '*' && op != '/')) {
        printf("Invalid input. Please enter one of +, -, *, /: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    return op;
}

double performCalculation(double num1, char operator, double num2) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                printf("Error: Division by zero is not allowed.\n");
                return 0.0; // Return 0 if division by zero
            }
        default:
            printf("Invalid operator.\n");
            return 0.0;
    }
}
