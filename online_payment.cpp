#include <iostream>
#include <string>
using namespace std;

// Base class
class Payment {
    
};

// Derived class for Credit Card payments
class CreditCard : public Payment {

};

// Derived class for Bkash payments
class Bkash : public Payment {

};

// Derived class for Nagad payments
class Nagad : public Payment {

};

// Overloaded executePayment functions for each payment method
void executePayment(const CreditCard& payment) {
    payment.validate();
    payment.processPayment();
    payment.transactionDetails();
}

void executePayment(const Bkash& payment) {
    payment.validate();
    payment.processPayment();
    payment.transactionDetails();
}

void executePayment(const Nagad& payment) {
    payment.validate();
    payment.processPayment();
    payment.transactionDetails();
}

int main() {
    int choice;

    // Prompt user to choose a payment method
    cout << "Select a payment method:\n";
    cout << "1. Credit Card\n";
    cout << "2. Bkash\n";
    cout << "3. Nagad\n";
    cout << "Enter choice (1-3): ";
    cin >> choice;

    // Execute the selected payment method
    switch (choice) {
        case 1: {
            CreditCard creditCardPayment;
            cout << "=== Credit Card Payment ===" << endl;
            executePayment(creditCardPayment);
            break;
        }
        case 2: {
            Bkash bkashPayment;
            cout << "\n=== Bkash Payment ===" << endl;
            executePayment(bkashPayment);
            break;
        }
        case 3: {
            Nagad nagadPayment;
            cout << "\n=== Nagad Payment ===" << endl;
            executePayment(nagadPayment);
            break;
        }
        default:
            cout << "Invalid choice. Please select a valid payment method." << endl;
            break;
    }

    return 0;
}
