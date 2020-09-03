//
// Created by loggityloglog on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_WORD_H
#define S20_PA01_SENTIMENTANALYSIS_WORD_H

#include "Stringy.h"

// this class will serve to keep all the information about each instance of words in the reviews.
class word{
public:
	/* ***** Getters / Setters ***** */
	int getNumPos(){return this->numPos;}
	void setNumPos(int pos){this->numPos = pos;}
	int getNumNeg(){return this->numNeg;}
	void setNumNeg(int neg){this-> numNeg = neg;}
	int getTotalInstances(){return this->totalInstances;}
	void setTotalInstances(int ins){this->totalInstances = ins;}
	// returns the c-string of the word in question.
	char* getWordy(){return this-> theWord->getString();}
	/* ***** Functions ***** */
	void increasePos() {numPos++;}
	void increaseNeg() {numNeg++;}
	// calculates the sentiment of the whole word.
	void calc_Sentiment();
	// will add a word to the word count, and change the positive or negative count.
	void add_Word(bool sentiment);

	/* ***** Constructors ***** */
	word();
	word(Stringy* theNewWord);
	word(char* theNewWord);
	word(int pos, int neg){this-> numPos = pos; this->numNeg = neg;}

private:
	Stringy* theWord;
	int numPos = 0;
	int numNeg = 0;
	int totalInstances = 0;
	bool sentiment;

};
#endif //S20_PA01_SENTIMENTANALYSIS_WORD_H
