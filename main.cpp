#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "machine.h"
using namespace std;
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int main(int argc, char** argv) {
	if(argc == 1) {
		Catch::Session ().run ();
		return 0;
	}
	else {
		//Catch:: Session().run();
		//ifstream training_Data("IMDB Dataset.csv");
		//ofstream outPut("outPut01.txt");
		cout << "args:" << endl;
		cout << argv[1] << endl;
		cout << argv[2] << endl;
	ifstream training_Data;
	training_Data.open(argv[1]);
	ofstream outPut;
	outPut.open(argv[2]);
	auto* newMachine = new machine();
	newMachine->jumpStart (training_Data,outPut);
	training_Data.close();
	outPut.close();
	cout << "Done" << endl;}
    return 0;
}
