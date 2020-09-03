//
// Created by loggityloglog on 9/3/20.
//
#include "machine.h"

machine::machine () {

}

void machine::take_In_Testing_Data () {
ifstream testing_Data("testing_Data");
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
ifstream training_Data("training_Data");
Stringy* trainingData;
review* trainingReview;
char temp[10000];
while(training_Data.getline(temp,9999)){
	trainingData = new Stringy(temp);
	trainingReview = new review(trainingData,1);
	this->trainData->push_back(trainingReview);
}
}

void machine::sort_Training_Data () {
	// for each review in the trainData array
	// todo: finish this function
for(review* eachReview: *this->trainData){

}
}
