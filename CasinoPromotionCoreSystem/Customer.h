/*
 * #pragma once ensures that this header file is included only once during compilation.
 * This prevents duplicate definitions and reduces compilation time
 */
#pragma once

/*
 * #include <bits/stdc++.h> includes most of the standard C++ libraries
 * Note: It's not part of the standard C++ library and may not be portable across all compilers.
 */
#include <bits/stdc++.h>
using namespace std;

/*
 * It simplifies code by allowing you to use 'vvpbi' and 'pbi' instead of the full type definitions.
 */
typedef vector< vector< pair<bool, int> > > vvpbi;
typedef pair<bool, int> pbi;

class Customer
{
private:

	int balance; // The current balance of the customer.

	int totalBet; // The total amount of money bet by the customer.

	int totalDeposit; // The total amount of money deposited by the customer.

	static bool win; // A static variable indicating if the customer has won in a given context.

	/*
	 * A vector of pairs used to represent various scenarios.
	 * This variable stores a collection of scenarios, where each scenario is a pair.
	 * Each pair consists of:
	 * - A boolean indicating whether this prize has been used (true if used, false otherwise).
	 * - An integer representing the prize amount.
	 * The outer vector represents different scenarios,
	 * This structure allows for efficient access and modification of scenario data.
	*/
	static vvpbi scenarios;

	vector<pbi> currentScenario; // This vector stores the user's current scenario.

	void checkPrize(int totalBet, int totalDeposit); // See description in cpp file.

public:

	/*
	 * Constructor for the customer class.
	 * Initializes the customer with default values
	 * for balance, total bets, and total deposits.
	 */
	Customer();

	/*
	 * Destructor for the customer class.
	 * Cleans up any resources used by the Customer instance (if necessary).
	 */
	~Customer();

	/*
	 * The static function addScenarios adds a
	 * scenario to the static variable "scenarios".
	 */
	static void addScenario(int prize1, int prize2, int prize3);

	/*
s	 * Increases the customer's balance by the specified amount.
	 * amount variable - The amount to be deposited into the customer's balance.
	 */
	void deposit(int amount);

	/*
	 * Places a bet with the specified amount and type.
	 * Decreases the customer's balance by the bet amount and updates the total bet.
	 * amount - The amount of the bet.
	 * betType - A string indicating the type of bet placed.
	 */
	void bet(int amount, string betType);

	/*
	 * return The current balance of the customer.
	 */
	int getBalance();

};
