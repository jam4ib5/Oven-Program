#include <iostream>
#include "Oven.h"

using namespace std;

void DisplayHeader(Oven& oven) {

	cout << "---------------------------------------------" << endl;
	if (oven.isOn()) {
		
		cout << "OVEN IS ON...  CURRENTLY AT " << oven.GetCurrentTemperature()
			<< " AND SET TO " << oven.GetSetTemperature() << endl;
	}
	else {
		cout << "OVEN IS OFF...  CURRENTLY AT " << oven.GetCurrentTemperature();
	}
}

int DisplayOptionsAndGetInput() {
	int userInput;
	cout << "\n---------------------------------------------" << endl;
	cout << "\n1) Turn oven ON (and change set temperature)" << endl;
	cout << "2) Turn oven OFF" << endl;
	cout << "3) Change set temperature" << endl;
	cout << "4) Simulate the passage of time"<<endl;
	cout << "5) Exit PROGRAM" << endl;
	cout << "?? ";
	cin >> userInput;
	while ((userInput < 1) || (userInput > 5)) {
		cout << "?? " << endl;
		cin >> userInput;
	};

	return userInput;
}



int main() {
	Oven oven;
	int userInput;

	do {
		DisplayHeader(oven);
		userInput = DisplayOptionsAndGetInput();

		if (userInput == 1) {
			cout << "\nOVEN TURNED ON " << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Set Oven to what temperature ["
				<< oven.GetMinimumTemperature() << "-"
				<< oven.GetMaximumTemperature() << "] ";
			int T;
			cin >> T;
			oven.TurnOn(T);

		}

		else if (userInput == 2) {
			cout << "OVEN TURNED OFF" << endl;
			oven.TurnOff();
		}

		else if (userInput == 3) {
			cout << "\nSet Oven to what temperature ["
				<< oven.GetMinimumTemperature() << "-"
				<< oven.GetMaximumTemperature()<<"] ";
			int T;
			cin >> T;
			oven.TurnOn(T);
		}
		else if (userInput == 4) {
			cout << "Simulate How many minutes of time: " << endl;
			int mins;
			cin >> mins;
			oven.SimulatePassingOfTime(mins);
		}
		cout << "\n" << endl;

	} while (userInput != 5);

	
}