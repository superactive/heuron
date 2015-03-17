/*
  -------------------------------------------------------------------------
  Name: dbhandler.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module consists routines to work with heuristic signatures database.
  -------------------------------------------------------------------------
*/

#include <string>
#include <fstream>
#include <map>
#include "wildcard.h"

using namespace std;

namespace heuron {
    
    class HeuristicSignature {
	/*
	  This class provides an [API] for heuristic signatures
	 */
    private:
	int id;
	Wildcard signature_wildcard;
	map<string, int> classified_threats;
    public:
	HeuristicSignature(Wildcard signature_wildcard,
			   map<string, int> classified_threats);
	int get_id();
	void set_id(int id);
	Wildcard get_signature();
	void set_signature(Wildcard signature_wildcard);
	// Will be implemented later
	void add_threat(string type, int threat);
	void change_threat(string type, int new_threat);
	int get_threat(string threat_type);
    };

    class DatabaseHandler {
	/*
	  Heuristic database handler
	 */
    private:
	map<int, HeuristicSignature> database;
    public:
	void load_database(ifstream is);
	HeuristicSignature read_signature(int id);
	HeuristicSignature parse_signature(string signature);
	map<int, HeuristicSignature>::iterator begin();
	map<int, HeuristicSignature>::iterator end();
    };
}
