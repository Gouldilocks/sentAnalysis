#include "testerReview.h"

//
// Created by loggityloglog on 9/4/20.
//
testerReview ::testerReview (Stringy total, int row, bool realSentiment, int pos, int neg) :  review(total, row){
this-> negWords = new int(1);
this-> posWords = new int(1);
this-> expectedOutput = new bool(false);
this-> sentiment = realSentiment;
this-> posWords = new int(pos);
this-> negWords = new int(neg);
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

testerReview::testerReview (const testerReview &tes) : review(tes) {
this-> expectedOutput = new bool(*tes.expectedOutput);
this-> posWords = new int(*tes.posWords);
this->negWords = new int(*tes.negWords);
}

testerReview::~testerReview () {
	delete expectedOutput; delete posWords; delete negWords;
}

testerReview::testerReview (bool expected) : review() {
	this-> expectedOutput = &expected;
}

bool testerReview::getExpectedOutput () {
	return expectedOutput;
}

void testerReview::setExpectedOutput (bool expect) {
	delete this->expectedOutput; expectedOutput = new bool(expect);
}

int *testerReview::getPosWords () {
	return this-> posWords;
}

int *testerReview::getNegWords () {
	return this-> negWords;
}

void testerReview::setPosWords (int *pos) {
	this-> posWords = pos;
}

void testerReview::setNegWords (int *neg) {
	this->negWords = neg;
}
