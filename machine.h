//
// Created by loggityloglog on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#define S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#include "Stringy.h"
#include "review.h"
#include <vector>

/*The machine's purpose is to organize all of the functionality of the review class, and to
 * facilitate order within the program. The machine will also process all of the input and output of the end product.
 * */
class machine{
public:
	~machine(){delete trainData; delete testData; delete positiveWords; delete negativeWords;}
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

	void setTrainData(vector<review*>* trainData){this->trainData = trainData;}

	vector<Stringy*>* getPositiveWords(){return this->positiveWords;}

	void setPositiveWords(vector<Stringy*>* analysedWords){this->positiveWords = analysedWords;}

	vector<Stringy*>* getNegativeWords(){return this-> negativeWords;}

	void setNegativeWords(vector<Stringy*>* negativeWords){this->negativeWords = negativeWords;}

	/* ***** Functions ***** */
	// function which will input all of the data to be sorted into testData.
	void take_In_Testing_Data();

	// function which will input all of the data to be sorted into trainData.
	void take_In_Training_Data();

	// function which will put all the words into their respective vectors.
	void sort_Training_Data();

private:
	//PRE-CONSTRUCTOR
	// a vector filled with all of the train data reviews.
	vector<review*>* trainData;

	// a vector filled with all of the testing data.
	vector<review*>* testData;

	//POST-CONSTRUCTOR
	// a vector filled with all of the words that have been categorized positive.
	vector<Stringy*>* positiveWords;

	// a vector filled with all of the words that have been categorized negative.
	vector<Stringy*>* negativeWords;

};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
