//============================================================================
// Name        : Assignment2_StringSet.cpp
// Author      : Miroslav Glamuzina
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "StringSet.h"
using namespace std;

/*CHECKLIST
 * ---------
 * insert - good
 * remove - good
 * find - good
 * size - good
 *
 *
 * */
int main() {
	cout << "Assignment 2 \n --------------------\n \n " << endl; // prints Assignment 2
	StringSet *ss = new StringSet();

	ss->insert("a");
	ss->insert("a");
	ss->remove("a");
	cout << "Search index : " << ss->find("a") << "\n" << endl;
	;

	ss->insert("b");
	ss->insert("c");
	ss->insert("d");
	ss->insert("e");
	ss->insert("f");

//	StringSet *ss2 = new StringSet(*ss);

//	ss2->setunion(StringSet);
//	ss2.insert("1");
//	ss2.insert("1");
//	ss2.insert("1");
//
//	ss->setunion(&ss2);

//	ss->insert("g");
//	ss->insert("h");
//	ss->insert("i");
//	ss->insert("j");
//	ss->insert("k");
//	ss->insert("l");
//	ss->insert("m");
//	ss->insert("n");
//	ss->insert("o");

	ss->remove("a");

	cout << ss->size() << endl;
	return 0;
}
