/*
  -------------------------------------------------------------------------
  Name: searchengine.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module implements various search engines.
  -------------------------------------------------------------------------
*/

#include <string>
#include <fstream>
#include <map>
#include "searchengine.h"

using namespace std;

namespace heuron {

    int MAX_LEN = 8192;
    
    int SimpleSearchEngine::search_in_file(std::ifstream is) {
	char file_char_array[MAX_LEN];
	is.readsome(file_char_array, MAX_LEN);
	string file_string(file_char_array);
	return search_in_string(file_string);
    }

    int SimpleSearchEngine::search_in_string(std::string target_string) {
	iterator iter = this->db_handler.begin(); // FIXME
	for ( ;iter != this->db_handler.end(); ++iter) {
	    if (match_wildcard(target_string, *iter) == 1) {
		return 1;
	    }
	}
	return 0;
    }

    int SimpleSearchEngine::match_wildcard(string target_string, Wildcard wildcard) {
	// TODO: add charater gaps support
	string wildcard_string = wildcard.get_wildcard();
	string::iterator wildcard_iter = wildcard_string.begin();
	int wildcard_size = wildcard_string.size(); 
	int num_of_equal_chars = 0;
	for (string::iterator iter = target_string.begin(); iter != target_string.end(); ++iter) {
	    if (*iter == *wildcard_iter) {
		num_of_equal_chars++;
	    }
	    else {
		num_of_equal_chars = 0;
	    }
	    if (num_of_equal_chars == wildcard_size) {
		return 1;
	    }
	}
	return 0;
    }
    
}
