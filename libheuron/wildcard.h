/*
  -------------------------------------------------------------------------
  Name: wildcard.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Simple wildcard parser.
  -------------------------------------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

namespace heuron {

    enum WILDCARD_TYPE {
	BINARY,
	STRING
    };
    
    class Wildcard {
    /*
      This class provides an [API] for generic wildcards
     */
    private:
	WILDCARD_TYPE type;
	string wildcard;
	vector<int> charater_gaps;
	// Will be implemented later
	int mismatch;
    public:
	Wildcard(string wildcard_string);
	Wildcard(WILDCARD_TYPE type, string wildcard, vector<int> charater_gaps);
    };
}
