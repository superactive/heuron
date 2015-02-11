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
    public:
		SearchEngine() = 0;
		int search_in_file();
		int search_in_memo();
		int search_in_string();
    };

	class SimpleSearchEngine {
	/*
	  Search engine which implements primitive substring search
	 */
	private:
	public:

	};

}
