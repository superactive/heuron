/*
  -------------------------------------------------------------------------
  Name: routines.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Various functions to work with strings.
  -------------------------------------------------------------------------
*/

#include <vector>

using namespace std;

namespace heuron {

	vector<string> split(string input, const char delimiter);
	string strip(string input, const char stripper);

}
