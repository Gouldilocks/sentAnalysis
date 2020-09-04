//
// Created by loggityloglog on 8/31/20.
//
# include "Stringy.h"
# include <iostream>
# include <cstring>
using namespace std;

/*temp = is a temporary variable*/
Stringy::Stringy()
{
	//initialize the string at 1 character, being the null-terminator.
	ylength = 1;
	ystring = new char[ylength];
	ystring[ylength-1] = '\0';
}
Stringy::Stringy(const char *input) // constructor, given a c-string.
{
	// A new copy of a C-string contains exactly the same number of characters in
	// the C-string plus a terminating zero.
	this-> ylength = strlen(input) + 1;
	this-> ystring = new char[ this-> ylength ];
	// adds each of the elements in input including the null terminating zero.
	for (int i = 0; i < this-> ylength; i++) this-> ystring[ i ] = input[ i ];
}

Stringy :: Stringy (Stringy &S){
	this-> ylength = S.ylength;
	this-> ystring = new char [ylength];
	//make all the values in S part of this string
	for (int i = 0; i < this-> ylength; i++){
		this-> ystring[i] = S.ystring[i];
	}
}
//Destructor
Stringy::~Stringy()
{
	delete[] ystring;
}


int Stringy::length()
{
	int i = 0;
	while(ystring[i] != '\0')
	{i++;}
	return i;
}

char& Stringy::at(int loc)
{
	// this is the location without subracting 1, because of the null terminator.
	if(loc < ylength) {
		return ystring[ loc ];
	} else {
		cout << "location out of bounds in Stringy at function" << endl;
		return ystring[ 1 ];
	}
}
// returns a bool determining whether the Stringy object is empty or not.
bool Stringy::empty()
{
	//check to see if the first element is null, and if the length of the cstring is only one.
	return strlen (ystring) < 1;
}



Stringy* Stringy::substr(int index, int length)
{

	int size = length+1;
	char* temp = new char[size];
	int j = 0;
	//double for loop, in which it will end at a specified length "i" in the string,
	//and starts at zero for the new temp string.
	for(int i = index, j = 0; j < size; i++, j++)
	{
		temp[j] = ystring[i];
	}
	//make sure the end of the c-string is null-terminated.
	if(temp[size -1 ] != '\0'){temp[size -1] = '\0';}

	//create the variable which the new substring will be.
	auto* returnMe = new Stringy();
	returnMe->ylength = size;
	delete[]returnMe->ystring;
	returnMe->ystring = new char[size];

	for(int m = 0; m < size; m++){

		returnMe->ystring[m] = temp[m];

	}
	delete[]temp;
	return returnMe;
}

// Function to set the string to a new string.
void Stringy:: setString(const char* input){
	this-> ylength = strlen(input) + 1;
	this-> ystring = new char[ylength];
	for(int i = 0; i < ylength-1; i++){
		this-> ystring[i] = input[i];
	}
	this-> ystring[ylength-1] = '\0';
}

bool operator == (const Stringy & S1, const Stringy & S2)
{
	//if they are the same length, only then does the algorithm start.
	if(S1.ylength == S2.ylength)
	{
		bool same = true;
		int counter1 = S1.ylength;
		int counter2 = S2.ylength;
		int i = 0;
		//will loop through all but the null-terminator in the string.
		while(i < counter1 && i < counter2){
			// bool same will be set to false if any of the string pieces do not match.
			if(S1.ystring[i] != S2.ystring[i]){bool same = false;}
			i++;
		}
		// for testing.
		//cout << i << " " << counter2 << endl;
		return same;
	}
	// if the strings are not the same length, return false.
	else {return false;}

}

ostream& operator <<(ostream & OS, const Stringy& S)
{
	OS << S.ystring;
	return OS;
}

istream& operator >> (istream & IS,Stringy& S) {
	char tempArr[1000];
	IS >> tempArr;
	S.ylength = strlen(tempArr) +1;
	for(int i = 0; i < S.ylength -1; i++){
		S.ystring[i] = tempArr[i];
	}
	S.ystring[S.ylength-1] = '\0';
	return IS;
}
Stringy& Stringy::operator =(const Stringy &S)
{
	this-> ylength = S.ylength;
	delete[] this-> ystring;
	this-> ystring = new char[this-> ylength];
	for(int i = 0 ; i < (this-> ylength);i++)
	{
		this-> ystring[i] = S.ystring[i];
	}
	return *this;
}

Stringy& operator + (const Stringy& S1, const Stringy & S2){
	//add the lengths minus the null terminator, then add one to rep. the new null terminator.
	int length = (S1.ylength -1) + (S2.ylength - 1) + 1;
	// initialize the array that will be used
	char *array = new char[length];
	// add the first array to the full array, without the null terminator.
	for (int i = 0; i < S1.ylength-1; i ++) {
		array[i] = S1.ystring[i];
	}
	// add the second array to the full array, without the null terminator.
	for (int i = 0; i < S2.ylength - 1; i++){
		array[i + (S1.ylength-1)] = S2.ystring[i];
	}
	// add the null terminator to the end of the new array.
	array[length-1]  = '\0';
	// create the new Stringy object which will store this new added c-String.
	auto* returnMe = new Stringy(array);
	// delete the temp variable
	delete[] array;
	// return the new Stringy
	return *returnMe;
}
// not needed, just made for the heck of it:
Stringy& Stringy :: operator += (const Stringy& S1){
	// make total length equal to the original length minus null plus new stringy minus null plus new null
	int newLength = (this-> ylength -1) + (S1.ylength -1) + 1;
	int oldlength = this-> ylength;

	// save the old string in its original form
	char oldString[ylength];
	for(int i = 0; i < ylength; i++){
		oldString[i] = ystring[i];
	}

	// reset the string in this object.
	this-> ylength = newLength;
	delete[] this-> ystring;
	this-> ystring = new char[ylength];

	// add the two strings together into a new Stringy, excluding the null terminator
	for(int i = 0; i < oldlength - 1; i++){
		this-> ystring[i] = oldString[i];
	}
	// add the second string to the new string, including the null terminator
	for(int i = oldlength - 1, j = 0; i < ylength; i++, j++){
		this-> ystring[i] = S1.ystring[j];
	}
	// return the pointer.
	return *this;
}

Stringy &operator+ (const Stringy &S1, char *addition) {
	char * newStringy = nullptr;
	newStringy = new char [S1.ylength + strlen(addition)];
	for(int i = 0; i < S1.ylength-1; i++){
		newStringy[i] = S1.ystring[i];
	}
	for(int i = S1.ylength-1, j = 0; i < S1.ylength+strlen(addition); i++,j++){
		newStringy[i] = addition[j];
	}

	auto* returnMe = new Stringy(newStringy);
	cout << *returnMe << endl;
	return *returnMe;
}

/* Referenced Stack overflow for this function:
 * https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c
 * */
void Stringy::findAndDelete (char *toFind) {
	// strstr returns null if needle is not found in haystack. i.e. if toFind is not found in this-> ystring.
	while(strstr(this->ystring,toFind) != nullptr){

		/* this will find where the toFind string is inside of the ystring, then delete the word that was found
		by moving the data over the number of places that the length of toFind is. */
		 memmove(strstr(this->ystring,toFind), strstr(this->ystring,toFind) + strlen(toFind), strlen(ystring) - strlen(toFind));
		 this->ylength = strlen(this->ystring)+1;
	}
}

