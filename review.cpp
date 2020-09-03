//
// Created by loggityloglog on 9/3/20.
//
#include "review.h"
#include <iostream>
#include <sstream>
/*
 * Elements:
 * -----------------
 * Stringy* total
 * bool sentiment
 * Stringy* spaceSeparatedWords
 * */
review::review () {
total = nullptr;
sentiment = false;
spaceSeparatedWords = nullptr;
}

review::review (review *oldReview) {
this-> total = new Stringy(*oldReview->getTotal ());
this->sentiment = oldReview->getSentiment();
this-> spaceSeparatedWords = new Stringy(*oldReview->getSpaceSeparatedWords ());
}

review::review (Stringy *total) {
this-> total = new Stringy(*total);
this->sentiment = findSentiment();
cleanUp();
}

review::review (Stringy *total, bool sentiment) {

}

void review::cleanUp () {

}

bool review::findSentiment () {
	return false;
}

void review::makeBlackList () {
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

