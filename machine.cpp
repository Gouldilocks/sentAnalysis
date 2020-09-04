//
// Created by loggityloglog on 9/3/20.
//
#include "machine.h"
#include <sstream>
machine::machine () {
	this-> trainData = new vector<review*>();
	this->testData = new vector<review*>();
	this->sentimentWords = new vector<word*>();
this->take_In_Training_Data ();
this->sort_Training_Data ();
this->take_In_Testing_Data ();
}

void machine::take_In_Testing_Data () {
ifstream testing_Data("testing_Data.csv");
Stringy* testingData;
review* testingReview;
char temp[10000];
while(testing_Data.getline(temp,9999)){
testingData = new Stringy(temp);
testingReview = new review(testingData, 0);
this->testData->push_back(testingReview);
}
}

void machine::take_In_Training_Data () {
ifstream training_Data("training_Data.csv");
Stringy* trainingData;
review* trainingReview;
char temp[10000];
while(training_Data.getline(temp,9999)){
	trainingData = new Stringy(temp);
	trainingReview = new review(trainingData,1);
	this->trainData->push_back(trainingReview);
}
}
// todo: finish this function
void machine::sort_Training_Data () {
	Stringy* tempStringy;
	// for each review in the trainData array
	for (review *eachReview: *this->trainData) {
		// put the review's string into a string stream for tokenization.
		stringstream ss (eachReview->getSpaceSeparatedWords ()->getString ());
		char temp[10000];
		// tokenizes the words at each space.
		while (ss.getline (temp, 9999, ' ')) {
			tempStringy = new Stringy(temp);
			// if the review is positive
			if(eachReview->getSentiment ()){
			// check if the word is in the positive word bank
			for (word *eachWord: *sentimentWords) {
			// if it is in the bank, increment word count
			if (eachWord->getWordy() == tempStringy->getString ()){
				eachWord->increasePos ();
				// if it is not, then add it as new word
			} else {
				sentimentWords->push_back(new word(tempStringy, true));
			}
			}
			// if the review is negative
			} else if (!eachReview->getSentiment ()) {
				// check if the word is in the negative word bank
				for (word *eachWord: *sentimentWords) {
				// if it is in the bank, increment word count
				if (eachWord-> getWordy () == tempStringy->getString ()){
					eachWord->increaseNeg ();
				}
				// if it is not, then add it as new word
				else {
					sentimentWords->push_back((new word(tempStringy, false)));
				}
				}
			}
		}
	}
}
