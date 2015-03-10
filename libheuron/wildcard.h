/*
  -------------------------------------------------------------------------
  Name: wildcard.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Simple wildcard parser.
  -------------------------------------------------------------------------
*/

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
	int[] charater_gaps;
	Wildcard _parse(string wildcard_string);
	// Will be implemented later
	int mismatch;
    public:
	Wildcard(string wildcard_string);
    };
}
