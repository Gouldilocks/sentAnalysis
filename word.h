//
// Created by Christian Gould on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_WORD_H
#define S20_PA01_SENTIMENTANALYSIS_WORD_H

#include "Stringy.h"
//IMPORTANT the sentiment must be calculated after all the words have been
// this class will serve to keep all the information about each instance of words in the reviews.
class word{
public:
	/* ***** Destructor ***** */
	~word();


	/* ***** Constructors ***** */
	// Default Constructor.
	word();
	// Constructor: takes a Stringy as parameter. Word will be set to this. Takes bool of sentiment.
	word(Stringy* theNewWord, bool senty);
	// Constructor: copies from a pointer to a word. (deep copy)
	word(char* theNewWord);
	// Copy constructor.
	word(const word& w1);
	// Stringy constructor
	word(Stringy theNewWord, bool senty);

	/* ***** Functions ***** */
	// will increase the numPos by 1 and totalInstances by 1.
	void increasePos() const;
	// will increase the numNeg by 1 and totalInstances by 1.
	void increaseNeg() const;
	// calculates the sentiment of the whole word.
	void calc_Sentiment() const;
	// will add a word to the word count, and change the positive or negative count.
	void add_Word(bool sentiment)const;


	/* ***** Getters / Setters ***** */
	// returns a bool of the word's overall sentiment.
	bool getSent() const;
	// returns a pointer to the word's overall sentiment.
	bool* getSentPtr() const;
	// set the sentiment of the word. Takes bool pointer as parameter.
	void setSent(bool* senty);
	// returns a pointer to a Stringy containing the word.
	Stringy * get_The_Word() const;
	// returns a bool of the sorted bool.
	bool getSorted();
	// sets the sorted element. Takes a bool as parameter.
	void setSorted(bool sort);
	// sets the word. Takes a Stringy pointer as parameter.
	void set_The_Word(Stringy* newWord);
	// returns a pointer to the number of positive instances of this word.
	int* getNumPos();
	// sets the number of positive instances. Takes int pointer as parameter.
	void setNumPos(int* pos);
	// returns a pointer to the number of negative instances.
	int* getNumNeg();
	// sets the number of negative instances. Takes int pointer as parameter.
	void setNumNeg(int* neg);
	// returns the number of total instances of this word.
	int getTotalInstances();
	// sets the number of total instances of this word. Takes int pointer as parameter.
	void setTotalInstances(int* ins);
	// returns the c-string of this word.
	char* getWordy();


	/* ***** overloaded operators ***** */
	// operator compares the Stringys of each word ONLY.
	friend bool operator == (const word& W1, const word& W2);
	// operator sets the elements of this word to the same as w2. (Dynamic allocation)
	word& operator = (const word& w2);
	// Prints out each of the elements out to the console.
	friend ostream& operator << (ostream& OS, const word& w1);
	// less than sign
	friend bool operator< (const word& lhs, const word& rhs);
private:
	Stringy* theWord;
	int* numPos;
	int* numNeg;
	int* totalInstances;
	bool* sentiment;
	bool* sorted;

};
#endif //S20_PA01_SENTIMENTANALYSIS_WORD_H
