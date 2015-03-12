/*
  -------------------------------------------------------------------------
  Name: wildcard.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Simple wildcard parser.
  -------------------------------------------------------------------------
*/

using namespace std;

namespace heuron {

    Wildcard::Wildcard(string wildcard_string) {
	
    }

    Wildcard::Wildcard(WILDCARD_TYPE type, string wildcard, vector<int> charater_gaps) {

    }

    Wildcard Wildcard::_parse(string wildcard_string) {
	WILDCARD_TYPE type;
	vector<int> charater_gaps;
	string wildcard("");
	// TODO: remove iterator
	string::iterator iter = wildcard_string.begin();
	switch (*iter) {
	case '[':
	    type = WILDCARD_TYPE.BINARY;
	    break;
	case '<':
	    type = WILDCARD_TYPE.STRING;
	    break;
	case default:
	    // Should throw an exception
	    break;
	}
	string signature = wildcard_string.substr(1, wildcard_string.end() - wildcard_string.begin() - 1);
	bytes = signature.split(' ');
	for (int i = 0; i < bytes.len(); ++i) {
	    b = bytes[i];
	    if (b == "??") {
		charater_gaps.push_back(i);
		wildcard.push_back(0);
	    }
	    else {
		// TODO: convert to function
		// 30 - 39; 48d
		// 41 - 46; 65d
		char current_char = 0;
		if (b[0] >= 0x30 && b[0] <= 0x39) {
		    current_char += (b[0] - 0x30) * 16;
		}
		if (b[0] >= 0x41 && b[0] <= 0x46) {
		    current_char += (b[0] - 0x41) * 16;
		}
		if (b[1] >= 0x30 && b[1] <= 0x39) {
		    current_char += (b[1] - 0x30);
		}
		if (b[1] >= 0x41 && b[1] <= 0x46) {
		    current_char += (b[1] - 0x41);
		}
		wildcard.push_back(current_char);
	    }
	}
	result = new Wildcard(type, wildcard, charater_gaps);
	return result;
    }
    
}
