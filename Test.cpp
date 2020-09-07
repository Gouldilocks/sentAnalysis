//
// Created by loggityloglog on 9/6/20.
//
#include "catch.hpp"
#include "Stringy.h"
#include "review.h"

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
REQUIRE(s[9].length() == 10);
REQUIRE(s[2].length() == 0);
REQUIRE(s[8].length() == 26);
REQUIRE(s[3].length() == 27);
}

SECTION("Substring function"){
REQUIRE(*s[0].substr(0, 5) == "testS");
REQUIRE(*s[4].substr(0, 4) == "this");
REQUIRE(*s[4].substr(1, 3) == "his");
}

SECTION("c_str function"){
		REQUIRE(strcmp(s[0].getString(), "testString") == 0);
		REQUIRE(strcmp(s[9].getString(), s[0].getString()) == 0);
		REQUIRE(strcmp(s[2].getString(), "") == 0);
	}
}
TEST_CASE("Review Class", "[review]"){
	review negRev(new Stringy("This is a review which is negative\",negative"), 1);
	review PosRev(new Stringy("This is a positive review which happens to be positive\",positive"),2);
	SECTION("Getters and Setters"){
		REQUIRE(negRev.getTotal() == new Stringy("This is a review which is negative\",negative"));
		negRev.setTotal(new Stringy("This is the new Total"));
		REQUIRE(negRev.getTotal() == new Stringy("This is the new Total"));

	}
}