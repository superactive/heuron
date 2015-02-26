/*
  -------------------------------------------------------------------------
  Name: dbhandler.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module consists routines to work with heuristic signatures database.
  -------------------------------------------------------------------------
*/

#include <string>
#include"dbhandler.h"
    
namespace heuron {

    HeuristicSignature::HeuristicSignature(string signature,
					   map<string, int> classified_threats) {
	this->classified_threats = classified_threats;
    }

    int HeuristicSignature::get_id() {
	return this->id;
    }

    void HeuristicSignature::set_id() {
	this->id = id;
    
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
        
    
    void DatabaseHandler::load_database() {
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
	end_iter = signature.end() - 2; // Pre-last charater of string
	string parameters_string = string::copy(signature,
						iter - signature.begin(),
						end_iter - iter);
	string wildcard("");
	map<string, int> classified_threats();
	vector<string> parameters = split(parameters_string, ';');
	for (int i = 0; i < parameters.size(); ++i) {
	    vector<string> parsed_parameters = split(parameters[i], '=');
	    if (parsed_parameters[0] == "wildcard") {
		wildcard = parsed_parameters[1];
	    }
	    if (parsed_parameters[0] == "type") {
		types = split(parsed_parameters[i], ',');
		for (int j = 0; j < types.size(); ++j) {
		    parsed_type = split(types[j], ':');
		    classified_threats.insert(pair<string, int>(parsed_type[0],
								stoi(parsed_type[1], nullptr, 10));
		}
	    }
	}
	return HeuristicSignature(wildcard, classified_threats);
    }

}	
