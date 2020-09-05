//
// Created by loggityloglog on 9/3/20.
//
#include "machine.h"
#include <sstream>
#include <algorithm>
#include <iostream>

machine::machine () {
	this-> trainData = new vector<review*>();
	this->testData = new vector<testerReview*>();
	this->sentimentWords = nullptr;
	this->sentimentWords = new vector<word*>();
	this-> outputMe = new Stringy();

}
void machine:: jumpStart(ifstream& testing_Data, ifstream& training_Data) {
	this->take_In_Training_Data (training_Data);
	this->sort_Training_Data ();
	//this->sort_Sentiment_Words();
	//this->take_In_Testing_Data (testing_Data);
	//this->sort_Testing_Data (); todo: make code for this;
	//this->compare_Answers();
	//this->output_Result (); todo: make code for this
}

void machine::take_In_Testing_Data (ifstream& testing_Data) {
Stringy* testingData;
testerReview* testingReview;
char temp[10000];
int rowCounter = 1;
while(testing_Data.getline(temp,9999)){
testingData = new Stringy(temp);
testingReview = new testerReview(testingData, rowCounter);
this->testData->push_back(testingReview);
rowCounter++;
}
}

void machine::take_In_Training_Data (ifstream& training_Data) {
Stringy* trainingData;
review* trainingReview;
char temp[10000];
int rowCounter = 1;
while(training_Data.getline(temp,9999)){
	trainingData = new Stringy(temp);
	trainingReview = new review(trainingData,rowCounter);
	this->trainData->push_back(trainingReview);
	rowCounter++;
}
}
// todo: test this function
void machine::sort_Training_Data () {
	Stringy *tempStringy;
	// if the sentimentWords is empty, add the first word in trainData.
	if (this->sentimentWords->empty ()) {
		this->sentimentWords->push_back (new word (*this->trainData->at (0)->getSpaceSeparatedWords ()->getString (),
												   this->trainData->at (0)->getSentiment ()));
	}

		// for each of the reviews, do this.
		for (review *eachReview : *this->trainData) {
			// if the sentimentWords is not empty, check if it is in one of the existing words
			vector<Stringy *> *tokenizedWords = eachReview->getSpaceSeparatedWords ()->tokenizeStringy (' ');
			for (Stringy *putMeInSentimentWords : *tokenizedWords) {
				sentimentWords->push_back (new word (putMeInSentimentWords, eachReview->getSentiment ()));
			}
		}
	}
//todo: finish function
void machine::sort_Testing_Data () {

}
//todo: test function
void machine::compare_Answers () {
	// for each tested review in testData
for (testerReview testMe: *testData){
	if (testMe.getSentiment() == testMe.getExpectedOutput ()){
		this->numRight++;
	} else {
		// increase number wrong and add the row number to the output stringy with new line
		this->numWrong++;
		char rowArr[2] = {(char) testMe.getRow(), '\n'};
		*outputMe = *outputMe + rowArr;
	}
}
}
//todo: finish function
void machine::output_Result () {

}
//todo: test function
void machine::sort_Sentiment_Words () {
	vector<Stringy*>* words_To_Place;
	// initialize the sentiment words
this-> sentimentWords = new vector<word*> ();
for (review* thisReview : *trainData){
	words_To_Place = thisReview->getSpaceSeparatedWords()->tokenizeStringy(' ');
		// for each word in the review
		for(Stringy* tempStringy: *words_To_Place){
			// if the word is not already in the vector
			/* referenced stack overflow
			 * https://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
			 * */
			word* tempWord = new word(tempStringy, thisReview->getSentiment());
			//original code taken from stackoverflow -> if(std::find(v.begin(), v.end(), x) != v.end())
			// if the word is already in the vector
			if(getIndex(sentimentWords,tempWord) > -1){
				// if the review is positive increase positive of word
				if(thisReview->getSentiment ()) {
					sentimentWords->at(getIndex (sentimentWords, tempWord))->increasePos();
				}
				// if the review is negative increase negative of word
				if(!thisReview->getSentiment ()) {
					sentimentWords->at(getIndex (sentimentWords, tempWord))->increaseNeg();
				}
			}
			// otherwise add it as a new word.
			else{
				this-> sentimentWords->push_back(tempWord);
				// if the review is positive, add a positive count, if negative, add negative count.
				tempWord->add_Word (thisReview->getSentiment ());
			}
		}
}
}

/* referenced geeks for geeks
 * https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/
 * */
// Function to print the
// index of an element
int machine:: getIndex(vector<word*>* v, word* K)
{
	auto it = find(v->begin(),
				   v->end(), K);

	// If element was found
	if (it != v->end()) {
		// calculating the index
		// of K
		int index = distance(v->begin(),
							 it);
		return index;
	}
	else {
		// If the element is not
		// present in the vector
		cout << "-1" << endl;
		return -1;
	}
}