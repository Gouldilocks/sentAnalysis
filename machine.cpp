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
#include <sstream>

machine::machine () {
	this-> trainData = new vector<review*>();
	this->testData = new vector<testerReview*>(10000);
	this->sentimentWords = new vector<word*>(50000);
	this-> outputMe = new Stringy();

}
void machine:: jumpStart(ifstream& training_Data, ofstream& outPutHere) {
	cout << "Taking in Training Data" << endl;
	this->take_In_Training_Data (training_Data);
	cout << "Finished taking in Training Data" << endl;
	cout << endl;
	cout << "Begin sorting sentiment words" << endl;
	this->sort_Sentiment_Words();
	cout << "Finished sorting sentiment words" << endl;
	cout << endl;
	cout << "Starting taking in testing data" << endl;
	this->take_In_Testing_Data (training_Data);
	cout << "Finished take in testing data" << endl;
	cout << endl;
	cout << "Begin sorting testing data" << endl;
	this->sort_Testing_Data ();
	cout << "Finished sorting testing data" << endl;
	cout << endl;
	cout << "Begin comparing answers" << endl;
	this->compare_Answers();
	cout << "Finished comparing answers" << endl;
	cout << endl;
	cout << "Begin output result" << endl;
	this->output_Result (outPutHere);
	cout << "End output result" << endl;
}

void machine::take_In_Testing_Data (ifstream& testing_Data) {
char temp[50000];
int rowCounter = 40000;
int numPos = 1;
int numNeg = 1;
int testerReviewIndex = 0;
while(testing_Data.getline(temp,50000) /*&& rowCounter < 40300*/){
	Stringy pushMe(temp);
	bool senty = pushMe.findSentiment (pushMe);
	pushMe.clean ();
for(int i = 0; i < 20000; i++){
	if((*sentimentWords)[i] == nullptr) break;
	//cout << (*(*sentimentWords)[i]) << endl;
	if(pushMe.wordInsideIt ((*sentimentWords)[i]->get_The_Word ())){
		if((*sentimentWords)[i]->getSent()){
			numPos++;
		} else numNeg++;
	}
}
// fix this having all nulls
	(*this->testData)[testerReviewIndex] = new testerReview(pushMe,rowCounter,senty,numPos,numNeg);
rowCounter++;
testerReviewIndex++;
}
//cout << "Size of TestData: " << testData->size() << endl;
//for(int i = 0; i < 20000; i++){
//	if((*testData)[i] == nullptr) break;
//	cout << *(*testData)[i]->getTotal() << endl;
}
//}

void machine::take_In_Training_Data (ifstream& training_Data) {
//Stringy stopWords("a an and are as at be by for from has he in is it its of on that the to was were will with");
Stringy stopWords("a");
char temp[50000];
int rowCounter = 0;
int wordsSorted = 0;
//int wordMade = 0;
while(training_Data.getline(temp,49999) && rowCounter < 40001){
	if(rowCounter == 20000)cout << "gotem" << endl;
	//cout << temp << endl;
	if (rowCounter == 0) {rowCounter++; continue;}
	//cout << "Finished that loop " << rowCounter << " times" << endl;
	Stringy total(temp);
	bool reviewSentiment = total.findSentiment(total);
	total.clean();
		for(Stringy* currString : *total.tokenizeStringy(' ', stopWords,3)) {
			//cout << "The word is " << *currString << endl;
			// make sure not to get the random ones.
			if (rowCounter < 20000) {
				word currWord (currString, reviewSentiment);
				word *inside = isInsideVectorStringy (*this->sentimentWords, currString);
				if (inside == nullptr) {
					//wordMade++;
					//cout << "Word made # " << wordMade << endl;
					(*this->sentimentWords)[wordsSorted] = (new word (currWord));
					//cout << "At sorted num: " << wordsSorted << endl;
					//cout << *(*this->sentimentWords)[wordsSorted] << endl;
					wordsSorted++;
				} else {
					inside->add_Word (reviewSentiment);
					//cout << *currString << " Added to " << *inside << endl;
				}
			}
		}
	rowCounter++;
}
cout << "Number of unique words categorized: " << wordsSorted << endl;
//for(int i = 0; i < wordsSorted; i++){
//	cout << *(*this->sentimentWords)[wordsSorted] << endl;
//}
}


