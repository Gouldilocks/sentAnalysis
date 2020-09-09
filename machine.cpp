//
// Created by loggityloglog on 9/3/20.
//

#include "machine.h"
#include "Stringy.h"
#include "review.h"
#include "testerReview.h"
#include <algorithm>
#include <iostream>
#include <set>

machine::machine () {
	this-> trainData = new vector<review*>();
	this->testData = new vector<testerReview*>();
	this->sentimentWords = nullptr;
	this->sentimentWords = new vector<word*>();
	this-> outputMe = new Stringy();

}
void machine:: jumpStart(ifstream& training_Data, ofstream& outPutHere) {
	this->take_In_Training_Data (training_Data);
	this->sort_Training_Data ();
	this->sort_Sentiment_Words();
	this->take_In_Testing_Data (training_Data);
	this->sort_Testing_Data ();
	this->compare_Answers();
	this->output_Result (outPutHere);
}

void machine::take_In_Testing_Data (ifstream& testing_Data) {
Stringy* testingData;
testerReview* testingReview;
char temp[10000];
int rowCounter = 40000;
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
while(training_Data.getline(temp,9999) && rowCounter < 40000){
	trainingData = new Stringy(temp);
	trainingReview = new review(trainingData,rowCounter);
	this->trainData->push_back(trainingReview);
	rowCounter++;
}
}
// this function simply puts all the data from the training into sentimentWords
// for Sort_Sentiment_Words to clean up.
void machine::sort_Training_Data () {

	// for each of the reviews, do this.
		for (review *eachReview : *this->trainData) {
			bool reviewSentiment = eachReview->getSentiment ();
			//cout << *eachReview->getTotal() << endl;
			// if the sentimentWords is not empty, check if it is in one of the existing words
			vector<Stringy *> *tokenizedWords = eachReview->getSpaceSeparatedWords ()->tokenizeStringy (' ');

			for (Stringy *putMeInSentimentWords : *tokenizedWords) {
				currentWord = new word(putMeInSentimentWords, reviewSentiment);

				// if the word is not already in the array, add it as a new word.
				if(this->sentimentWords->empty() || isInsideVector(*(this->sentimentWords), *currentWord) == nullptr) {
					//cout << *currentWord->get_The_Word () << endl;
					sentimentWords->push_back (currentWord);

					// otherwise, increase the number of that word.
				} else {
					word *ref = nullptr;
					ref = (isInsideVector (*this->sentimentWords, *currentWord));
					bool senty = eachReview->getSentiment ();
					// add the word to the list of words for that given word.
					isInsideVector (*this->sentimentWords, *ref)->add_Word (senty);
				}
			}
		}
	}
void machine::sort_Testing_Data () {
for(testerReview *thisReview : *testData){
	for(word* eachWord : *sentimentWords){
		// find the number of occurrences of this particular word inside of this review..
		int occurrences = thisReview->review :: getSpaceSeparatedWords()->find_Number_Inside (eachWord->get_The_Word ());
		// if the word is positive, increase positive word count
		if(occurrences > 0) {
			if (eachWord->getSent ()) {
				thisReview->addToPosWords (occurrences);
				// if the word is negative, increase negative word count
			} else {
				thisReview->addToNegWords (occurrences);
			}
		}
	}// end every word
	float percentage =(double) (*thisReview->getPosWords ())/(double)(*thisReview->getNegWords ());
	//cout << "Percentage: " << percentage << endl;
	//cout << "Positive: " << (double)*thisReview->getPosWords () << endl;
	//cout << "Negative: " << (double)*thisReview-> getNegWords () << endl;
	// if the percentage of positive words exceeds the number of
	// negative words, then set expected output to positive.
	thisReview->setExpectedOutput (percentage >= 1);
}// end every review
}
void machine::compare_Answers () {
	// for each tested review in testData
for (testerReview* testMe: *testData){
	if (testMe->getSentiment() == testMe->getExpectedOutput ()){
		this->numRight++;
	} else { // increase number wrong and add the row number to the output stringy with new line
		this->numWrong++;
		// create string add integer.
		*outputMe = *outputMe + testMe->getRow();
		*outputMe = *outputMe + "\n";
	}
}
}
void machine::output_Result (ofstream& outPutHere) {
	//cout << "numRight: " << (double) numRight << endl;
	//cout << "numWrong: " << (double) numWrong << endl;
double percentage = (double)this->numRight / ((double)this->numWrong + (double) this->numRight);
	//cout << "Percentage: " << percentage << endl;
outPutHere << percentage << endl;
outPutHere << *this-> outputMe << endl;
}

void machine::sort_Sentiment_Words () {
// calculate the sentiment by the number of occurrences of each of the words
	for(int i = 0; i < this->sentimentWords->size(); i++){
		//cout << *sentimentWords->at (i)->get_The_Word () << endl;
		sentimentWords->at(i)->calc_Sentiment ();
	// if the word does not meet requirements, delete it from usable words.
	if (sentimentWords->at(i)->getSentPtr () == nullptr) *this->sentimentWords->erase(sentimentWords->begin()+i);
}
}
/* referenced geeks for geeks
 * https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/
 * */
word* machine :: isInsideVector(vector<word*> v, word k){
	vector<word> vec;
	for(word * pushMeBack  : v){
		vec.push_back(*pushMeBack);
	}
	for(int i = 0; i < vec.size(); i++){
		if (vec.at(i) == k){ return v.at(i); } else continue;
	}
	return nullptr;
}
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
		//cout << "-1" << endl;
		return -1;
	}
}
machine::machine (const machine &m1) {
this-> trainData = new vector<review*>(*m1.trainData);
this-> testData = new vector<testerReview*>(*m1.testData);
this-> outputMe = new Stringy(*m1.outputMe);
this-> currentWord = new word(*m1.currentWord);
this-> numRight = m1.numRight;
this-> numWrong = m1.numWrong;
this-> sentimentWords = new vector<word*> (*m1.sentimentWords);
}
