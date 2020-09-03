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
	review(Stringy* total, bool sentiment);
	/* ***** Getters / Setters ***** */
	Stringy* getTotal(){return total;}
	void setTotal(Stringy* total){this-> total = total;}
	void setSentiment(bool sentiment){this-> sentiment = sentiment;}
	bool getSentiment(){return sentiment;}
	void setSpaceSeparatedWords(Stringy* words){this-> spaceSeparatedWords = words;}
	Stringy* getSpaceSeparatedWords(){return spaceSeparatedWords;}
	Stringy* getBlackList(){return blackList;}
	void setBlackList(Stringy* blackList){this-> blackList = blackList;}
	/* ***** Functions ***** */
	// function will clean up the total, ignoring blacklisted words,
	// and then put the clean version of the review into spaceSeparatedWords.
	void cleanUp();
	bool findSentiment();
	void makeBlackList();

private:
	// the whole string as taken from the file.
	Stringy* total;
	// the sentiment given for the whole review.
	bool sentiment;
	// all the words, minus the ones I do not want, and minus any punctuation I do not want
	Stringy* spaceSeparatedWords;
	// the space-separated list of words which are banned from being analyzed.
	Stringy* blackList;
};
#endif //S20_PA01_SENTIMENTANALYSIS_REVIEW_H
