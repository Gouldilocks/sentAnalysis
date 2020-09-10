//
// Created by loggityloglog on 9/4/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
#define S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
#include "review.h"
#include "Stringy.h"
class testerReview : public review {
public:
	/* ***** Destructor ***** */
	~testerReview();


	/* ***** Constructors ***** */
	// default constructor
	testerReview();
	// Constructor: give Stringy of whole review, and row number
	testerReview(Stringy total, int row, bool realSentiment);
	// Constructor: give bool of expected output, and calls review default constructor.
	testerReview(bool expected);
	// Copy constructor.
	testerReview (const testerReview& tes);


	/* ***** Getters / Setters ***** */
	// returns expected output in form of a bool
	bool getExpectedOutput();
	// sets the expected output. takes bool as parameter.
	void setExpectedOutput(bool expect);
	// returns a pointer to the number of positive words in the review.
	int* getPosWords();
	// returns a pointer to the number of negative words int he review.
	int* getNegWords();
	// sets the number of positive words. Takes int pointer as parameter.
	void setPosWords(int* pos);
	// sets the number of negative words. Takes int pointer as parameter.
	void setNegWords(int* neg);
	// adds addMe to the number of positive words in the review.
	void addToPosWords(int addMe);
	// adds addMe to the number of negative words in the review.
	void addToNegWords(int addMe);
private:
	// The output which is calculated by my classifier.
	bool* expectedOutput;
	// The number of positive words in the review.
	int* posWords;
	// the number of negative words in the review.
	int* negWords;
};
#endif //S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
