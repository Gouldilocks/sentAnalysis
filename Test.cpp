//
// Created by Christian Gould on 9/6/20.
//
#include "catch.hpp"
#include "Stringy.h"
#include <sstream>

TEST_CASE("Stringy thingy", "[Stringy]") {
	Stringy s[11];
	s[ 0 ] = Stringy ("testString");
	s[ 1 ] = Stringy ("a test string");
	s[ 2 ] = Stringy ("");
	s[ 3 ] = Stringy ("THIS IS AN UPPERCASE STRING");
	s[ 4 ] = Stringy ("this is an uppercase string");
	s[ 5 ] = Stringy ("\n");
	s[ 6 ] = Stringy ("");
	s[ 7 ] = Stringy ("  split  split  split  ");
	s[ 8 ] = Stringy ("                          ");
	s[ 9 ] = Stringy ("testString");
	s[ 10 ] = Stringy ("the number is: ");

	SECTION ("Stringy pointer deep copy constructor") {
		Stringy* point = new Stringy("yes");
		Stringy deepcpy(point);
		REQUIRE(*point == deepcpy);
		REQUIRE(point != &deepcpy);
	} SECTION("Stringy size limit constructor") {
		Stringy sizedthree("okay", 3);
		REQUIRE(sizedthree == "oka");
		Stringy sizedten("onetwothree",10);
		REQUIRE(sizedten == "onetwothre");
	} SECTION("firstThree function") {
		Stringy first("yeeeeeees");
		Stringy second("yees");
		REQUIRE(first.firstThree(second));
		Stringy third("no");
		REQUIRE (!first.firstThree(third));
	} SECTION("wordInsideIt function") {
		Stringy wordIn("This is the end");
		Stringy findMe("end");
		REQUIRE(wordIn.wordInsideIt(findMe));
		REQUIRE(!wordIn.wordInsideIt(Stringy("yaya")));
	} SECTION("findAndDelete") {
		Stringy deleteor("This will be deleted soon");
		deleteor.findAndDelete("deleted");
		REQUIRE(deleteor == "This will be  soon");
		Stringy deletetwice("Nah fam bud");
		deletetwice.findAndDelete("fam");
		REQUIRE (deletetwice == "Nah  bud");
	} SECTION("at function") {
		Stringy ab("abcdefg");
		REQUIRE(ab.at(2) == 'c');
		REQUIRE(ab.at(3) == 'd');
		REQUIRE(ab.at(5) == 'f');
	} SECTION("Empty function") {
		Stringy emp("");
		Stringy notEmp("yeeeee");
		REQUIRE(emp.empty());
		REQUIRE(!notEmp.empty());
	} SECTION("length function") {
		REQUIRE(s[9].length() == 11);
		REQUIRE(s[2].length() == 1);
	} SECTION("charLength function") {
		CHECK(s[ 9 ].charLength () == 10);
		CHECK(s[ 2 ].charLength () == 0);
		CHECK(s[ 8 ].charLength () == 26);
		CHECK(s[ 3 ].charLength () == 27);
	} SECTION("Tokenize Stringy function") {
		Stringy tokenizeMEEeEe ("one two three a four b five");
		Stringy tokenizeMEEeEe2 ("one two three a four b five");
		vector<Stringy *> imSameFirst = { new Stringy ("one"), new Stringy ("two"), new Stringy ("three"),
										  new Stringy ("four"), new Stringy ("five") };
		vector<Stringy *> imSameSecond = { new Stringy ("one"), new Stringy ("two"), new Stringy ("thr"),
										   new Stringy ("fou"), new Stringy ("fiv") };
		// normal operation
		int counter = 0;
		for (Stringy *currString : *tokenizeMEEeEe.tokenizeStringy (' ', Stringy ("a b"))) {
			CHECK(*currString == *imSameFirst[ counter ]);
			counter++;
		}
		// overloaded with word size limit
		counter = 0;
		for (Stringy *currString : *tokenizeMEEeEe2.tokenizeStringy (' ', Stringy ("a b"), 3)) {
			CHECK(*currString == *imSameSecond[ counter ]);
			counter++;
		}
		SECTION("SubstringObj function") {
			// subString of object itself
			s[ 0 ].subStrObj (0, 5);
			s[ 4 ].subStrObj (0, 4);
			CHECK(s[ 0 ] == "testS");
			CHECK(s[ 4 ] == "this");
			s[ 4 ].subStrObj (1, 3);
			CHECK(s[ 4 ] == "his");
		} SECTION("Substring function") {
			Stringy sub ("I can't imagine having free time anymore");
			REQUIRE(sub.substr (0, 7) == "I can't");
		} SECTION("setString function") {
			Stringy setty ("set this to not this");
			setty.setString ("this is not that ^^^^");
		} SECTION("getString function") {
			CHECK(strcmp (s[ 0 ].getString (), "testString") == 0);
			CHECK(strcmp (s[ 9 ].getString (), s[ 0 ].getString ()) == 0);
			CHECK(strcmp (s[ 2 ].getString (), "") == 0);
		} SECTION("find_Number_Inside") {
			Stringy findInsideTest ("I I I I I I am a test");
			REQUIRE(findInsideTest.find_Number_Inside (new Stringy ("I")) == 6);
		} SECTION("Clean function") {
			Stringy one ("this's a test %$ ok.. yessir");
			one.clean ();
			REQUIRE(one == "this s a test    ok   yessir");
		} SECTION("findSentiment") {
			Stringy negSentiment ("\"this is negative\",negative");
			Stringy posSentiment ("\"this is positive\",positive");
			REQUIRE(!negSentiment.findSentiment (negSentiment));
			REQUIRE(posSentiment.findSentiment (posSentiment));
		} SECTION("Insertion operators") {
			stringstream ss;
			// << operator
			Stringy streamMe("I am a stream");
			ss << streamMe;
			// >> operator
			Stringy output;
			ss >> output;
			REQUIRE(output == "I");
			ss >> output;
			REQUIRE(output == "am");
			ss >> output;
			REQUIRE(output == "a");
			ss >> output;
			REQUIRE(output == "stream");
		} SECTION("Assignment operators") {
			Stringy str;
			str = "a test string";
			CHECK(str == s[ 1 ]);
			str = Stringy ("testString");
			CHECK(str == s[ 0 ]);
			str = "";
			CHECK(str == s[ 6 ]);
			str = Stringy ("\n");
			CHECK(str == s[ 5 ]);
		} SECTION("Equality operators") {
			CHECK(s[ 0 ] == Stringy ("testString"));
			CHECK(s[ 0 ] == s[ 9 ]);
			CHECK(s[ 2 ] == "");
			CHECK(s[ 1 ] == "a test string");
			CHECK(!(s[ 3 ] == s[ 4 ]));
		} SECTION("Addition operator") {
			// adding two strings
			CHECK(Stringy ("testStringtestString") == s[ 0 ] + s[ 9 ]);
			CHECK(s[ 6 ] + s[ 6 ] == "");
			CHECK(s[ 5 ] + s[ 6 ] == Stringy ("\n"));
			CHECK(s[ 0 ] + s[ 1 ] + s[ 2 ] == "testStringa test string");

			// overloaded with char*
			s[ 10 ].setString ("finish ");
			CHECK(s[ 10 ] + "me" == "finish me");
			s[ 10 ].setString ("adding a char* to it is");
			CHECK(s[ 10 ] + " fun" == "adding a char* to it is fun");
			s[ 10 ].setString ("newline here: ");
			CHECK(s[ 10 ] + "\n" == "newline here: \n");

			// overloaded with number
			CHECK(s[ 10 ] + 10 == "newline here: 10");
			s[ 10 ].setString ("the number is: ");
			CHECK(s[ 10 ] + 152 == "the number is: 152");
			s[ 10 ].setString ("the number is: ");
			CHECK(s[ 10 ] + 2000000 == "the number is: 2000000");
		} SECTION("Plus equals operator") {
			Stringy plus ("Plus");
			Stringy equals ("equals");
			plus += equals;
			CHECK(plus == "Plusequals");
			plus += equals;
			CHECK(plus == "Plusequalsequals");

		} SECTION("Less than operator") {
			Stringy less ("ZZZZZZ");
			Stringy more ("BBBBB");
			Stringy least ("AAAA");
			CHECK(less < more);
			CHECK(least < less);
			CHECK(least < more);
		}
	}
}