#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stringy.h"
#include "review.h"
#include "machine.h"
using namespace std;
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int main() {
// todo: make all words capital, as it treats them as different
/* blacklist almost works.
 * The issue is, blacklisted words will instead be blank,
 * dynamically allocated strings with nothing in them.*/
	ifstream testing_Data("testing_Data.csv");
	ifstream training_Data("training_Data.csv");
	auto* newMachine = new machine();
	newMachine->jumpStart (testing_Data,training_Data);
	cout << "Done" << endl;
//char yes[4] = "yes";
//word w1(yes);
//word w2(yes);
//if (w1 == w2){
//	cout << "yep" << endl;
//}
//else cout << "nope" << endl;
//Stringy* testMe = new Stringy("test It");
//testMe->findAndDelete ("test");
//testMe->findAndDelete ("It");
//char* okie;
//okie = testMe->getString ();
//word* wordUp = new word(okie);
//if (okie == NULL) cout << "ladies and gentlemen... we got him" << endl;
//else cout << "nope" << endl;
    return 0;
}

