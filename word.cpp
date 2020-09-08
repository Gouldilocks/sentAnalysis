//
// Created by loggityloglog on 9/3/20.
//
#include "word.h"

word::word (char *theNewWord) {
	this-> theWord = new Stringy(theNewWord);
	this->numPos = new int(0);
	this-> numNeg = new int(0);
	this-> totalInstances = new int(0);
	this-> sentiment = new bool(false);
	this-> sorted = new bool(false);
}

word::word (Stringy *theNewWord, bool senty) {
	this->numPos = new int(0);
	this-> numNeg = new int(0);
	this-> totalInstances = new int(0);
	this-> sentiment = new bool(senty);
	this-> sorted = new bool(false);
	this-> theWord = new Stringy(theNewWord);
	add_Word(senty);
}

word::word () {
this-> theWord = nullptr;
	this->numPos = new int(0);
	this-> numNeg = new int(0);
	this-> totalInstances = new int(0);
	this-> sentiment = new bool(false);
	this-> sorted = new bool (false);
}
word :: word(const word& w1){
	this-> numPos = new int(*w1.numPos);
	this->numNeg = new int(*w1.numNeg);
	this-> totalInstances = new int(*w1.totalInstances);
	this->sentiment = new bool (*w1.sentiment);
	this-> sorted = new bool(*w1.sorted);
	this-> theWord = new Stringy(*w1.theWord);
}
void word::calc_Sentiment () {
	//*sentiment = *numPos >= *numNeg;
	if(*this-> totalInstances > 3){
		if (sentiment == nullptr) {
			sentiment = new bool (false);
		}
		*sentiment = *numPos >= *numNeg;
	} else this->sentiment = nullptr;
}

void word::add_Word (bool senty) {
if (senty){
	increasePos ();
} else {
	increaseNeg ();
		}
}

void word::increasePos () {
*this-> numPos = *numPos + 1;
*this->totalInstances = *totalInstances + 1;
}

void word::increaseNeg () {
*this-> numNeg = *numNeg +1;
*this->totalInstances = *totalInstances + 1;
}

word &word::operator= (const word &word1) {
	if(this == &word1) return *this;
	delete this-> theWord;
	delete this-> numPos;
	delete this-> numNeg;
	delete this-> totalInstances;
	delete this-> sentiment;
	delete this-> sorted;
	this-> theWord = new Stringy(*word1.theWord);
	this-> numPos = new int(*word1.numPos);
	this-> numNeg = new int(*word1.numNeg);
	this-> totalInstances = new int(*word1.totalInstances);
	this-> sentiment = new bool (*word1.sentiment);
	this-> sorted = new bool (*word1.sorted);
	return *this;
}


