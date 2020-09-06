#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stringy.h"
#include "review.h"
#include "machine.h"
using namespace std;
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int main() {
// todo: make all words capital, as it treats them as different
	ifstream testing_Data("testing_Data.csv");
	ifstream training_Data("training_Data.csv");
	auto* newMachine = new machine();
	newMachine->jumpStart (testing_Data,training_Data);
	cout << "Done" << endl;
    return 0;
}

