/*
  -------------------------------------------------------------------------
  Name: searchengine.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module implements various search engines.
  -------------------------------------------------------------------------
*/

namespace heuron {
    
    class SearchEngine {
	/*
	  Abstract class for generic search engines
	 */
    private:
	DatabaseHandler db_handler;
    public:
	SearchEngine();
	virtual int search_in_file(std::ifstream is) = 0;
	//virtual int search_in_memo() = 0;
	virtual int search_in_string(string target_string) = 0;
    };

    class SimpleSearchEngine {
    /*
      Search engine which implements primitive substring search
     */
    private:
    public:
	int search_in_file(std::ifstream is);
	int search_in_string(string target_string);
	int match_wildcard(string target_string, Wildcard wildcard);
    };

}
