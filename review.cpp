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

review::review (Stringy *total, Stringy* blackList) {
this-> total = new Stringy(*total);
this->sentiment = findSentiment();
cleanUp(blackList);
}

review::review (Stringy *total, bool sentiment) {
this-> total = total;
this-> sentiment = sentiment;
}

void review::cleanUp (Stringy* blackList) {

}

// will default to false.
bool review::findSentiment () {
	// whole function will not execute if Stringy is empty.
	if (this->total->empty()) return 0;
	bool returnMe = false;
	for(int i = 0; i < this->total->length (); i++){
		if (i == this->total-> length() - 1) return i;
		else{
			// will only return true if ",p or ",|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')
			if (this->total->getString ()[i] == '"'  && (this->total->getString ()[i+1] == ','|| this->total->getString ()[i+1] == '\t' || this->total-> getString ()[i+1] == '|') && this->total->getString ()[i+2] == 'p')	{
				return true;
			}
			else if(this->total->getString ()[i] == '"'  && (this->total->getString ()[i+1] == ','|| this->total->getString ()[i+1] == '\t' || this->total-> getString ()[i+1] == '|') && this->total-> getString ()[i+2] == 'n'){
				return false;
				}
			}
		}
	return returnMe;
	}

review::review (Stringy *total) {
this-> total = total;
this->sentiment = findSentiment ();
this->spaceSeparatedWords = nullptr;
}





