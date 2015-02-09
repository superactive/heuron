/*
  -------------------------------------------------------------------------
  Name: dbhandler.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module consists routines to work with heuristic signatures database.
  -------------------------------------------------------------------------
*/

namespace heuron {
    
    class HeuristicSignature {
	/*
	  This class provides an [API] for heuristic signatures
	 */
    private:
	// TODO: Now it is string, later it will be something like:
	// REGEXP signature;
	string signature;
	map<string, int> classified_threats;
    public:
	HeuristicSignature(string signature,
			   map<string, int> classified_threats);
	int get_signature();
	int set_signature(string signature);
	int add_threat(string type, int threat);
	int change_threat(string type, int new_threat);
    };

    class DatabaseHandler {
	/*
	  Heuristic database handler
	 */
    private:
	HeuristicSignature *database;
    public:
	int load_database();
	int get_database();
	int read_signature();
    };
}
