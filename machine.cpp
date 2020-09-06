//
// Created by loggityloglog on 9/3/20.
//
#include "machine.h"
#include <sstream>
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
void machine:: jumpStart(ifstream& testing_Data, ifstream& training_Data) {
	this->take_In_Training_Data (training_Data);
	this->sort_Training_Data ();
	this->sort_Sentiment_Words();
	this->take_In_Testing_Data (testing_Data);
	this->sort_Testing_Data ();
	this->compare_Answers();
	this->output_Result ();
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
// this function simply puts all the data from the training into sentimentWords
// for Sort_Sentiment_Words to clean up.
void machine::sort_Training_Data () {
	Stringy *tempStringy;
		// for each of the reviews, do this.
		for (review *eachReview : *this->trainData) {
			bool reviewSentiment = eachReview->getSentiment ();
			// if the sentimentWords is not empty, check if it is in one of the existing words
			vector<Stringy *> *tokenizedWords = eachReview->getSpaceSeparatedWords ()->tokenizeStringy (' ');
			for (Stringy *putMeInSentimentWords : *tokenizedWords) {
				word* tempWord = new word(putMeInSentimentWords, reviewSentiment);
				sentimentWords->push_back (tempWord);

			}
		}
	}
//todo: finish function
void machine::sort_Testing_Data () {
for(testerReview *thisReview : *testData){
	for(word* thisWord : *sentimentWords){
		// find the number of occurrences of this particular word inside of this review..
		int occurrences = thisReview->getSpaceSeparatedWords()->find_Number_Inside (thisWord->get_The_Word ());
		// if the word is positive, increase positive word count
		if(thisWord->getSent()){
			thisReview->addToPosWords (occurrences);
		// if the word is negative, increase negative word count
		}else{
			thisReview->addToNegWords (occurrences);
		}
	}// end every word
	float percentage = (*thisReview->getPosWords ())/(*thisReview->getNegWords ());
	if (percentage >= 1){
	thisReview->setExpectedOutput (true);
	} else {
	thisReview->setExpectedOutput (false);
	}
}// end every review
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
ofstream outPutHere("outPutFile.csv");
float percentage = this->numRight / this->numWrong;
outPutHere << percentage << endl;
outPutHere << this-> outputMe << endl;
}
//todo: redo function
void machine::sort_Sentiment_Words () {
	int negAdd = 0;
	int posAdd = 0;
	// account for how many instances of words there are
	for (word *thisWord : *sentimentWords) {
		for (int i = 0; i < sentimentWords->size (); i++) {
			if (thisWord == sentimentWords->at (i) && !sentimentWords->at (i)->getSorted ()) {
				//thisWord->setNumNeg (thisWord->getNumNeg () + sentimentWords->at(i)->getNumNeg ());
				//thisWord->setNumPos (thisWord->getNumPos () + sentimentWords->at(i)->getNumPos ());
				if (sentimentWords->at (i)->getNumPos () > 0) {
					thisWord->add_Word (true);
				} else thisWord->add_Word (false);
				// set the number of negative and positive for the next word to zero
				// so that the algorithm does not make the numbers too high.
				sentimentWords->at (i)->setNumNeg (0);
				sentimentWords->at (i)->setNumPos (0);
				// set the sorted portion of the words to true.
				thisWord->setSorted (true);
				sentimentWords->at (i)->setSorted (true);
			}
		}
		// make all the words equivalent in size.
//		for(int i = 0; i < sentimentWords->size(); i++){
//			if(thisWord == sentimentWords->at (i)){
//				sentimentWords->at(i)->setNumNeg (negAdd);
//				sentimentWords->at(i)->setNumPos (posAdd);
	}
	// then remove the duplicate words
	removeVec (*sentimentWords);
}



/* referenced geeks for geeks
 * https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/
 * */
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
/*
https://www.techiedelight.com/remove-duplicates-vector-cpp/
 */
// reference for this function
void machine :: removeVec (vector<word*> &vec) {
//	vector<int> eraseMe;
//	for(int j = 0; j < vec.size(); j++){
//		for(int i = j; i < vec.size(); i++){
//			if(vec.at(j)->getWordy () == vec.at(i)->getWordy () && vec.at (i)->getSorted ()){
//				vec.at(i)->setSorted(false);
//				eraseMe.push_back(i);
//			}
//		}
//	}
//	// set to descending order
//	sort(eraseMe.begin(), eraseMe.end(), greater<int>());
//	// erase the parts of the vector
//	for(int eraseInt : eraseMe){
//		vec.erase(vec.begin() + eraseInt - 1);
//	}
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
}