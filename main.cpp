#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stringy.h"
#include "review.h"
#include "machine.h"
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int main() {

//auto* newMachine = new machine();
review* reviewMan = new review(new Stringy("Hello negative this is my positive negative string hellow\",positive"), 1);
reviewMan->cleanUp();
cout << *reviewMan->getSpaceSeparatedWords() << endl;
    return 0;
}

