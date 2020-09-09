//
// Created by loggityloglog on 9/6/20.
//
#include "catch.hpp"
#include "Stringy.h"
#include "review.h"
#include "testerReview.h"

TEST_CASE("Stringy thingy", "[Stringy]"){
Stringy s[11];
s[0] = Stringy("testString");
s[1] = Stringy("a test string");
s[2] = Stringy("");
s[3] = Stringy("THIS IS AN UPPERCASE STRING");
s[4] = Stringy("this is an uppercase string");
s[5] = Stringy("\n");
s[6] = Stringy("");
s[7] = Stringy("  split  split  split  ");
s[8] = Stringy("                          ");
s[9] = Stringy("testString");
s[10] = Stringy("the number is: ");

SECTION("Equality operators"){
CHECK(s[0] == Stringy("testString"));
CHECK(s[0] == s[9]);
CHECK(s[2] == "");
CHECK(s[1] == "a test string");
CHECK(!(s[3] == s[4]));
}

SECTION("Assignment operators"){
Stringy str;
str = "a test string";
CHECK(str == s[1]);
str = Stringy("testString");
CHECK(str == s[0]);
str = "";
CHECK(str == s[6]);
str = Stringy("\n");
CHECK(str == s[5]);
}

SECTION("Addition operator"){
CHECK(Stringy("testStringtestString") == s[0]+s[9]);
CHECK(s[6] + s[6] == "");
CHECK(s[5] + s[6] == Stringy("\n"));
CHECK(s[0] + s[1] + s[2] == "testStringa test string");

// overloaded with number
CHECK(s[10] + 10 == "the number is: 10");
s[10].setString("the number is: ");
CHECK(s[10] + 15 == "the number is: 15");
s[10].setString("the number is: ");
CHECK(s[10] + 2000000 == "the number is: 2000000");

// overloaded with char*
s[10].setString("finish ");
CHECK(s[10] + "me" == "finish me");
s[10].setString("adding a char* to it is");
CHECK(s[10] + " fun" == "adding a char* to it is fun");
s[10].setString("newline here: ");
CHECK(s[10] + "\n" == "newline here: \n");
}

//SECTION("Greater than operator"){
//CHECK(s[0] > s[1]);
//CHECK(s[4] > s[3]);
//CHECK(s[9] > s[6]);
//CHECK(s[7] > s[6]);
//}
//
//SECTION("[] Operator"){
//CHECK(s[0][1] == 'e');
//CHECK(s[4][4] == ' ');
//CHECK(s[6][0] == 0);
//}

SECTION("charLength function"){
CHECK(s[9].charLength() == 10);
CHECK(s[2].charLength() == 0);
CHECK(s[8].charLength() == 26);
CHECK(s[3].charLength() == 27);
}

SECTION("Substring function"){
		s[ 0 ].subStrObj (0, 5);
		s[ 4 ].subStrObj (0, 4);
CHECK(s[0] == "testS");
CHECK(s[4] == "this");
		s[ 4 ].subStrObj (1, 3);
CHECK(s[4] == "his");
}

SECTION("c_str function"){
		CHECK(strcmp(s[0].getString(), "testString") == 0);
		CHECK(strcmp(s[9].getString(), s[0].getString()) == 0);
		CHECK(strcmp(s[2].getString(), "") == 0);
	}
}
TEST_CASE("Review Class", "[review]"){
	Stringy negString("This is a review which is negative\",negative");
	Stringy posString("This is a review which is positive\",positive");
	Stringy testString("This is a tester review of spaced");
	Stringy blackList ("spaced"); // this is the blacklist;
	Stringy testSpaced("This is a review which is ");
	Stringy* negStringP = new Stringy(negString);
	Stringy* poStringP = new Stringy(posString);
	review negRev(negStringP, 1);
	review posRev(poStringP, 2);
	SECTION("Getters and Setters"){
		CHECK (!negRev.getSentiment());
		CHECK (posRev.getSentiment());
		negRev.setSentiment(true);
		CHECK (negRev.getSentiment ());
		negRev.setSentiment(false);
		CHECK (!negRev.getSentiment ());
		CHECK(*negRev.getTotal() == testSpaced);
		Stringy* testy = new Stringy(testString);
		posRev.setSpaceSeparatedWords(testy);
		CHECK(posRev.getSpaceSeparatedWords() == testString);
		negRev.setTotal(testy);
		CHECK(*negRev.getTotal() == testString);
		negRev.setRow(2);
		posRev.setRow(1);
		CHECK (negRev.getRow() == 2);
		CHECK (posRev.getRow() == 1);
	}
}
// subclass of review
TEST_CASE("testerReview Class", "[testerReview]"){
	Stringy negString("This is a review which is negative\",negative");
	Stringy posString("This is a review which is positive\",positive");
	Stringy testString("This is a tester review of spaced");
	Stringy blackList ("spaced"); // this is the blacklist;
	Stringy testSpaced("This is a review which is ");
	Stringy* negStringP = new Stringy(negString);
	Stringy* poStringP = new Stringy(posString);
	testerReview negRev(negStringP, 1);
	testerReview posRev(poStringP, 2);
	SECTION("Getters and Setters"){
		CHECK (!negRev.getSentiment());
		CHECK (posRev.getSentiment());
		negRev.setSentiment(true);
		CHECK (negRev.getSentiment ());
		negRev.setSentiment(false);
		CHECK (!negRev.getSentiment ());
		CHECK(*negRev.getTotal() == testSpaced);
		Stringy* testy = new Stringy(testString);
		posRev.setSpaceSeparatedWords(testy);
		CHECK(posRev.getSpaceSeparatedWords() == testString);
		negRev.setTotal(testy);
		CHECK(*negRev.getTotal() == testString);
		negRev.setRow(2);
		posRev.setRow(1);
		CHECK (negRev.getRow() == 2);
		CHECK (posRev.getRow() == 1);
	}
	SECTION ("Getters and Setters from testerReview"){
	posRev.setExpectedOutput(false);
	CHECK(!posRev.getExpectedOutput());
	posRev.setExpectedOutput(true);
	CHECK(posRev.getExpectedOutput());
	negRev.setPosWords(new int(2));
	CHECK(*negRev.getPosWords() == 2);
	negRev.setNegWords(new int(2));
	CHECK(*negRev.getNegWords() == 2);
	negRev.addToNegWords(1);
	CHECK(*negRev.getNegWords() == 3);
	negRev.addToPosWords(1);
	CHECK(*negRev.getPosWords() == 3);
	}
}