#include <iostream>
#include <limits>

// Function prototypes
void showMenu();
double getNumber();
char getOperation();
double performOperation(double num1, double num2, char op);

int main() {
    char continueCalc = 'y';

    // Welcome message
    std::cout << "Welcome to the Ultimate Calculator!\n";
    std::cout << "You can perform the following operations: addition (+), subtraction (-), multiplication (*), and division (/).\n";

    while (continueCalc == 'y' || continueCalc == 'Y') {
        // Get user input
        double num1 = getNumber();
        double num2 = getNumber();
        char operation = getOperation();

        // Perform the calculation
        double result = performOperation(num1, num2, operation);

        // Display the result
        std::cout << "The result is: " << result << "\n";

        // Ask the user if they want to perform another calculation
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> continueCalc;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Thank you for using the Ultimate Calculator! Goodbye!\n";
    return 0;
}

// Function to display the menu
void showMenu() {
    std::cout << "Please choose an operation:\n";
    std::cout << "+ : Addition\n";
    std::cout << "- : Subtraction\n";
    std::cout << "* : Multiplication\n";
    std::cout << "/ : Division\n";
}

// Function to get a valid number from the user
double getNumber() {
    double number;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a valid number.\n";
        } else {
            break;
        }
    }
    return number;
}

// Function to get a valid operation from the user
char getOperation() {
    char operation;
    while (true) {
        showMenu();
        std::cout << "Enter the operation: ";
        std::cin >> operation;
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            break;
        } else {
            std::cout << "Invalid operation. Please enter a valid operation.\n";
        }
    }
    return operation;
}

// Function to perform the chosen operation
double performOperation(double num1, double num2, char op) {
    double result;
    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
                result = 0; // you might want to handle this case differently
            } else {
                result = num1 / num2;
            }
            break;
        default:
            std::cout << "Invalid operation.\n";
            result = 0; // should never reach here due to validation in getOperation()
    }
    return result;
}
