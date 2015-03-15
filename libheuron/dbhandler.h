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

using namespace std;

namespace heuron {
    
    class HeuristicSignature {
	/*
	  This class provides an [API] for heuristic signatures
	 */
    private:
	int id;
	// TODO: Now it is string, later it will be something like:
	// REGEXP signature;
	string signature;
	map<string, int> classified_threats;
    public:
	HeuristicSignature(string signature,
			   map<string, int> classified_threats);
	int get_id();
	void set_id(int id);
	string get_signature();
	void set_signature(std::string signature);
	// Will be implemented later
	void add_threat(string type, int threat);
	void change_threat(string type, int new_threat);
	int get_threat(string threat_type);
    };

    class DatabaseHandler {
	/*
	  Heuristic database handler
	  TODO: Make iterator
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
