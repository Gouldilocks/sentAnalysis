//
// Created by loggityloglog on 8/31/20.
//

#ifndef S20_PA01_SENTIMENTANALYSIS_STRINGY_H
#define S20_PA01_SENTIMENTANALYSIS_STRINGY_H
#include <cstring>
#include <fstream>
#include <vector>
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

	// will find and remove the char* that is passed from the ystring.
	void findAndDelete(char* toFind);

	//displays length of string excluding null
	int length(); // $$$

	// returns a chracter at specified loc-1
	char& at(int loc); // $$$

	// if string is empty returns true else it returns false
	bool empty(); // $$$

	//	int find (const Stringy& S, int index =0);

	// takes the next word in the String, then returns a vector of each word according to the delimeter
	vector<Stringy*>* tokenizeStringy(char delim);

	// returns a pointer to a substring of the object that calls it
	Stringy* substr(int index, int length); // $$$

	// sets the string of a Stringy that has not been initialized.
	void setString (const char* input); // $$$

	char* getString (){return this-> ystring;}

	void setLength(int newLen){this->ylength = newLen;}
	/* ********     Overloaded Operators     ******** */

	friend ostream& operator << (ostream & OS,const Stringy &S); // $$$

	friend istream& operator >> (istream & IS,Stringy &S); // $$$

	Stringy& operator = (const Stringy& S);// $$$

	friend  bool operator ==(const Stringy& S1, const Stringy & S2); // $$$

	friend Stringy & operator + (const Stringy& S1, const Stringy & S2); // $$$

	friend Stringy & operator + (const Stringy& S1, char addition[]); // $$$

	Stringy & operator += (const Stringy& S1); // $$$

private:
	char* ystring;
	int ylength;
};
#endif //S20_PA01_SENTIMENTANALYSIS_STRINGY_H
