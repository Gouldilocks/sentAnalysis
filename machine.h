//
// Created by loggityloglog on 9/3/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#define S20_PA01_SENTIMENTANALYSIS_MACHINE_H
#include "Stringy.h"
#include "review.h"
#include <vector>

class machine{
public:
	Stringy* getBlackList(){return blackList;}
	void setBlackList(Stringy* blackList){this-> blackList = blackList;}
	void makeBlackList();
private:
	// the space-separated list of words which are banned from being analyzed.
	Stringy* blackList = nullptr;
	// a vector filled with all of the train data reviews.
	vector<review> trainData;
};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
