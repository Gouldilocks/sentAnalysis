//
// Created by Christian Gould on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_REVIEW_H
#define S20_PA01_SENTIMENTANALYSIS_REVIEW_H
#include "Stringy.h"
/* The purpose of the class review is to organize all the aspects of each review.
 * This class will store the review itself, a version of the review free from
 * unwanted words/ characters, and also store the sentiment of the review if
 * given it.
 * The review objects will be managed by a machine object.
 * ^^^^^^^^^^^^^
 * This was the original plan, until I found that parsing the input into reviews
 * did not offer enough function for the amount of time spent on it.
 * The main advantage was more abstraction, however it was not worth the
 * sacrifice of efficiency. The subclass testerReview was used, however.
 * */
class review{
public:
	/* ***** Destructor ***** */
	~review();


	/* ***** Constructors ***** */
	// Default Constructor
	review();
	// Copy Constructor of a pointer
	review(review* oldReview);
	// Copy Constructor
	review(const review& rev);
	// Constructor: give the whole review, and which row it is on.
	review(Stringy total, int row);
	/* Constructor: give the whole review, the sentiment, and give a true to useBool.
	usebool is necessary to make sure that there is no confusion that the above
	constructor is used when row == 1 or 0.*/
	review(Stringy* total, bool sentiment, bool useBool);


	/* ***** Getters / Setters ***** */
	// returns the pointer to the total review
	virtual Stringy* getTotal();
	// sets the total. Takes pointer to a Stringy which contains whole review.
	virtual void setTotal(Stringy* total);
	// sets the sentiment of the review. Takes bool as parameter.
	virtual void setSentiment(bool sentiment);
	// returns a bool of the sentiment of the review.
	virtual bool getSentiment();
	// sets the spaceSeparatedWords variable. Takes stringy pointer as parameter.
	virtual void setSpaceSeparatedWords(Stringy* words);
	// returns a Stringy pointer to this review's spaceSeparatedWords
	virtual Stringy* getSpaceSeparatedWords();
	// returns the rowNumber of this review.
	virtual int getRow();
	// sets the rowNumber of this review. Takes the rownumber as an int as parameter.
	virtual void setRow(int newRow);


	/* ***** Functions ***** */
	/* function will clean up the total, ignoring blacklisted words,
	and then put the clean version of the review into spaceSeparatedWords. */
	virtual void cleanUp(ifstream& noNoWords);
	// function to find the sentiment of the total review when it is given.
	virtual bool findSentiment();


	/* ***** Operators ***** */
	review& operator= (const review& rev1);
	friend bool operator == (const review& lhs, const review& rhs);
protected:
	// the whole string as taken from the file.
	Stringy* total = nullptr;
	// the sentiment given for the whole review.
	bool sentiment;
	// all the words, minus the ones I do not want, and minus any punctuation I do not want
	Stringy* spaceSeparatedWords = nullptr;
	// this integer will keep track of which row this certain review is on.
	int row = 0;
};
#endif //S20_PA01_SENTIMENTANALYSIS_REVIEW_H
