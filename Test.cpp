//
// Created by loggityloglog on 9/6/20.
//
#include "catch.hpp"
#include "Stringy.h"
#include "review.h"
#include "testerReview.h"

TEST_CASE("Stringy thingy", "[Stringy]"){
Stringy s[10];
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

SECTION("Equality operators"){
REQUIRE(s[0] == Stringy("testString"));
REQUIRE(s[0] == s[9]);
REQUIRE(s[2] == "");
REQUIRE(s[1] == "a test string");
REQUIRE(!(s[3] == s[4]));
}

SECTION("Assignment operators"){
Stringy str;
str = "a test string";
REQUIRE(str == s[1]);
str = Stringy("testString");
REQUIRE(str == s[0]);
str = "";
REQUIRE(str == s[6]);
str = Stringy("\n");
REQUIRE(str == s[5]);
}

SECTION("Addition operator"){
REQUIRE(Stringy("testStringtestString") == s[0]+s[9]);
REQUIRE(s[6] + s[6] == "");
REQUIRE(s[5] + s[6] == Stringy("\n"));
REQUIRE(s[0] + s[1] + s[2] == "testStringa test string");
}

//SECTION("Greater than operator"){
//REQUIRE(s[0] > s[1]);
//REQUIRE(s[4] > s[3]);
//REQUIRE(s[9] > s[6]);
//REQUIRE(s[7] > s[6]);
//}
//
//SECTION("[] Operator"){
//REQUIRE(s[0][1] == 'e');
//REQUIRE(s[4][4] == ' ');
//REQUIRE(s[6][0] == 0);
//}

SECTION("getLength function"){
REQUIRE(s[9].charLength() == 10);
REQUIRE(s[2].charLength() == 0);
REQUIRE(s[8].charLength() == 26);
REQUIRE(s[3].charLength() == 27);
}

SECTION("Substring function"){
	s[0].substr(0,5);
	s[4].substr(0,4);
REQUIRE(s[0] == "testS");
REQUIRE(s[4] == "this");
	s[4].substr(1,3);
REQUIRE(s[4] == "his");
}

SECTION("c_str function"){
		REQUIRE(strcmp(s[0].getString(), "testString") == 0);
		REQUIRE(strcmp(s[9].getString(), s[0].getString()) == 0);
		REQUIRE(strcmp(s[2].getString(), "") == 0);
	}
}
TEST_CASE("Review Class", "[review]"){
	Stringy negString("This is a review which is negative\",negative");
	Stringy posString("This is a review which is positive\",positive");
	Stringy testString("This is a tester review of spaced");
	Stringy blackList ("spaced"); // this is the blacklist;
	Stringy testSpaced("This is a review which is ");
	Stringy* negStringp = new Stringy(negString);
	Stringy* poStringp = new Stringy(posString);
	review negRev(negStringp, 1);
	review posRev(poStringp, 2);
	SECTION("Getters and Setters"){
		REQUIRE (!negRev.getSentiment());
		REQUIRE (posRev.getSentiment());
		negRev.setSentiment( true );
		REQUIRE (negRev.getSentiment ());
		negRev.setSentiment(false);
		REQUIRE (!negRev.getSentiment ());
		REQUIRE(*negRev.getTotal() == testSpaced);
		Stringy* testy = new Stringy(testString);
		posRev.setSpaceSeparatedWords(testy);
		REQUIRE(posRev.getSpaceSeparatedWords() == testString);
		negRev.setTotal(testy);
		REQUIRE(*negRev.getTotal() == testString);
		negRev.setRow(2);
		posRev.setRow(1);
		REQUIRE (negRev.getRow() == 2);
		REQUIRE (posRev.getRow() == 1);
	}
}
// subclass of review
TEST_CASE("testerReview Class", "[testerReview]"){
	Stringy negString("This is a review which is negative\",negative");
	Stringy posString("This is a review which is positive\",positive");
	Stringy testString("This is a tester review of spaced");
	Stringy blackList ("spaced"); // this is the blacklist;
	Stringy testSpaced("This is a review which is ");
	testerReview negRev(&negString, 1);
	testerReview posRev(&posString, 2);
	SECTION("Getters and Setters"){
		REQUIRE (!negRev.getSentiment());
		REQUIRE (posRev.getSentiment());
		negRev.setSentiment( true );
		REQUIRE (negRev.getSentiment ());
		negRev.setSentiment(false);
		REQUIRE (!negRev.getSentiment ());
		REQUIRE(*negRev.getTotal() == testSpaced);
		posRev.setSpaceSeparatedWords(&testString);
		REQUIRE(posRev.getSpaceSeparatedWords() == testString);
		negRev.setTotal(&testString);
		REQUIRE(*negRev.getTotal() == testString);
		negRev.setRow(2);
		posRev.setRow(1);
		REQUIRE (negRev.getRow() == 2);
		REQUIRE (posRev.getRow() == 1);
	}
	SECTION ("Getters and Setters from testerReview"){
	posRev.setExpectedOutput(false);
	REQUIRE(!posRev.getExpectedOutput());
	posRev.setExpectedOutput(true);
	REQUIRE(posRev.getExpectedOutput());
	negRev.setPosWords(new int(2));
	REQUIRE(*negRev.getPosWords() == 2);
	negRev.setNegWords(new int(2));
	REQUIRE(*negRev.getNegWords() == 2);
	negRev.addToNegWords(1);
	REQUIRE(*negRev.getNegWords() == 3);
	negRev.addToPosWords(1);
	REQUIRE(*negRev.getPosWords() == 3);
	}
}