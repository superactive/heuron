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
#include <vector>
#include <map>
#include"dbhandler.h"
#include"routines.h"

using namespace std;
    
namespace heuron {

    HeuristicSignature::HeuristicSignature(string signature,
					   map<string, int> classified_threats) {
	this->classified_threats = classified_threats;
    }

    int HeuristicSignature::get_id() {
	return this->id;
    }

    void HeuristicSignature::set_id(int id) {
	this->id = id;
    }
    
    string HeuristicSignature::get_signature() {
	return this->signature;
    }
    
    void HeuristicSignature::set_signature(string signature) {
	this->signature = signature;
    }
    
    void HeuristicSignature::add_threat(string type, int threat) {
	/* Will be implemented later */
    }
    
    void HeuristicSignature::change_threat(string type, int new_threat) {
	/* Will be implemented later */
    }
        
    
    void DatabaseHandler::load_database(ifstream is) {
	std::map<int, HeuristicSignature> temp_database();
	int id = 0;
	if (is.is_open()) {
	    while (is.good()) {
		string signature_string("");
		getline(is, signature_string);
		HeuristicSignature signature = parse_signature(signature_string);
		this->database.insert(std::pair<int, HeuristicSignature>(id, signature));
	    }
	}
    }
    
    HeuristicSignature DatabaseHandler::read_signature(int id) {
	return this->database[id];
    }

    HeuristicSignature DatabaseHandler::parse_signature(string signature) {
	string::iterator iter = signature.begin();
	string hash("");
	string name("");
	for (; *iter != ' '; ++iter) {
	    hash.push_back(*iter);
	}
	iter++; // Skip ' '
	for (; *iter != ' '; ++iter) {
	    name.push_back(*iter);
	}
	iter++; // Skip ' '
	iter++; // Skip '{'
	string::iterator end_iter = signature.end() - 2; // Pre-last charater of string
	string parameters_string("");
	signature.copy(parameters_string, iter, end_iter - iter);
	string wildcard("");
	map<string, int> classified_threats();
	vector<string> parameters = split(parameters_string, ';');
	for (int i = 0; i < parameters.size(); ++i) {
	    vector<string> parsed_parameters = split(parameters[i], '=');
	    if (parsed_parameters[0] == "wildcard") {
		wildcard = parsed_parameters[1];
	    }
	    if (parsed_parameters[0] == "type") {
		vector<string> types = split(parsed_parameters[i], ',');
		for (int j = 0; j < types.size(); ++j) {
		    vector<string> parsed_type = split(types[j], ':');
		    int type_threat = std::stoi(parsed_type[1], nullptr, 10);
		    classified_threats.insert(pair<string, int>(parsed_type[0], type_threat));
		}
	    }
	}
	return HeuristicSignature(wildcard, classified_threats);
    }

}	
