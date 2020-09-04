//
// Created by loggityloglog on 9/4/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
#define S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
#include "review.h"
#include "Stringy.h"
class testerReview :public review {
public:
	/* ***** Constructors ***** */
	testerReview();
	testerReview(Stringy* total, int row);
	testerReview(bool expected) : review() {this-> expectedOutput = &expected;};
	/* ***** Getters / Setters ***** */
	bool getExpectedOutput(){return expectedOutput;}
	void setExpectedOutput(bool expect){this-> expectedOutput = &expect;}
private:
	// this is the output that I would have gotten from my classifier.
	bool* expectedOutput;
};
#endif //S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
