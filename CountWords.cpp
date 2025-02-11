// CountWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

void PrintDictionary(map<string, int>* dict);
void StartUp();

int main()
{
    StartUp();

    string retry;
    cout << "Do you want to retry?(y/n)" << endl;
    cin >> retry;

    if (std::tolower(retry[0]) == 'y') {
        StartUp();
    }

    return 0;
}

void StartUp() {
    cout << "Enter the path of a file: ";
    char path[100];
    cin >> path;
    ifstream file(path);

    if (!file) {
        cerr << "Error: couldn't open the file!" << endl;
        StartUp();
    }

    map<string, int> amountWords;
    string word;

    char ch;
    while (file.get(ch)) {
        if (isspace(ch)) {
            if (!word.empty()) {
                amountWords[word]++;
                word.clear();
            }
        }
        else if (isdigit(ch))
        {
            word.clear();
        }
        else {
            word += ch;
        }
    }

    if (!word.empty()) {
        amountWords[word]++;
    }

    file.close();
    PrintDictionary(&amountWords);
}

void PrintDictionary(map<string, int>* dict) {
    for (const auto& pair : *dict) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
