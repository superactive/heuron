/*
  -------------------------------------------------------------------------
  Name: searchengine.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module implements various search engines.
  -------------------------------------------------------------------------
*/

namespace heuron {

    MAX_LEN = 65536;
    
    int SimpleSearchEngine::search_in_file(std::ifstream is) {
	file_string = std::string("");
	is.readsome(file_string, MAX_LEN);
	return search_in_string(file_string);
    }

    int SimpleSearchEngine::search_in_string(string target_string) {
	for (map::iterator iter = this->db_handler.begin(); i != this->db_handler.end(); ++i) {
	    if (match_wildcard(target_string, *iter) == 1) {
		return 1;
	    }
	}
	return 0;
    }

    int SimpleSearchEngine::match_wildcard(string target_string, Wildcard wildcard) {
	// TODO: add charater gaps support
	string::iterator wildcard_iter = wildcard.wildcard.begin(); 
	int wildcard_size = wildcard.wildcard.size(); 
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
