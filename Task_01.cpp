#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Function to get a random motivational message
std::string getMotivationalMessage() {
    std::vector<std::string> messages = {
        "Don't give up!",
        "You can do it!",
        "Keep trying!",
        "Almost there!",
        "You're getting closer!"
    };
    int index = std::rand() % messages.size();
    return messages[index];
}

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Welcome message
    std::cout << "Welcome to the Ultimate Guessing Game!\n";
    std::cout << "I will generate a random number, and your task is to guess it.\n";

    // Difficulty level selection
    int maxNumber;
    std::cout << "Choose your difficulty level:\n";
    std::cout << "1. Easy (1-100)\n";
    std::cout << "2. Medium (1-500)\n";
    std::cout << "3. Hard (1-1000)\n";
    std::cout << "Enter your choice (1/2/3): ";
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            maxNumber = 100;
            break;
        case 2:
            maxNumber = 500;
            break;
        case 3:
            maxNumber = 1000;
            break;
        default:
            std::cout << "Invalid choice. Defaulting to Easy level.\n";
            maxNumber = 100;
    }

    // Generate a random number between 1 and maxNumber
    int randomNumber = std::rand() % maxNumber + 1;
    int userGuess = 0;
    int attempts = 0;

    std::cout << "I have generated a random number between 1 and " << maxNumber << ".\n";
    std::cout << "Can you guess what it is?\n";

    // Loop until the user guesses the correct number
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            std::cout << "Too high! " << getMotivationalMessage() << "\n";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! " << getMotivationalMessage() << "\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
            break;
        }
    }

    // Summary of the user's performance
    std::cout << "You guessed the correct number in " << attempts << " attempts.\n";
    if (attempts <= 5) {
        std::cout << "Amazing! You are a guessing genius!\n";
    } else if (attempts <= 10) {
        std::cout << "Well done! Great job guessing.\n";
    } else {
        std::cout << "Good effort! Keep practicing to improve your guessing skills.\n";
    }

    return 0;
}
