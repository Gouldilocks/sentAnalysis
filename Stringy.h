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
	/* ***** Destructor ***** */
	~Stringy();


	/* ***** Constructors ***** */
	//default sets string to NULL
	Stringy();
	//Takes in a string and creates an object
	Stringy(const char* input);
	// pointer constructor
	Stringy(Stringy *S);
	// copy constructor
	Stringy(const Stringy &s);


	/* ***** Functions ***** */
	// will find and remove the char* that is passed from the ystring.
	void findAndDelete(char* toFind);
	// returns a chracter at specified loc (includes 0)
	char& at(int loc);
	// if string is empty returns true else it returns false
	bool empty();
	//displays length of string including null
	int length() const;
	// returns the length of the string, excluding null-terminator
	int charLength();
	// takes the next word in the String, then returns a vector of each word according to the delimeter
	vector<Stringy*>* tokenizeStringy(char delim);
	// Modifies the current object to be a substring.
	void subStrObj(int index, int length);
	// returns a substring of the object
	Stringy substr(int index, int length);
	// sets the string
	void setString (const char* input); // $$$
	// returns the char* of this-> Stringy
	char * getString () const;
	// sets the ylength of this Stringy
	void setLength(int newLen);
	// returns the number of times the given Stringy appears in this-> Stringy
	int find_Number_Inside(Stringy* toFind);
	// cleans the string up according to the blacklist.
	void clean();


	/* ***** Overloaded Operators ***** */
	// outputs the ystring to the output stream.
	friend ostream& operator << (ostream & OS,const Stringy &S);
	// adds the input from IS to this Stringy
	friend istream& operator >> (istream & IS,Stringy &S);
	// assigns ystring and ylength from given Stringy.
	Stringy& operator = (const Stringy& S);
	// compares the ystrings, and NOT ylength.
	friend  bool operator ==(const Stringy& S1, const Stringy & S2);
	// adds two Stringys together and returns result. Does not modify parameters.
	friend Stringy & operator + (const Stringy& S1, const Stringy & S2);
	// adds Stringy to a char. Does not modify parameters.
	friend Stringy & operator + (const Stringy& S1,const char* addition);
	// adds an integer to a Stringy. Does not modify parameters.
	friend Stringy & operator + (const Stringy& S1, const int num_Toadd);
	// adds a Stringy to this Stringy. Modifies left hand side of operator. Does not modify right side.
	Stringy & operator += (const Stringy& S1);

private:
	int ylength;
	char* ystring;
};
#endif //S20_PA01_SENTIMENTANALYSIS_STRINGY_H
