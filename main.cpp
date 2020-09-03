#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stringy.h"
int findSent(Stringy*find){
for(int i = 0; i < find->length (); i++){
	// function will not excecute if the string is empty
	if (find->empty()){
		return 0;
		// this will only execute if the function has a string in it.
	} else {

	}
}
}
int main() {
//	Stringy* stringMan = new Stringy("Cor");
//	Stringy* strong = new Stringy("rect");
//	//stringMan->setString("Okay");
//Stringy* combined = new Stringy("Cor");
//cout << "Enter a c-String" << endl;
//cin >> *combined;
//cout << *combined << endl;
//cout << (*combined == *strong) << endl;
//cout << (*combined == *stringMan) << endl;
//		combined = (*stringMan + *strong);
//		*combined += *stringMan;
//		*combined += *strong;
//	cout << *stringMan << endl;
//	cout << *combined << endl;
//	cout << combined->length() << endl;
//	cout << "empty?: " << combined-> empty () << endl;
//	cout << combined->at(2) << endl;
//	cout << *combined->substr (2, 5);
//    std::cout << "Hello, World!" << std::endl;
//    std::ofstream fout("output01.txt");
//    fout << "Hello world!" << std::endl;
//    fout.close();
//delete stringMan;
//delete strong;
ofstream outputMe("testMe");
ifstream testhim("fullData.csv");
char temp[1000000];
vector<Stringy *> stringThing;


for(int i = 0; i < 200; i++) {
	cout << i << endl;
	testhim.getline(temp,100000);
	cout << temp << endl;
	auto* testStringy = new Stringy(temp);
	stringThing.push_back (testStringy);
}
for(Stringy* ok: stringThing){
	outputMe << *ok << endl;
}

    return 0;
}

