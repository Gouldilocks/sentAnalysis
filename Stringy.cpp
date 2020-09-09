//
// Created by loggityloglog on 8/31/20.
//
# include "Stringy.h"
# include <iostream>
# include <cstring>
# include <sstream>
using namespace std;

/*temp = is a temporary variable*/
Stringy::Stringy()
{
	//initialize the string at 1 character, being the null-terminator.
	ylength = 1;
	ystring = new char[ylength];
	ystring[ylength-1] = '\0';
}
Stringy::Stringy(const char* input) // constructor, given a c-string.
{
	// A new copy of a C-string contains exactly the same number of characters in
	// the C-string plus a terminating zero.
	this-> ylength = strlen(input) + 1;
	this-> ystring = new char[ this-> ylength ];
	// adds each of the elements in input including the null terminating zero.
	for (int i = 0; i < this-> ylength; i++) {
		this->ystring[ i ] = input[ i ];
	}
}
Stringy :: Stringy (const Stringy &s){
	this-> ylength = s.ylength;
	this-> ystring = new char[ylength];
	strcpy (this->ystring,s.ystring);
}
Stringy :: Stringy (Stringy *S){
	this-> ylength = S->length ();
	this-> ystring = new char [ylength];
	//make all the values in S part of this string
	for (int i = 0; i < this-> ylength; i++){
		this-> ystring[i] = S->getString()[i];
	}
}
//Destructor
Stringy::~Stringy()
{
	delete[] ystring;
}


int Stringy::length() const {
	return (this-> ylength);
}
int Stringy :: charLength(){
	return strlen(this-> ystring);
}

char& Stringy::at(int loc)
{
	// this is the location without subracting 1, because of the null terminator.
	if(loc < ylength) {
		return ystring[ loc ];
	} else {
		cout << "location out of bounds in Stringy (at) function" << endl;
		return ystring[ 1 ];
	}
}
// returns a bool determining whether the Stringy object is empty or not.
bool Stringy::empty()
{
	//check to see if the first element is null, and if the length of the cstring is only one.
	return strlen (ystring) < 1;
}



