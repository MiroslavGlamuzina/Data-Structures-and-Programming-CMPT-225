/*
 * StringSet.h
 *
 *  Created on: Sep 14, 2015
 *      Author: Miroslav
 */

#ifndef STRINGSET_H_
#define STRINGSET_H_
#include <string>
#include <iostream>

class StringSet {

public:

	std::string* str_set;
	int MAX_SIZE = 4;

	StringSet();
	StringSet(const StringSet &);
	bool insert(std::string);
	bool remove(std::string);
	int find(std::string) const;
	int size() const;
	StringSet setunion(const StringSet &) const;
	StringSet intersection(const StringSet &) const;
	StringSet difference(const StringSet &) const;
	StringSet& operator=(const StringSet&) = delete;
	virtual ~StringSet();

private:

};
//static std::string* str_set;
static int current_size;
#endif /* STRINGSET_H_ */
