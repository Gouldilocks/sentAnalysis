//
// Created by loggityloglog on 9/3/20.
//

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
	~machine(){delete trainData; delete testData; delete sentimentWords;}
	/*ToDo:
	 * Create Constructors
	 * Take the reviews and call the total parameter constructor in review. ~~Pull input with getline~~
	 *
	 *
	 *
	 *
	 * */
	/* ***** Constructors ***** */
	machine();
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
	void jumpStart(ifstream& testing_Data, ifstream& training_Data);

	// function will compare what was gotten versus what should have been gotten.
	void compare_Answers();

	void output_Result();

	void sort_Sentiment_Words();

	int getIndex(vector<word*>* v, word* K);
protected:
	//INITIALIZED IN-CONSTRUCTOR
	// a vector filled with all of the train data reviews.
	vector<review*>* trainData;

	// a vector filled with all of the testing data.
	vector<testerReview*>* testData;

	//INITIALIZED POST-CONSTRUCTOR
	// a vector filled with all of the words that have been categorized positive.
	vector<word*>* sentimentWords;

	int numRight;

	int numWrong;

	Stringy* outputMe;

};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