void Stringy::subStrObj(int index, int length)
{

	int size = length+1;
	char * temp = new char[size];
	//double for loop, in which it will end at a specified length "i" in the string,
	//and starts at zero for the new temp string.
	for(int i = index, j = 0; j < size; i++, j++)
	{
		temp[j] = ystring[i];
	}
	//make sure the end of the c-string is null-terminated.
	if(temp[size-1] != '\0'){temp[size-1] = '\0';}
	delete this-> ystring;
	this-> ystring = temp;
	this-> ylength = size;
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
	return strcmp (S1.getString (), S2.getString ()) == 0;

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
Stringy& Stringy::operator = (const Stringy &S)
{
	// if it is self assignment, return this Stringy
	if(this == &S) return *this;
	//set the length the same, then delete this Stringy's string.
	this-> ylength = S.ylength;
	delete[] this-> ystring;
	this-> ystring = new char[this-> ylength];
	// copy each of the elements of S to this Stringy.
	for(int i = 0 ; i < (this-> ylength);i++)
	{
		this-> ystring[i] = S.ystring[i];
	}
	// return this Stringy.
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
	// return the Stringy.
	return *this;
}

Stringy &operator+ (const Stringy &S1,const char* addition)  {
	char* newStringy = nullptr;
	int newlen = strlen(S1.getString()) + strlen(addition)+1;
	newStringy = new char [newlen];
	for(int i = 0; i < strlen(S1.getString ()); i++){
		newStringy[i] = S1.getString ()[i];
	}
	for(int i = strlen(S1.getString ()), j = 0; i < newlen; i++,j++){
		newStringy[i] = addition[j];
	}
	newStringy[newlen] = '\0';
	return *new Stringy(newStringy);
}

/* Referenced Stack overflow for this function:
 * https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c
 * */

void Stringy::findAndDelete (char *toFind) {
	// strstr returns null if needle is not found in haystack. i.e. if toFind is not found in this-> ystring.
	/* while loop checks these:
	 * That the char* exists
	 * That the char before the word is a space
	 * That the char after the word is a space
	 * That the char is not an empty string
	 * */
	//&& (strcmp(begOfWord -1 , " ")) == 0 && strcmp(toFind,"") != 0 && strcmp((begOfWord + (toFindLen + 1) ), " ") == 0
	while(this->ystring, toFind != nullptr){
		char* begOfWord = strstr(this->ystring,toFind);
		if(begOfWord == nullptr) return;
		int toFindLen = strlen(toFind);
		int bytesToMove = strlen(begOfWord) - toFindLen;
		//cout << "Find n' Delete" << endl;
		/* this will find where the toFind string is inside of the ystring, then delete the word that was found
		by moving the data over the number of places that the length of toFind is. */
			//cout << "toFind: " << toFind << endl;
			//cout << "Destination: " << strstr(this->ystring,toFind) << endl;
			//cout << "Source: " << strstr(this->ystring, toFind) + strlen(toFind) << endl;
			//cout << "Number of Bytes: " << bytesToMove << endl;
			//cout << "******************" << endl;
			memmove (begOfWord, begOfWord + toFindLen,
					 bytesToMove);
		subStrObj (0, this->length () - toFindLen);
		this->ylength = strlen (ystring) + 1;
	}
}

vector<Stringy *>* Stringy::tokenizeStringy (char delim) {
	auto* returnMe = new vector<Stringy*> ();
	char temp[10000];
	Stringy* tempStringy;
	stringstream ss(this->getString ());
	while(ss.getline(temp,9999, delim)){
		// avoid spaces being put into the word vector.
		if(temp[0] != ' ') {
			tempStringy = new Stringy (temp);
			returnMe->push_back (tempStringy);
		} else continue;
	}
	return returnMe;
}

int Stringy :: find_Number_Inside(Stringy* toFind) {
	int returnMe = 0;
	//cout << "Stringy toFind: " << *toFind << endl;
	//cout << "char* findMe: " << toFind-> getString () << endl;
	char* findMe = toFind->getString ();
	while(strstr(this->ystring,findMe) != nullptr && (strcmp(strstr(this->ystring,findMe), " ")) != 0 && strcmp(findMe,"") != 0){
		int toFindLen = strlen(findMe);
		int bytesToMove = strlen(strstr(this->ystring,findMe)) - toFindLen;
		returnMe++;
		/* this will find where the toFind string is inside of the ystring, then delete the word that was found
		by moving the data over the number of places that the length of toFind is. */
//		cout << "toFind: " << toFind << endl;
//		cout << "Destination: " << strstr(this->ystring,findMe) << endl;
//		cout << "Source: " << strstr(this->ystring, findMe) + strlen(findMe) << endl;
//		cout << "Number of Bytes: " << bytesToMove << endl;
//		cout << "******************" << endl;
		memmove (strstr (this->ystring, findMe), strstr (this->ystring, findMe) + strlen (findMe),
				 bytesToMove);
		subStrObj (0, this->length () - toFindLen);
		this->ylength = strlen (ystring) + 1;
	}
	return returnMe;
}

Stringy Stringy::substr (int index, int length) {
	int size = length+1;
	char * temp = new char[size];
	//double for loop, in which it will end at a specified length "i" in the string,
	//and starts at zero for the new temp string.
	for(int i = index, j = 0; j < size; i++, j++)
	{
		temp[j] = ystring[i];
	}
	//make sure the end of the c-string is null-terminated.
	if(temp[size-1] != '\0'){temp[size-1] = '\0';}
	return Stringy(temp);
}

/* reference:
 * https://www.cplusplus.com/forum/beginner/50062/
 * */
Stringy &operator+ (const Stringy &S1, const int num_Toadd) {
	int counter=0;
	int number = num_Toadd;
	// counter will be how many digits inside the number.
	while(number)
	{
		number = number/10;
		counter++;
	}
	int returnLen = S1.length () + counter;
	char* putMeInStringy = new char[returnLen];
	// put the elements of S1 into the new char
	for(int i = 0; i < S1.length() - 1; i++){
		putMeInStringy[i] = S1.getString ()[i];
	}
	char numberToAddToString[counter +1];
	stringstream strs;
	strs << num_Toadd;
	strs.getline(numberToAddToString,counter+1);
	for(int i = S1.length () -1, j= 0 ; i <returnLen - 1; i++, j++){
		putMeInStringy[i] = numberToAddToString[j];
	}
	putMeInStringy[returnLen - 1] = '\0';
	return * new Stringy(putMeInStringy);
}

void Stringy::setLength (int newLen)
	{
	this->ylength = newLen;
	}

char *Stringy::getString () const
	{
	return this-> ystring;
	}

