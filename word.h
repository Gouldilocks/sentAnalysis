//
// Created by loggityloglog on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_WORD_H
#define S20_PA01_SENTIMENTANALYSIS_WORD_H

#include "Stringy.h"
//IMPORTANT the sentiment must be calculated after all the words have been
// this class will serve to keep all the information about each instance of words in the reviews.
class word{
public:
	/* ***** Getters / Setters ***** */
	bool getSent(){return *this->sentiment;}
	void setSent(bool* senty){this->sentiment = senty;}
	Stringy * get_The_Word() const {return theWord;}
	bool getSorted(){return *this-> sorted;}
	void setSorted(bool sort) {*this->sorted = sort;}
	void set_The_Word(Stringy* newWord){this->theWord = newWord;}
	int* getNumPos(){return this->numPos;}
	void setNumPos(int* pos){this->numPos = pos;}
	int* getNumNeg(){return this->numNeg;}
	void setNumNeg(int* neg){this-> numNeg = neg;}
	int getTotalInstances(){return *this->totalInstances;}
	void setTotalInstances(int* ins){this->totalInstances = ins;}
	// returns the c-string of the word in question.
	char* getWordy(){return this-> theWord->getString();}
	/* ***** Functions ***** */
	void increasePos();
	void increaseNeg();
	// calculates the sentiment of the whole word.
	void calc_Sentiment();
	// will add a word to the word count, and change the positive or negative count.
	void add_Word(bool sentiment);

	/* ***** Constructors ***** */
	word();
	word(Stringy* theNewWord, bool senty);
	word(char* theNewWord);
	//word(int pos, int neg){this-> numPos = pos; this->numNeg = neg;}

	~word(){delete theWord; delete numPos; delete numNeg; delete totalInstances; delete sentiment; delete sorted;}
	/* ***** overloaded operators ***** */
	friend bool operator == (const word& W1, const word& W2){
		return (*W1.get_The_Word ()->getString () == *W2.get_The_Word ()->getString ());
	}
private:
	Stringy* theWord;
	int* numPos = nullptr;
	int* numNeg = nullptr;
	int* totalInstances;
	bool* sentiment;
	bool* sorted;

};
#endif //S20_PA01_SENTIMENTANALYSIS_WORD_H
