/* Corey Peterson
   CS_210
   Project_Three
   02/25/2024
*/


#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


// Class with public and private members
class ItemFrequency {

private:
	map<string, int> frequencyMap;

public:
	// Read the contents of the .txt file
	void readFromFile(const string& CS210_Input_File) {
		ifstream inputFile("CS210_Input_File.txt");
		if (!inputFile.is_open()) {
			cout << "Error opening file" << "CS210_Input_File.txt" << endl;
			return;

		}

		string item;
		int frequency;
		while (inputFile >> item) {
			frequencyMap[item] ++;

		}

		inputFile.close();

	}

	// Lookup function for specific items and retrieval of their frequencies
	int getFrequency(const string& item) {
		if (frequencyMap.count(item)) {
			return frequencyMap[item];
		}
		else {
			return 0;
		}
	}

	// Create the frequency list function
	void printFrequencyList() {
		for (const auto& pair : frequencyMap) {
			cout << pair.first << " " << pair.second << endl;
		}
	}

	// Create the histogram function
	void printHistogram() {
		for (const auto& pair : frequencyMap) {
			cout << pair.first << " ";
			for (int i = 0; i < pair.second; ++i) {
				cout << "$";
			}
			cout << endl;
		}
	}

	// Create backup .dat file function
	void saveToFile(const string& filename) {
		ofstream outputFile(filename);

		if (!outputFile.is_open()) {
			cout << "Error opening file " << filename << " for writing" << endl;
			return;
		}

		for (const auto& pair : frequencyMap) {
			outputFile << pair.first << " " << pair.second << endl;
		}

		outputFile.close();
	}
};

// Main program calling the above functions
int main() {
	ItemFrequency itemFreq;
	itemFreq.readFromFile("CS210_Input_File.txt");

	// Create the backup .dat file before any user interaction
	itemFreq.saveToFile("frequency.dat");


	// Display the interactive menu that the user can choose from
	int choice;
	do {
		cout << "\nMenu:" << endl;
		cout << "\nPlease enter your selection" << endl;
		cout << "\n1. Find quantity of item sold (case sensitive)" << endl;
		cout << "2. Print list of items sold" << endl;
		cout << "3. Print frequency information in the form of a histogram" << endl;
		cout << "4. Exit Program" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			string item;
			cout << "\nEnter item: ";
			cin >> item;
			cout << "Quantity sold: " << itemFreq.getFrequency(item) << endl;
			break;
		}
		case 2:
			itemFreq.printFrequencyList();
			break;
		case 3:
			itemFreq.printHistogram();
			break;
		case 4:
			cout << "Exiting Program" << endl;
			break;
		default:
			cout << "Invalid choice. Please enter choice again" << endl;
		}

	} while (choice != 4);

	return 0;

}
