#include "testerReview.h"

//
// Created by loggityloglog on 9/4/20.
//
testerReview ::testerReview (Stringy* total, int row) :  review(total, row){
this-> negWords = new int(1);
this-> posWords = new int(1);
this-> expectedOutput = new bool(false);
}
testerReview :: testerReview() : review(){
	this-> expectedOutput = nullptr;
}

void testerReview::addToPosWords (int addMe) {
*this->posWords = *posWords + addMe;
}

void testerReview::addToNegWords (int addMe) {
*this->negWords = *negWords + addMe;
}
