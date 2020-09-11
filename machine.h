//
// Created by Christian Gould on 9/3/20.
//
#ifndef S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#define S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#include "Stringy.h"
#include "review.h"
#include "word.h"
#include "testerReview.h"
#include <vector>
#include <set>

/*The machine's purpose is to organize all of the functionality of the review class, and to
 * facilitate order within the program. The machine will also process all of the input and output of the end product.
 * */
class machine{
public:
	/* ***** Destructor ***** */
	~machine();


	/* ***** Constructors ***** */
	// default constructor
	machine();
	// copy constructor
	machine(const machine& m);


	/* ***** Getters / Setters ***** */
	// return number of rightly predicted reviews
	int get_Right();
	// set the number of rightly predicted reviews
	void set_Right(int right);
	// get the number of wrongly predicted reviews
	int get_Wrong();
	// set the number of wrongly predicted reviews
	void set_Wrong(int wrong);


	/* ***** Functions ***** */
	/* function will run all necessary functions in order to calculate
	 * sentiment of the testing data */
	void jumpStart(ifstream& training_Data, ofstream& outPutHere);
	// function which will input all of the data to be sorted into testData.
	void take_In_Testing_Data(ifstream& testing_Data);
	/* function will take words from testingData and
	 * put them into sentimentWords */
	void sort_Sentiment_Words();
	// function which will input all of the data to be sorted into trainData.
	void take_In_Training_Data(ifstream& training_Data);
	// function which will use the trained / learned data to sort unknown reviews
	void sort_Testing_Data();
	/*function will compare expected output to the actual output
	 * of the testing data */
	void compare_Answers();
	// function will output all the data to the output file
	void output_Result(ofstream& outPutHere);
	// checks if a string is in a given vector of words
	word* isInsideVectorStringy(vector<word*> v, const Stringy& k);

protected:
	// a vector filled with all of the testing data.
	vector<testerReview*>* testData;
	// a vector filled with all of the words that have been categorized positive.
	//vector<word*>* sentimentWords;
	set<word> sentimentWords;
	// the number of correctly predicted reviews.
	int numRight = 0;
	// the number of incorrectly predicted reviews.
	int numWrong = 0;
	// the output that will be put to the file.
	Stringy* outputMe;
};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
