//
// Created by Christian Gould on 9/3/20.
//
#include "review.h"
#include <iostream>

review::~review () {
	delete spaceSeparatedWords;
	delete total;
}

review::review () {
	total = nullptr;
	sentiment = false;
	spaceSeparatedWords = nullptr;
}

// copy constructor
review::review (review *oldReview) {
	this->total = new Stringy (*oldReview->getTotal ());
	this->sentiment = oldReview->getSentiment ();
	this->spaceSeparatedWords = new Stringy (*oldReview->getSpaceSeparatedWords ());
	this->row = oldReview->getRow ();
}

review::review (const review &rev) {
	this->total = new Stringy (*rev.total);
	this->spaceSeparatedWords = new Stringy (*rev.spaceSeparatedWords);
	this->sentiment = rev.sentiment;
	this->row = rev.row;
}

review::review (Stringy total, int row) {
	this->row = row;
	this->total = new Stringy (total);
	//cout << "made one" << endl;
}

review::review (Stringy *total, bool sentiment, bool useBool) {
	this->total = total;
	this->sentiment = sentiment;
	this->row = 1;
}

Stringy *review::getTotal () {
	return total;
}

void review::setTotal (Stringy *total) {
	this->total = total;
}

void review::setSentiment (bool sentiment) {
	this->sentiment = sentiment;
}

bool review::getSentiment () {
	return this->sentiment;
}

void review::setSpaceSeparatedWords (Stringy *words) {
	delete this->spaceSeparatedWords;
	this->spaceSeparatedWords = words;
}

Stringy *review::getSpaceSeparatedWords () {
	return this->spaceSeparatedWords;
}

int review::getRow () {
	return this->row;
}

void review::setRow (int newRow) {
	this->row = newRow;
}

void review::cleanUp (ifstream &noNoWords) {
	char temporary[200];
	int counter = 0;
	counter++;
	while (noNoWords.getline (temporary, 150, ' ')) {
		Stringy tempStringy (temporary);
		this->total->findAndDelete (tempStringy.getString ());
	}
	this->spaceSeparatedWords = new Stringy (*this->total);
}

bool review::findSentiment () {
	// whole function will not execute if Stringy is empty.
	if (this->total->empty ()) return false;
	bool returnMe = false;
	for (int i = 0; i < this->total->length (); i++) {
		if (i == this->total->length () - 1) {return i;}
		else {
			// will only return true if ",p or ",|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')
			if (this->total->getString ()[ i ] == '"' &&
				(this->total->getString ()[ i + 1 ] == ',' || this->total->getString ()[ i + 1 ] == '\t' ||
				 this->total->getString ()[ i + 1 ] == '|') && this->total->getString ()[ i + 2 ] == 'p') {
				return true;
			} else if (this->total->getString ()[ i ] == '"' &&
					   (this->total->getString ()[ i + 1 ] == ',' || this->total->getString ()[ i + 1 ] == '\t' ||
						this->total->getString ()[ i + 1 ] == '|') && this->total->getString ()[ i + 2 ] == 'n') {
				return false;
			}
		}
	}
	return returnMe;
}

review &review::operator= (const review &rev1) {
	if (rev1 == *this) return *this;
	this->total = new Stringy (rev1.total);
	this->sentiment = rev1.sentiment;
	this->spaceSeparatedWords = new Stringy (rev1.spaceSeparatedWords);
	this->row = rev1.row;
}

bool operator== (const review &lhs, const review &rhs) {
	return (
			*lhs.total == *rhs.total &&
			lhs.sentiment == rhs.sentiment &&
			*lhs.spaceSeparatedWords == *rhs.spaceSeparatedWords &&
			lhs.row == rhs.row
	);
}


































