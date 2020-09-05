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
	int counter = 0;
	Stringy *tempStringy;
	// for each review in the trainData array
	for (review *eachReview: *this->trainData) {
		// put the review's string into a string stream for tokenization.
		stringstream ss (eachReview->getSpaceSeparatedWords ()->getString ());
		char temp[10000];
		// tokenizes the words at each space.
		while (ss.getline (temp, 9999, ' ')) {
			counter = 0;
			tempStringy = new Stringy (temp);
			// if the review is positive
			if (sentimentWords->empty()){
				sentimentWords->push_back (new word (tempStringy, eachReview->getSentiment ()));
					continue;
			} else
			if (eachReview->getSentiment ()) {
				// check if the word is in the positive word bank
				//for (word *eachWord: *sentimentWords) {
				for(auto eachWord : *sentimentWords){
					counter++;
						// if it is in the bank, increment word count
					if (eachWord->get_The_Word()->getString() == tempStringy->getString ()) {
						eachWord->increasePos ();
						// if it is not, then add it as new word
					} else {
						if (tempStringy->length () > 1) {
							sentimentWords->push_back (new word (tempStringy, true));
						} else continue;
					}
				}
				// if the review is negative
			} else if (!eachReview->getSentiment ()) {
				// check if the word is in the negative word bank
				for (word *eachWord: *sentimentWords) {
					// if it is in the bank, increment word count
					if (eachWord->getWordy () == tempStringy->getString ()) {
						eachWord->increaseNeg ();
					}
						// if it is not, then add it as new word
					else {
						if (tempStringy->length () > 1) {
							sentimentWords->push_back (new word (tempStringy, false));

						}
					}
				}
			}
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
