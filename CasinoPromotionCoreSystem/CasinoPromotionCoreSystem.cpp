#include "Customer.h"

/*
* I use a map structure to store customers, and then delete them to avoid memory leaks.
* The key in the map is the customer's id, and the
* value is a pointer to the instance of the Customer class.
*/
map<string, Customer*> storedCustomers;
ifstream transictions("/data/transactions.txt"); // Attempt to open "transictions.txt".
ofstream results("/data/results.txt"); // Declare an ofstream variable named resutls.

void registerCase() {
    string user_id; // User's id
    transictions >> user_id; // Store this id in a string.
    storedCustomers[user_id] = new Customer();
}

void scenarioCase() {
    int prize1, prize2, prize3; // Prize amounts
    transictions >> prize1 >> prize2 >> prize3;
    Customer::addScenario(prize1, prize2, prize3);
}

void depositCase() {
    string user_id;
    int amount; // Deposit amount
    transictions >> user_id >> amount;
    storedCustomers[user_id]->deposit(amount);
}

void betCase() {
    string user_id;
    string betType; // Bet type (SLOT, CASINO, SPORT)
    int amount; // Bet amount
    transictions >> user_id >> betType >> amount;
    storedCustomers[user_id]->bet(amount, betType);
}

void balanceCase() {
    string user_id;
    transictions >> user_id; // Current balance
    results << storedCustomers[user_id]->getBalance() << endl;
}

int main()
{

    if (transictions.is_open()) { // Check if the file exists

        // Someone must register in the first line.
        string tmp, user_id;
        transictions >> tmp >> user_id;
        storedCustomers[user_id] = new Customer();
      
        string line;
        while (getline(transictions, line)) { // Read input file line by line.
            string command; // Command (deposite, bet, addscenario, balance, register).
            transictions >> command; // Store this command in a string.
            if (command == "register") registerCase();
            else if (command == "addscenario") scenarioCase();
            else if (command == "deposit") depositCase();
            else if (command == "bet") betCase();
            else if (command == "balance") balanceCase();
        }

        transictions.close(); // Close the input file.
        results.close(); // ,,-----,, output file.
        for (auto p : storedCustomers) { // Iterates through a map of <string,pointers> and deallocates the heap memory for each pointer, as it is no longer in use.
            delete p.second;
        }
    }

    else {
        cout << "Unable to open file." << endl; // If the file doesn't exist.
    }

}
