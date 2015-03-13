/*
  -------------------------------------------------------------------------
  Name: routines.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Various functions to work with strings.
  -------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include "routines.h"

using namespace std;

namespace heuron {

	vector<string> split(string input, const char delimiter) {
		vector<string> result;
		string current_substring("");
		for (string::iterator iter = input.begin(); iter != input.end(); ++iter) {
			if (*iter != delimiter) {
				current_substring.push_back(*iter);
			}
			else {
				result.push_back(current_substring);
				current_substring = "";
			}
		}
		if (current_substring != "") {
			result.push_back(current_substring);
		}
		return result;
	}

	string strip(string input, const char stripper) {
		string result("");
		string::iterator begin_iter = input.begin();
		string::iterator end_iter = input.end() - 1;
		for (; *begin_iter == stripper; ++begin_iter) {}
		for (; *end_iter == stripper; --end_iter) {}
		for (string::iterator iter = begin_iter; iter != end_iter + 1; ++iter) {
			result.push_back(*iter);
		}
		return result;
	}

}
