//
// Created by loggityloglog on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_REVIEW_H
#define S20_PA01_SENTIMENTANALYSIS_REVIEW_H
#include "Stringy.h"
/* The purpose of the class review is to organize all the aspects of each review.
 * This class will store the review itself, a version of the review free from
 * unwanted words/ characters, and also store the sentiment of the review if
 * given it.
 * The review objects will be managed by a machine object.*/
class review{
public:
	~review(){delete total; delete spaceSeparatedWords;}
	/* ***** Constructors ***** */
	review();
	review(review* oldReview);
	/* int is_It_Testing serves for the class to function as knowing whether or not the data is training
	 * data or testing data, so that it does not run findSentiment.
	 * put 1 if it is training data, any other number for testing data*/
	review(Stringy* total, int row);
	review(Stringy* total, bool sentiment, bool useBool);
	/* ***** Getters / Setters ***** */
	Stringy* getTotal(){return total;}
	void setTotal(Stringy* total){this-> total = total;}
	void setSentiment(bool sentiment){this-> sentiment = sentiment;}
	bool getSentiment(){return sentiment;}
	void setSpaceSeparatedWords(Stringy* words){this-> spaceSeparatedWords = words;}
	Stringy* getSpaceSeparatedWords(){return spaceSeparatedWords;}
	int getRow(){return this->row;}
	void setRow(int newRow){this->row = newRow;}
	/* ***** Functions ***** */
	// function will clean up the total, ignoring blacklisted words,
	// and then put the clean version of the review into spaceSeparatedWords.
	void cleanUp(ifstream& noNoWords);
	// function to find the sentiment of the total review when it is given.
	bool findSentiment();

protected:
	// the whole string as taken from the file.
	Stringy* total = nullptr;
	// the sentiment given for the whole review.
	bool sentiment;
	// all the words, minus the ones I do not want, and minus any punctuation I do not want
	Stringy* spaceSeparatedWords = nullptr;
	// this integer will keep track of which row this certain review is on.
	int row;
};
#endif //S20_PA01_SENTIMENTANALYSIS_REVIEW_H
