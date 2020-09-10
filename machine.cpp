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
	this->testData = new vector<testerReview*>();
	this->sentimentWords = nullptr;
	this->sentimentWords = new vector<word*>();
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
char temp[10000];
int rowCounter = 40000;
while(testing_Data.getline(temp,9999) && rowCounter < 40300){
	cout << temp << endl;
	Stringy pushMe(temp);
	bool senty = findSentiment (pushMe);
	pushMe.clean ();
	this->testData->push_back(new testerReview(pushMe, rowCounter, senty));
rowCounter++;
}
}

void machine::take_In_Training_Data (ifstream& training_Data) {
char temp[10000];
int rowCounter = 1;
while(training_Data.getline(temp,9999) && rowCounter < 300){
	//cout << "Finished that loop " << rowCounter << " times" << endl;
	ifstream noNoWords("blackList.txt");
	Stringy total(temp);
	bool reviewSentiment = findSentiment(total);
	total.clean();
	rowCounter++;
	for(Stringy* currString : *total.tokenizeStringy(' ')){
		word currWord(currString,reviewSentiment);
		word* inside = isInsideVector (*this->sentimentWords,currWord);
	if (inside == nullptr){
	this->sentimentWords->push_back(new word(currWord));
	}
	else {
		inside->add_Word(reviewSentiment);
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
	for(int i = 0; i < v.size(); i++){
		if (*v.at(i) == k){ return v.at(i); } else continue;
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
bool machine::findSentiment (Stringy total) {
	// whole function will not execute if Stringy is empty.
	if (total.empty()) return false;
	bool returnMe = false;
	for(int i = 0; i < total.length (); i++){
		if (i == total.length() - 1) return i;
		else{
			// will only return true if ",p or ",|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')
			if (total.getString ()[i] == '"'  && (total.getString ()[i+1] == ','|| total.getString ()[i+1] == '\t' || total.getString ()[i+1] == '|') && total.getString ()[i+2] == 'p')	{
				return true;
			}
			else if(total.getString ()[i] == '"'  && (total.getString ()[i+1] == ','|| total.getString ()[i+1] == '\t' || total.getString ()[i+1] == '|') && total.getString ()[i+2] == 'n'){
				return false;
			}
		}
	}
	return returnMe;
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