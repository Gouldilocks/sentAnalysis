//
// Created by loggityloglog on 9/3/20.
//
/*	To do list:
 * ------------------------------
 * 1.) Make all input upper case
 * 2.) Fix Blacklist deleting substring words //todo: test that I fixed it.
 * 3.) Make all elements possible on the stack.
 * 4.) Fix output file type
 * 5.) Fix main for proper input
 * 6.) Finish catch cases
 * 7.) Fix n's and p's being shot out like crazy
 * in the reviews at sort_Training_Data
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
	~machine();


	/* ***** Constructors ***** */
	// default constructor
	machine();
	// copy constructor
	machine(const machine& m);


	/* ***** Getters / Setters ***** */
	// return the vector of reviews to be categorized
	vector<review*>* getTrainData();
	// set the vector of reviews to be categorized
	void setTrainData(vector<review*>* trainingData);
	// returns the vector of categorized words
	vector<word*>* getSentimentWords();
	// set the vector of categorized words
	void setSentimentWords(vector<word*>* analysedWords);
	// return number of rightly predicted reviews
	int get_Right();
	// set the number of rightly predicted reviews
	void set_Right(int right);
	// get the number of wrongly predicted reviews
	int get_Wrong();
	// set the number of wrongly predicted reviews
	void set_Wrong(int wrong);


	/* ***** Functions ***** */
	// function which will input all of the data to be sorted into testData.
	void take_In_Testing_Data(ifstream& testing_Data);
	// function which will use the trained / learned data to sort unknown reviews
	void sort_Testing_Data();
	// function which will input all of the data to be sorted into trainData.
	void take_In_Training_Data(ifstream& training_Data);
	// function which will put all the words from training data into their respective vectors.
	void sort_Training_Data();
	/* function will run all necessary functions in order to calculate
	 * sentiment of the testing data */
	void jumpStart(ifstream& training_Data, ofstream& outPutHere);
	/*function will compare expected output to the actual output
	 * of the testing data */
	void compare_Answers();
	// function will output all the data to the output file
	void output_Result(ofstream& outPutHere);
	/* function will take words from testingData and
	 * put them into sentimentWords */
	void sort_Sentiment_Words();
	/* function will get the index of the given word
	 * and return it. Returns -1 if cannot find */
	int getIndex(vector<word*>* v, word* K);
	/* Given a vector containing pointers to k variables,
	 * this function will return the pointer to a matching
	 * word k, and if none is found, will return nullptr
	 */
	word* isInsideVector(vector<word*> v, word k);
	word* isInsideVectorStringy(vector<word*> v, const Stringy& k);
	// returns a bool of the sentiment of a given Stringy.
	bool findSentiment(Stringy total);
	// cleans up the given String to fit the blacklist.
	void cleanUp(ifstream& noNoWords, Stringy& toClean);
protected:
	// a vector filled with all of the train data reviews.
	vector<review*>* trainData;
	// a vector filled with all of the testing data.
	vector<testerReview*>* testData;
	// a vector filled with all of the words that have been categorized positive.
	vector<word*>* sentimentWords;
	// the number of correctly predicted reviews.
	int numRight = 0;
	// the number of incorrectly predicted reviews.
	int numWrong = 0;
	// the output that will be put to the file.
	Stringy* outputMe;
	// the current word being analyzed.
	word* currentWord;

};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
