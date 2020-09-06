//
// Created by loggityloglog on 9/3/20.
//
#include "word.h"

word::word (char *theNewWord) {
	this-> theWord = new Stringy(theNewWord);
	this->numPos = new int(0);
	this-> numNeg = new int(0);
}

word::word (Stringy *theNewWord, bool senty) {
	this->numPos = new int(0);
	this-> numNeg = new int(0);
	this-> totalInstances = new int(0);
	this-> sentiment = new bool(false);
	this-> sorted = new bool(false);
	this-> theWord = new Stringy(*theNewWord);
	add_Word(senty);
}

word::word () {
this-> theWord = nullptr;
	this->numPos = new int(0);
	this-> numNeg = new int(0);
}

void word::calc_Sentiment () {
	//*sentiment = *numPos >= *numNeg;
	if(*this-> totalInstances > 3){
		if (sentiment == nullptr) {
			sentiment = new bool (false);
		}
		*sentiment = *numPos >= *numNeg;
	} else sentiment = nullptr;
}

void word::add_Word (bool senty) {
if (senty){
	increasePos ();
} else {
	increaseNeg ();
		}
		this-> calc_Sentiment ();
}

void word::increasePos () {
*this-> numPos = *numPos + 1;
*this->totalInstances = *totalInstances + 1;
}

void word::increaseNeg () {
*this-> numNeg = *numNeg +1;
*this->totalInstances = *totalInstances + 1;
}

