//
// Created by loggityloglog on 8/31/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_STRINGY_H
#define S20_PA01_SENTIMENTANALYSIS_STRINGY_H
#include <cstring>
#include <fstream>
using namespace std;
class Stringy
{

public:
	/* *****     Constructors     ***** */
	//$$$
	Stringy();//default sets string to NULL
	//$$$
	Stringy(const char* input);//Takes in a string and creates an object
	//$$$
	Stringy(Stringy &S);//Copy constructor
	//$$$
	~Stringy();//Destructor deletes the nstring at the end

	/* *****     Functions     ***** */

	//displays length of string excluding null
	int length(); // $$$

	// returns a chracter at specified loc-1
	char& at(int loc); // $$$

	// if string is empty returns true else it returns false
	bool empty(); // $$$

	//	int find (const Stringy& S, int index =0);

	// returns a pointer to a substring of the object that calls it
	Stringy* substr(int index, int length); // $$$

	// sets the string of a Stringy that has not been initialized.
	void setString (const char* input); // $$$

	/* ********     Overloaded Operators     ******** */

	friend ostream& operator << (ostream & OS,const Stringy &S); // $$$

	//replaces given stringy with next line of input stream
	friend istream& operator >> (istream & IS,Stringy &S); // $$$

	Stringy& operator = (const Stringy& S);// $$$

	friend  bool operator ==(const Stringy& S1, const Stringy & S2); // $$$

	friend Stringy * operator + (const Stringy& S1, const Stringy & S2); // $$$

	Stringy * operator += (const Stringy& S1); // $$$

private:
	char* ystring;
	int ylength;
};
#endif //S20_PA01_SENTIMENTANALYSIS_STRINGY_H
