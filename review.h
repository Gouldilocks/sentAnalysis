//
// Created by loggityloglog on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_REVIEW_H
#define S20_PA01_SENTIMENTANALYSIS_REVIEW_H
#include "Stringy.h"
class review{
public:
	/* ***** Constructors ***** */
	review();
	review(review* oldReview);
	review(Stringy* total);
	review(Stringy* total, Stringy* blackList);
	review(Stringy* total, bool sentiment);
	/* ***** Getters / Setters ***** */
	Stringy* getTotal(){return total;}
	void setTotal(Stringy* total){this-> total = total;}
	void setSentiment(bool sentiment){this-> sentiment = sentiment;}
	bool getSentiment(){return sentiment;}
	void setSpaceSeparatedWords(Stringy* words){this-> spaceSeparatedWords = words;}
	Stringy* getSpaceSeparatedWords(){return spaceSeparatedWords;}
	/* ***** Functions ***** */
	// function will clean up the total, ignoring blacklisted words,
	// and then put the clean version of the review into spaceSeparatedWords.
	void cleanUp(Stringy* blackList);
	// function to find the sentiment of the total review.
	bool findSentiment();

private:
	// the whole string as taken from the file.
	Stringy* total = nullptr;
	// the sentiment given for the whole review.
	bool sentiment;
	// all the words, minus the ones I do not want, and minus any punctuation I do not want
	Stringy* spaceSeparatedWords = nullptr;
};
#endif //S20_PA01_SENTIMENTANALYSIS_REVIEW_H
