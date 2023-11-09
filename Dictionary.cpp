#include <iostream>
#include <Windows.h>
#include <map>
#include <fstream>
using namespace std;

typedef pair<string, string> word;

void Input(multimap<string, string>& dict) {
	string str1, str2;
	cout << "Enter word on English: ";
	cin >> str1;
	cout << "Enter word on Russian: ";
	cin >> str2;
	dict.insert(word(str1, str2));
}

void Print(multimap<string, string>& dict) {
	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		cout << it->first << " - " << it->second << endl;
	}
}


void SaveToFile(multimap<string, string>& dict) {
	ofstream wr("Dictionary.txt", ios::out | ios::app);

	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		wr << it->first << " - " << it->second << endl;
	}

	wr.close();
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	multimap<string, string> dictionary;

	int userChoice;

	do
	{
		cout << "Enter:\n1 - Input\n2 - Print\n3 - Find\n4 - Save to file\n--> ";
		cin >> userChoice;
		switch (userChoice)
		{
		case 0:
			exit;
			break;
		case 1:
			Input(dictionary);
			break;
		case 2:
			Print(dictionary);
			break;
		case 4:
			SaveToFile(dictionary);
			break;
		case 3:
			string str;
			cout << "Enter word to find: ";
			cin >> str;
			int countOfWords = 0;
			auto result = dictionary.find(str);
			if (result == dictionary.end())
			{
				cout << "Word is not found." << endl;
				break;
			}
			for (; result != dictionary.end(); result++)
			{
				if (result->first == str) {
					cout << result->second << ' ';
					countOfWords++;
				}
			}
			cout << endl << "Колиство вхождений слова: " << countOfWords << endl;
			break;

		}

	} while (userChoice != 0);

	return 0;

}