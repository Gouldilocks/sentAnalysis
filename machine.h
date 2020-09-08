//
// Created by loggityloglog on 9/3/20.
//
/*	To do list:
 * -------------
 * 1.) Make all input upper case
 * 2.) Check for rule of threes
 * 3.) Fix Blacklist deleting substring words
 * 4.) Make all elements on the heap
 * 5.) Fix output file type
 * 6.) Fix main for proper input
 * 7.) Finish catch cases
 *
 *
 */
#ifndef S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#define S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#include "Stringy.h"
#include "review.h"
#include "word.h"
#include "testerReview.h"
#include <vector>

/*The machine's purpose is to organize all of the functionality of the review class, and to
 * facilitate order within the program. The machine will also process all of the input and output of the end product.
 * */
class machine{
public:
	/* ***** Destructor ***** */
	~machine(){delete trainData; delete testData; delete sentimentWords; delete currentWord;} /* ***** Constructors ***** */
	machine();

	machine(const machine& m);
	/* ***** Getters / Setters ***** */
	vector<review*>* getTrainData(){return this->trainData;}

	void setTrainData(vector<review*>* trainingData){this->trainData = trainingData;}

	vector<word*>* getSentimentWords(){return this->sentimentWords;}

	void setSentimentWords(vector<word*>* analysedWords){this->sentimentWords = analysedWords;}

	int get_Right() {return this->numRight;}

	void set_Right(int right){this->numRight = right;}

	int get_Wrong() {return this->numWrong;}

	void set_Wrong(int wrong){this-> numWrong = wrong;}
	/* ***** Functions ***** */
	// function which will input all of the data to be sorted into testData.
	void take_In_Testing_Data(ifstream& testing_Data);

	// function which will use the trained / learned data to sort unknown reviews
	void sort_Testing_Data();

	// function which will input all of the data to be sorted into trainData.
	void take_In_Training_Data(ifstream& training_Data);

	// function which will put all the words into their respective vectors.
	void sort_Training_Data();

	// function which will jumpstart the whole proces of the program.
	void jumpStart(ifstream& testing_Data, ifstream& training_Data, ofstream& outPutHere);

	// function will compare what was gotten versus what should have been gotten.
	void compare_Answers();

	// function will output all the data to the output file
	void output_Result(ofstream& outPutHere);

	/* function will take words from testingData and
	 * put them into sentimentWords */
	void sort_Sentiment_Words();

	/* function will get the index of the given word
	 * and return it. Returns -1 if cannot find */
	int getIndex(vector<word*>* v, word* K);

	word* isInsideVector(vector<word*> v, word k);
protected:
	//INITIALIZED IN-CONSTRUCTOR
	// a vector filled with all of the train data reviews.
	vector<review*>* trainData;

	// a vector filled with all of the testing data.
	vector<testerReview*>* testData;

	//INITIALIZED POST-CONSTRUCTOR
	// a vector filled with all of the words that have been categorized positive.
	vector<word*>* sentimentWords;

	int numRight = 0;

	int numWrong = 0;

	Stringy* outputMe;

	word* currentWord;

};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
