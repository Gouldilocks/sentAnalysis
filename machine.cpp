//
// Created by loggityloglog on 9/3/20.
//
#include "machine.h"
#include <iostream>
void machine::makeBlackList () {
	delete this-> blackList;
	this-> blackList = new Stringy();
	ifstream blackListInput("blackList");
	char temp [10000];
// get a whole line from the input file
	while (blackListInput.getline(temp, 9999, ' ')){
		Stringy tempStringy(temp);
		*this-> blackList += tempStringy;
		*this-> blackList = *this->blackList + " ";
	}
	cout << "Blacklisted Words: " << *this-> blackList << endl;
}
