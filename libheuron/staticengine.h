/*
  -------------------------------------------------------------------------
  Name: staticengine.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module implements static heuristic engine.
  -------------------------------------------------------------------------
*/

namespace heuron {
    
    class StaticEngine {
	/*
	  
	 */
    private:
    public:
	StaticEngine();
	int search_in_file();
	int search_in_memo();
	int search_in_string();
    };

}
