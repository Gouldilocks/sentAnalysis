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
	this-> theWord = new Stringy(*theNewWord);
	this->add_Word (senty);
}

word::word () {
this-> theWord = nullptr;
	this->numPos = new int(0);
	this-> numNeg = new int(0);
}

void word::calc_Sentiment () {
	sentiment = numPos >= numNeg;
}

void word::add_Word (bool sentiment) {
if (sentiment){
	increasePos ();
} else increaseNeg ();
}

