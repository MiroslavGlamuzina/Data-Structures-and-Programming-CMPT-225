/*
 * StringSet.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: Miroslav
 */

#include "StringSet.h"
#include <string>
#include <iostream>

StringSet::StringSet() {
	current_size = 0;
	str_set = new std::string[MAX_SIZE];
}

StringSet::StringSet(const StringSet &str_set_par) {
	current_size = str_set_par.size();
	MAX_SIZE = str_set_par.MAX_SIZE;
	str_set = new std::string[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; ++i) {
		str_set[i] = str_set_par.str_set[i];
	}
}

bool StringSet::insert(std::string s) {
	if (current_size < MAX_SIZE) {
		current_size++;
		std::string *str_set_temp = new std::string[current_size];
		for (int i = 0; i < current_size - 1; i++) {
			str_set_temp[i] = str_set[i];
			if (s.compare(str_set_temp[i]) == 0) {
				std::cout << "DUPLICATE ENTRY.... Not Inserting" << std::endl;
				current_size--;
				return false;
			}
		}
		str_set_temp[current_size - 1] = s;
		str_set = str_set_temp;

		//testing
		std::cout << "inserted Row count " << current_size << std::endl;
		for (int i = 0; i < current_size; i++) {
			std::cout << str_set[i] << std::endl;
		}
		std::cout << "\n" << std::endl;
		return true;
	}
	//UPDATE ARRAY AND INSERT
	else {
		for (int i = 0; i < current_size; i++) {
			if (s.compare(str_set[i]) == 0) {
				std::cout
						<< "[OVER MAX VALUE] DUPLICATE ENTRY.... Not Inserting"
						<< std::endl;
				return false;
			}
		}
		//UPDATE THE ARRAY
		std::string *str_set_temp = new std::string[current_size * 2];
		MAX_SIZE = MAX_SIZE * 2;
		for (int i = 0; i < current_size; i++) {
			str_set_temp[i] = str_set[i];
			std::cout << "DEBUG value : " << str_set[i] << std::endl;
		}
		str_set = str_set_temp;
		StringSet::insert(s);
		return true;
	}

	std::cout << "NO ITEMS INSERTED!" << std::endl;
	return false;
}

bool StringSet::remove(std::string s) {
	bool contains = false;
	for (int i = 0; i < current_size; i++) {
		if (s.compare(str_set[i]) == 0) {
			contains = true;
		}
	}
	if (contains) {
		std::cout << "There contains an element. . . " << std::endl;
		std::cout << "Removing string " << s << ". . ." << std::endl;

		current_size--;
		std::string* temp = new std::string[current_size];
		int counter = 0;
		for (int i = 0; i < current_size; i++) {
			if (s.compare(str_set[i]) != 0) {
				temp[counter] = str_set[i];
				counter++;
			}
		}
		str_set = temp;

//DEBUG
//		for (int i = 0; i < current_size; i++) {
//			std::cout << "Index[" << i << "] " << str_set[i] << std::endl;
//		}
		return true;
	}
	return false;
}

int StringSet::find(std::string s) const {
	for (int i = 0; i < current_size; i++) {
		if (s.compare(str_set[i]) == 0) {
			return i;
		}
	}
	return -1;
}

int StringSet::size() const {
	return current_size;
}

StringSet StringSet::setunion(const StringSet &str_set_par) const {
	StringSet result;
	for (int i = 0; i < MAX_SIZE; ++i) {
		result.insert(str_set[i]);
		result.insert(str_set_par.str_set[i]);
	}
	return result;
}
//
//StringSet StringSet::intersection(const StringSet &) const{
//
//	return 0 ;
//}
//
//StringSet StringSet::difference(const StringSet &) const{
//
//	return 0;
//}

StringSet::~StringSet() {

}