void machine::sort_Testing_Data () {
for(int i = 0; i < 10000; i++){
	if((*testData)[i] == nullptr) break;
	//cout << "Percentage: " << percentage << endl;
	//cout << "Positive: " << (double)*thisReview->getPosWords () << endl;
	//cout << "Negative: " << (double)*thisReview-> getNegWords () << endl;
	//cout << *thisReview->getTotal () << endl;
	// if the percentage of positive words exceeds the number of
	// negative words, then set expected output to positive.
	//cout << "Poswords >= Negwords returns: " << (thisReview->getPosWords() >= thisReview->getNegWords ()) << endl;
	(*testData)[i]->setExpectedOutput ((*testData)[i]->getPosWords () >= (*testData)[i]->getNegWords ());
	//cout << "Expected Output: " << thisReview->getExpectedOutput () << endl;
}// end every review
}
void machine::compare_Answers () {
	int PosRevs = 0;
	int NegRevs = 0;
	// for each tested review in testData
for (int i = 0; i < 10000; i++){
	if((*testData)[i] == nullptr) break;
	if((*testData)[i]->getSentiment ())PosRevs++; else NegRevs++;
	if ((*testData)[i]->getSentiment() == (*testData)[i]->getExpectedOutput ()){
		this->numRight++;
		//cout << *testMe-> getTotal () << endl;
	} else { // increase number wrong and add the row number to the output stringy with new line
		this->numWrong++;
		//cout << *testMe->getTotal () << endl;
		// create string add integer.
		*outputMe = *outputMe + (*testData)[i]->getRow();
		*outputMe = *outputMe + "\n";
	}
}
cout << "Positive reviews: " << PosRevs << endl;
cout << "Negative reviews: " << NegRevs << endl;
}
void machine::output_Result (ofstream& outPutHere) {
	cout << "numRight: " << (double) numRight << endl;
	cout << "numWrong: " << (double) numWrong << endl;
double percentage = (double)this->numRight / ((double)this->numWrong + (double) this->numRight);
	cout << "Percentage: " << percentage << endl;
outPutHere << percentage << endl;
outPutHere << *this-> outputMe << endl;
}

void machine::sort_Sentiment_Words () {
// calculate the sentiment by the number of occurrences of each of the words
	for(int i = 0; i < this->sentimentWords->size(); i++){
		//cout << *sentimentWords->at (i)->get_The_Word () << endl;
		// when you get to the end of sentimentWords, end the loop.
		if ((*sentimentWords)[i] == nullptr) {return;}
		(*sentimentWords)[i]->calc_Sentiment ();
		//cout << *sentimentWords->at(i) << endl;
	// if the word does not meet requirements, delete it from usable words.
	if ((*sentimentWords)[i]->getSentPtr () == nullptr) *this->sentimentWords->erase(sentimentWords->begin()+i);
}
}
/* referenced geeks for geeks
 * https://www.geeksforgeeks.org/how-to-find-index-of-a-given-element-in-a-vector-in-cpp/
 * */
word* machine :: isInsideVector(vector<word*> v, word k){
	for(int i = 0; i < v.size(); i++){
		if (*v.at(i) == k){ return v.at(i); } else continue;
	}
	return nullptr;
}
word* machine :: isInsideVectorStringy(vector<word*> v, const Stringy& k){
	for(int i = 0; i < v.size(); i = i+2){
		if(v[i] == nullptr) return nullptr;
//		cout << (v[i])->get_The_Word() << " is the vector word compared to ";
//		cout << k << endl;
//		cout << "Returns: " << (v[i]->get_The_Word() == k) << endl;
	if((v[i]->get_The_Word())->firstThree(k)){return v[i];} else continue;
	}
	return nullptr;
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

machine::~machine () {
	delete trainData; delete testData; delete sentimentWords; delete currentWord;
}

vector<review *> *machine::getTrainData () {
	return this->trainData;
}

void machine::setTrainData (vector<review *> *trainingData) {
	this->trainData = trainingData;
}

vector<word *> *machine::getSentimentWords () {
	return this->sentimentWords;
}

void machine::setSentimentWords (vector<word *> *analysedWords) {
	this->sentimentWords = analysedWords;
}

int machine::get_Right () {
	return this->numRight;
}

void machine::set_Right (int right) {
	this->numRight = right;
}

int machine::get_Wrong () {
	return this->numWrong;
}

void machine::set_Wrong (int wrong) {
	this-> numWrong = wrong;
}
void machine::cleanUp (ifstream& noNoWords, Stringy& stringy) {
	char temporary[200];
	int counter = 0;
	counter++;
	while(noNoWords.getline(temporary,150,' ')) {
		Stringy tempStringy(temporary);
		stringy.findAndDelete(tempStringy.getString ());
	}
}