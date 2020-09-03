//
// Created by loggityloglog on 9/3/20.
//
#include "word.h"

word::word (char *theNewWord) {
	this-> theWord = new Stringy(theNewWord);
}

word::word (Stringy *theNewWord, bool sentiment) {
	this-> theWord = new Stringy(theNewWord->getString());
	if(sentiment){
		increasePos ();
	} else {
		increaseNeg ();
	}
}

word::word () {
this-> theWord = nullptr;
}

void word::calc_Sentiment () {
	sentiment = numPos > numNeg && totalInstances > 3;
}

void word::add_Word (bool sentiment) {
if (sentiment){
	increasePos ();
} else increaseNeg ();
calc_Sentiment();
}
