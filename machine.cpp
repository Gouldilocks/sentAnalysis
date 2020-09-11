//
// Created by Christian Gould on 9/3/20.
//

#include "machine.h"
#include "Stringy.h"
#include "testerReview.h"
#include <iostream>
#include <set>

machine::~machine () {
	delete testData;
}

machine::machine () {
	this->testData = new vector<testerReview *> (10000);
	this->outputMe = new Stringy ();
}

machine::machine (const machine &m1) {
	this->testData = new vector<testerReview *> (*m1.testData);
	this->outputMe = new Stringy (*m1.outputMe);
	this->numRight = m1.numRight;
	this->numWrong = m1.numWrong;
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
	this->numWrong = wrong;
}

void machine::jumpStart (ifstream &training_Data, ofstream &outPutHere) {
	this->take_In_Training_Data (training_Data);
	this->sort_Sentiment_Words ();
	this->take_In_Testing_Data (training_Data);
	this->sort_Testing_Data ();
	this->compare_Answers ();
	this->output_Result (outPutHere);
}

// First Major Operation
void machine::take_In_Training_Data (ifstream &training_Data) {
	cout << endl << "Taking in Training Data" << endl;
	// init stop words and counters
	Stringy stopWords ("a an and are as at be by for from has he in is it its of on that the to was were will with");
// input buffer
	char temp[50000];
// counts which row the input is on
	int rowCounter = 0;
// counts the number of unique words sorted for console
	int wordsSorted = 0;

	// while loop will iterate for each review
	while (training_Data.getline (temp, 49999) && rowCounter < 40001) {
		// skip the first line, which is the template.
		if (rowCounter == 0) {
			rowCounter++;
			continue;
		}
		// Stringy which holds the whole review, and clean it up
		Stringy total (temp);
		bool reviewSentiment = total.findSentiment (total);
		total.clean ();
		// tokenize the string and loop through it
		for (Stringy *currString : *total.tokenizeStringy (' ', stopWords, 3)) {
			// limit the number of rows being categorized.
			if (rowCounter < 20000) {
				/* for each of the words in the review:
				 * find if it is already categorized
				 * if it is, increase instances by appropriate sentiment
				 * if not, create a new word object in the set */
				word currWord (currString, reviewSentiment);
				auto it = sentimentWords.find (currWord);
				if (it == sentimentWords.end ()) {
					sentimentWords.insert (word (currWord));
					wordsSorted++;
				} else {
					it->add_Word (reviewSentiment);
				}
			}
		}
		rowCounter++;
	}
	// print to console for debugging / information
	cout << "Finished taking in Training Data" << endl;
	cout << "Number of unique words categorized: " << wordsSorted << endl;
	cout << endl;
}

// Second Major Operation
void machine::sort_Sentiment_Words () {
	cout << "Begin sorting sentiment words" << endl;
// calculate the sentiment by the number of occurrences of each of the words
	for (auto it = sentimentWords.begin (); it != this->sentimentWords.end (); it++) {
		// when you get to the end of sentimentWords, end the loop.
		it->calc_Sentiment ();
		// if the word does not meet requirements, delete it from usable words.
		if (it->getSentPtr () == nullptr) this->sentimentWords.erase (it);
	}
	cout << "Finished sorting sentiment words" << endl;
	cout << endl;
}

// Third Major Operation
void machine::take_In_Testing_Data (ifstream &testing_Data) {
	cout << "Starting taking in testing data" << endl;
	// the buffer
	char input_Buffer[50000];
	// the row which is being inputted
	int current_Row = 40000;
	// the number of positive words seen in a review
	int num_Pos_Wrd_Inst = 1;
	// the number of negative words seen in a review
	int num_Neg_Wrd_Inst = 1;
	// a counter to keep track of the review index for the vector
	int test_Review_Index = 0;

// While loop will iterate once for each review
	while (testing_Data.getline (input_Buffer, 50000)) {
		// initialize input buffer and clean it up
		Stringy pushMe (input_Buffer);
		bool senty = pushMe.findSentiment (pushMe);
		pushMe.clean ();

		// tokenize the input
		vector<Stringy *> *StringNow = pushMe.tokenizeStringy (' ', Stringy ("a"), 6);
		/* for every word in the review:
		 * check if in the set
		 * if in set, increase instances of that word with correct sentiment */
		for (int i = 0; i < StringNow->size (); i++) {
			auto it = sentimentWords.find ((word (*(*StringNow)[ i ], senty)));
			if (it != sentimentWords.end ()) {
				if ((it->getSent ())) {
					num_Pos_Wrd_Inst++;
				} else {num_Neg_Wrd_Inst++;}
			}
		}
		// create a new review with the acquired data
		(*this->testData)[ test_Review_Index ] = new testerReview (pushMe, current_Row, senty, num_Pos_Wrd_Inst,
																   num_Neg_Wrd_Inst);

		// increment counters and delete the vector
		current_Row++;
		test_Review_Index++;
		delete StringNow;
	}
	cout << "Finished take in testing data" << endl;
	cout << endl;
}


void machine::sort_Testing_Data () {
	cout << "Begin sorting testing data" << endl;
	for (int i = 0; i < 10000; i++) {
		if ((*testData)[ i ] == nullptr) break;
		(*testData)[ i ]->setExpectedOutput ((*testData)[ i ]->getPosWords () >= (*testData)[ i ]->getNegWords ());
	}
	cout << "Finished sorting testing data" << endl;
	cout << endl;
}

void machine::compare_Answers () {
	cout << "Begin comparing answers" << endl;
	int PosRevs = 0;
	int NegRevs = 0;
	// for each tested review in testData
	for (int i = 0; i < 10000; i++) {
		if ((*testData)[ i ] == nullptr) break;
		if ((*testData)[ i ]->getSentiment ())PosRevs++; else NegRevs++;
		if ((*testData)[ i ]->getSentiment () == (*testData)[ i ]->getExpectedOutput ()) {
			this->numRight++;
		} else {
			this->numWrong++;
			*outputMe = *outputMe + (*testData)[ i ]->getRow ();
			*outputMe = *outputMe + "\n";
		}
	}
	// print information to console
	cout << "Finished comparing answers" << endl;
	cout << endl;
	cout << "Positive reviews: " << PosRevs << endl;
	cout << "Negative reviews: " << NegRevs << endl;
}

void machine::output_Result (ofstream &outPutHere) {
	cout << "Begin output result" << endl;
	// print information to console
	cout << "numRight: " << (double) numRight << endl;
	cout << "numWrong: " << (double) numWrong << endl;
	double percentage = (double) this->numRight / ((double) this->numWrong + (double) this->numRight);
	cout << "Percentage: " << percentage << endl;
	outPutHere << percentage << endl;
	outPutHere << *this->outputMe << endl;
	cout << "End output result" << endl;
}

// ended up not using, due to inefficiency
word *machine::isInsideVectorStringy (vector<word *> v, const Stringy &k) {
	for (int i = 0; i < v.size (); i = i + 2) {
		if (v[ i ] == nullptr) return nullptr;
		if ((v[ i ]->get_The_Word ())->firstThree (k)) {return v[ i ];} else continue;
	}
	return nullptr;
}


