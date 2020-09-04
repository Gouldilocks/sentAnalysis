#include "testerReview.h"

//
// Created by loggityloglog on 9/4/20.
//
testerReview ::testerReview (Stringy* total, int row) :  review(total, row){
this-> expectedOutput = nullptr;
}
testerReview :: testerReview() : review(){
	this-> expectedOutput = nullptr;
}
