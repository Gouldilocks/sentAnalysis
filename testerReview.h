//
// Created by loggityloglog on 9/4/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
#define S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
#include "review.h"
#include "Stringy.h"
class testerReview : public review {
public:
	/* ***** Constructors ***** */
	testerReview();
	testerReview(Stringy* total, int row);
	testerReview(bool expected) : review() {this-> expectedOutput = &expected;};
	~testerReview(){delete expectedOutput; delete posWords; delete negWords;}
	/* ***** Getters / Setters ***** */
	bool getExpectedOutput(){return expectedOutput;}
	void setExpectedOutput(bool expect){this-> expectedOutput = &expect;}
	int* getPosWords(){return this-> posWords;}
	int* getNegWords(){return this-> negWords;}
	void setPosWords(int* pos){this-> posWords = pos;}
	void setNegWords(int* neg){this->negWords = neg;}
	void addToPosWords(int addMe);
	void addToNegWords(int addMe);
private:
	// this is the output that I would have gotten from my classifier.
	bool* expectedOutput;
	int* posWords;
	int* negWords;
};
#endif //S20_PA01_SENTIMENTANALYSIS_TESTERREVIEW_H
