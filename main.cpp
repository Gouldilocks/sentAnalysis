#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stringy.h"
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int findSent(Stringy*find){
	// whole function will not execute if Stringy is empty.
	if (find->empty()) return 0;
	int returnMe = 0;
for(int i = 0; i < find->length (); i++){
	if (i == find-> length() - 1) return i;
	else{
		// will only return true if ",p or ",|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')|| find->getString ()[i] == '\t' || find-> getString ()[i] == '|')
		if (find->getString ()[i] == '"'  && (find->getString ()[i+1] == ','|| find->getString ()[i+1] == '\t' || find-> getString ()[i+1] == '|') && (find->getString ()[i+2] == 'p' || find-> getString ()[i+2] == 'n'))	{
			for(int x = 0; x < 8; x++){
				cout << find->getString ()[x+i+2];
			}
			cout << endl;
			return i+2;
		}
	}
}
return returnMe;
}
int main() {

ofstream outputMe("blackList");
ifstream testhim("fullData.csv");
char temp[1000000];
vector<Stringy *> stringThing;


for(int i = 0; i < 200; i++) {
	//cout << i << endl;
	testhim.getline(temp,100000);
	//cout << temp << endl;
	auto* testStringy = new Stringy(temp);
	stringThing.push_back (testStringy);
}
for(Stringy* ok: stringThing){
	//findSent (ok);
}

    return 0;
}

