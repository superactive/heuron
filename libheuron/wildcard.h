/*
  -------------------------------------------------------------------------
  Name: wildcard.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Simple wildcard parser.
  -------------------------------------------------------------------------
*/

namespace heuron {
    
    class Wildcard {
    /*
      This class provides an [API] for generic wildcards
     */
    private:
	string wildcard;
	int[] charater_gaps;
	// Will be implemented later
	int mismatch;
    public:
	Wildcard(string input_wildcard);
	int search(string target_string);
    };
}
