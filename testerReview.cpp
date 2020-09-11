//
// Created by Christian Gould on 9/4/20.
//
#include "testerReview.h"

testerReview::~testerReview () {
	delete expectedOutput;
	delete posWords;
	delete negWords;
}

testerReview::testerReview () : review () {
	this->expectedOutput = nullptr;
}

testerReview::testerReview (Stringy total, int row, bool realSentiment, int pos, int neg) : review (total, row) {
	this->negWords = new int (1);
	this->posWords = new int (1);
	this->expectedOutput = new bool (false);
	this->sentiment = realSentiment;
	this->posWords = new int (pos);
	this->negWords = new int (neg);
}

testerReview::testerReview (bool expected) : review () {
	this->expectedOutput = &expected;
}

testerReview::testerReview (const testerReview &tes) : review (tes) {
	this->expectedOutput = new bool (*tes.expectedOutput);
	this->posWords = new int (*tes.posWords);
	this->negWords = new int (*tes.negWords);
}

bool testerReview::getExpectedOutput () {
	return *expectedOutput;
}

void testerReview::setExpectedOutput (bool expect) {
	expectedOutput = new bool (expect);
}

int *testerReview::getPosWords () {
	return this->posWords;
}

int *testerReview::getNegWords () {
	return this->negWords;
}

void testerReview::setPosWords (int *pos) {
	this->posWords = pos;
}

void testerReview::setNegWords (int *neg) {
	this->negWords = neg;
}

void testerReview::addToPosWords (int addMe) {
	*this->posWords = *posWords + addMe;
}

void testerReview::addToNegWords (int addMe) {
	*this->negWords = *negWords + addMe;
}
