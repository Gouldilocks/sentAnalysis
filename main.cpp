#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "machine.h"
using namespace std;
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int main(int argc, char** argv) {
	if(argv == nullptr) {
		Catch::Session ().run ();
		return 0;
	}
	else {
		//Catch:: Session().run();
	ifstream training_Data(argv[0]);
	ofstream outPut(argv[1]);
	auto* newMachine = new machine();
	newMachine->jumpStart (training_Data,outPut);
	cout << "Done" << endl;}
    return 0;
}
