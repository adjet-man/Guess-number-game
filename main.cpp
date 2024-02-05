#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0)); // set seed for random number generation
    int num1, num2, result, guess;
    char operation;
    bool correct = false;
    
    num1 = rand() % 100 + 1; // generate random number between 1 and 100 for num1
    num2 = rand() % 100 + 1; // generate random number between 1 and 100 for num2
    
    // randomly select an operation
    switch (rand() % 3) {
        case 0:
            operation = '+';
            result = num1 + num2;
            break;
        case 1:
            operation = '-';
            result = num1 - num2;
            break;
        case 2:
            operation = '*';
            result = num1 * num2;
            break;
    }
    
    cout << "Guess the result of the operation:\n";
    cout << num1 << " " << operation << " " << num2 << " = ";
    
    while (!(cin >> guess)) { // loop until valid input is received
        cin.clear(); // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter an integer: ";
    }
    
    if (guess == result) {
        cout << "Congratulations! You guessed correctly.\n";
        correct = true;
    } else {
        cout << "Sorry, the correct answer was " << result << ".\n";
    }
    
    // allow the user to continue guessing until they are correct
    while (!correct) {
        cout << "Guess again: ";
        
        while (!(cin >> guess)) { // loop until valid input is received
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter an integer: ";
        }
        
        if (guess == result) {
            cout << "Congratulations! You guessed correctly.\n";
            correct = true;
        } else {
            cout << "Sorry, try again.\n";
        }
    }
    
    return 0;
}