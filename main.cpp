#include<iostream>

using namespace std;

int main() {
	char restart = 'R';

	while (restart == 'R') {
		double list[9] = {};

		cout << "Enter the numbers (9 total) you want to sort - " << endl << endl;

		for (int i = 0; i < 9; ++i) {
			cout << "Number " << i + 1 << ": ";
			cin >> list[i];
		}

		cout << endl << "Your List: [";
		for (int i = 0; i < 9; ++i) {
			cout << list[i];
			if (i < 8) {
				cout << ", ";
			}
		}
		cout << "]";

		cout << endl << endl;
		cout << "Input 'L' to order from least to greatest." << endl;
		cout << "Input 'G' to order from greatest to least." << endl;
		char order;
		cin >> order;
		order = toupper(order);

		double orderedList[9] = {};
		for (int i = 0; i < 9; ++i) {
			orderedList[i] = list[i];
		}

		if (order == 'L') {
			int j = 0;

			cout << endl;
			cout << "Least to Greatest: ";

			while (j < 8) {
				if (orderedList[j] > orderedList[j + 1]) {
					int i = j;

					while (orderedList[i] > orderedList[i + 1]) {
						orderedList[i] = list[i + 1];
						if (i != 8) {
							orderedList[i + 1] = list[i];
						}
						else {
							orderedList[i] = list[i];
						}
						list[i] = orderedList[i];
						list[i + 1] = orderedList[i + 1];
						++i;
					}
					j = 0;
				}
				else {
					++j;
				}
			}
		}
		else if (order == 'G') {
			int j = 8;

			cout << endl;
			cout << "Greatest to Least: ";

			while (j > 0) {
				if (orderedList[j] > orderedList[j - 1]) {
					int i = j;

					while (orderedList[i] > orderedList[i - 1]) {
						orderedList[i] = list[i - 1];
						if (i != 0) {
							orderedList[i - 1] = list[i];
						}
						else {
							orderedList[i] = list[i];
						}
						list[i] = orderedList[i];
						list[i - 1] = orderedList[i - 1];
						++i;
					}
					j = 8;
				}
				else {
					--j;
				}
			}
		}
		else {
			cout << endl << "Error: Only allowed input of 'L' or 'G'." << endl << endl;
		}

		if (order == 'L' || order == 'G') {
			cout << "[";
			for (int i = 0; i < 9; ++i) {
				cout << orderedList[i];
				if (i < 8) {
					cout << ", ";
				}
			}
			cout << "]" << endl;
		}

		if (order == 'L' || order == 'G') {
			cout << endl;
			cout << "Input 'R' to sort another list." << endl;
			cout << "Input 'Q' to quit." << endl;
			cin >> restart;
			restart = toupper(restart);
			cout << endl;
		}

		if (restart != 'R') {
			cout << "Goodbye." << endl;
		}
	}

	return 0;
}