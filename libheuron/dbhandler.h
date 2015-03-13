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
	std::string signature;
	std::map<string, int> classified_threats;
    public:
	HeuristicSignature(std::string signature,
			   std::map<string, int> classified_threats);
	int get_id();
	void set_id(int id);
	string get_signature();
	void set_signature(std::string signature);
	// Will be implemented later
	void add_threat(std::string type, int threat);
	void change_threat(std::string type, int new_threat);
    };

    class DatabaseHandler {
	/*
	  Heuristic database handler
	  TODO: Make iterator
	 */
    private:
	std::map<int, HeuristicSignature> database;
    public:
	void load_database(std::ifstream is);
	HeuristicSignature read_signature(int id);
	HeuristicSignature parse_signature(std::string signature);
    };
}
