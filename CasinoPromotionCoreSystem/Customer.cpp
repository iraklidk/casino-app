#include "Customer.h"

// READ THE HEADER FILE (Customer.h) BEFORE THIS !!!

bool Customer::win = true; // Initialize the static bool member to track winning cases.
vvpbi Customer::scenarios; // You can find a description of this variable in the class interface.

/*
 * Function: Coustomer
 * Constructor initializes a customer instance with an empty balance
*/
Customer::Customer() {
	balance = 0;
	totalBet = 0;
	totalDeposit = 0;
	currentScenario;
}

/*
 * Function: ~Coustomer
 * Destructor for the MyClass class.
 * This function is automatically called when an
 * instance of Customer is no longer usable.
 * This function prevents memory leaks.
*/
Customer::~Customer() {

}

/*
 * Function: addScenario
 * This func adds scenario into static data of scenarios
*/
void Customer::addScenario(int prize1, int prize2, int prize3) {
	pbi p1, p2, p3;
	p1.second = prize1; p2.second = prize2; p3.second = prize3;
	vector<pbi> eachScenario = { p1, p2, p3 };
	scenarios.push_back(eachScenario);
}

/*
 * This method evaluates whether the current
 * deposit and bet amounts of the customer satisfy
 * the conditions specified in the available scenarios 
 * to win a prize. If the conditions are met,
 * and the prize has not been awarded before, 
 * it marks the prize as used and notifies the customer.
*/
void Customer::checkPrize(int totalBet, int totalDeposit) {
	if (totalDeposit < 100 || totalBet < 50 || (currentScenario.size() > 0 && currentScenario[2].first)) return; // Not yet or user already take 3 prize

	if (currentScenario.size() == 0) {
		for (int i = 0; i < scenarios.size();i++) {
			if (!scenarios[i][0].first) {
				currentScenario = scenarios[i]; // Provide the customer's scenario
				scenarios[i][0].first = 1; // Marked this scenario as used

				// This is a bit confusing.
				// This function checks which prize
				// the user deserves after assigning them a scenario
				/* Recursive leap of faith :D */
				checkPrize(totalBet, totalDeposit);
				return;
			}
		}
	}

	else { // prize1 case
		if (totalDeposit >= 100 && totalBet >= 50 && !currentScenario[0].first) {
			this->balance += currentScenario[0].second;
			currentScenario[0].first = 1;
			cout << "Congratulations! You deserved prize1 " << currentScenario[0].second << "GEL" << endl;
		}  // prize2 case
		if (totalDeposit >= 500 && totalBet >= 250 && !currentScenario[1].first) {
			this->balance += currentScenario[1].second;
			currentScenario[1].first = 1;
			cout << "Congratulations! You deserved prize2 " << currentScenario[1].second << "GEL" << endl;
		}  // prize3 case
		if (totalDeposit >= 1000 && totalBet >= 500) {
			this->balance += currentScenario[2].second;
			currentScenario[2].first = 1;
			cout << "Congratulations! You deserved prize3 " << currentScenario[2].second << "GEL" << endl;
		}
	}
}

/*
 * Function: Deposit
 * Increases the balance by the specified amount and total deposit.
*/
void Customer::deposit(int amount) {
	if (amount < 0) cout << "Incorrect input" << endl;
	else {
		this->balance += amount;
		totalDeposit += amount;
		checkPrize(totalBet, totalDeposit); // Checks if the user deserves a prize
	}
}

/*
 * Function: bet
 * This function takes an integer argument and places a bet for the customer
 * and if bet type is SLOT increases total bet.
 * If there is a winning case, the customer's
 * balance doubles. otherwise, nothing happens.
*/
void Customer::bet(int amount, string betType) {
	if (amount > balance) cout << "Not enough money" << endl;
	else if (amount < 0) cout << "Incorrect input" << endl;
	else {
		balance -= amount;
		if (win) {
			cout << "You Won " << amount * 2 << "GEL. Congratulations!" << endl;
			this->balance += amount * 2;
		}
		else {
			cout << "You lost. Better luck next time" << endl;
		}
		if(betType == "SLOT") totalBet += amount; // Increase total bet
		win = !win; // Changes winning case
		checkPrize(totalBet, totalDeposit); // Checks if the user deserves a prize
	}
}

/*
 * Function: getBalance
 * This function returns the current balance of a Customer class instance.
*/
int Customer::getBalance() {
	return this->balance;
}