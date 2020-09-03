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
	/*ToDo:
	 * Create Constructors
	 * Take the call the total parameter constructor in review. ~~Pull input with getline~~
	 *
	 *
	 *
	 *
	 * */

private:
	// a vector filled with all of the train data reviews.
	vector<review*>* trainData;

	// a vector filled with all of the words that have been categorized positive and negative.
	vector<Stringy*>* analysedWords;
};
#endif //S20_PA01_SENTIMENTANALYSIS_MACHINE_H
