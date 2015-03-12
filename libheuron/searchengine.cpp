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
    
    int SimpleSearchEngine::search_in_file(std::ifstream is, Wildcard wildcard) {
	file_string = std::string("");
	is.readsome(file_string, MAX_LEN);
	return search_in_string(file_string);
    }

    int SimpleSearchEngine::search_in_string(string target_string, Wildcard wildcard) {

    }
    
}
