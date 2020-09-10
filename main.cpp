#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include <vector>
#include "machine.h"
using namespace std;
// function which returns the index of the given stringy where the beginning of the sentiment starts.
int main(int argc, char** argv) {
	//Catch :: Session().run();
// todo: make all words capital, as it treats them as different
	ifstream training_Data("fullData.csv");
	ofstream outPut("outPut01.txt");
	auto* newMachine = new machine();
	newMachine->jumpStart (training_Data,outPut);
	cout << "Done" << endl;
    return 0;
}
/* CATCH things
 * #define CATCH_CONFIG_RUN
 * #include "catch.hpp"
 *int main(int argc, char** argv)
 * no command line, catch
 * if arguments given, then run my main
 *
 * make a tests.cpp file
 * #include catch.hpp
 *
 * TEST_CASE("Integer Wrapper Test Case"){
 * integer a;
 * integer b(3);
 * integer c(4);
 * SECTION("Checking GetVal..."){
 * 	REQUIRE // means that if your tests are going through, and you get a require that does not go through, it will automatically stop
 * 	CHECK // means that it will only make note of when a bad thing happens.
 * CHECK ( b.getVal() == 3 )
 *
 * if you do not create a operator or constructor, then
 * }
 *
 *
 *
 *
 * }
 *
 * */

