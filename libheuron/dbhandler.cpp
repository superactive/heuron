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

    HeuristicSignature::HeuristicSignature(Wildcard signature_wildcard,
					   map<string, int> classified_threats) {
	this->signature_wildcard = signature_wildcard;
	this->classified_threats = classified_threats;
    }

    int HeuristicSignature::get_id() {
	return this->id;
    }

    void HeuristicSignature::set_id(int id) {
	this->id = id;
    }
    
    Wildcard HeuristicSignature::get_signature() {
	return this->signature_wildcard;
    }
    
    void HeuristicSignature::set_signature(Wildcard signature_wildcard) {
	this->signature_wildcard = signature_wildcard;
    }
    
    int HeuristicSignature::get_threat(string threat_type) {
	// FIXME: Unsafe, check threat containment
	return this->classified_threats[threat_type];
    }
    
    void HeuristicSignature::add_threat(string type, int threat) {
	/* Will be implemented later */
    }
    
    void HeuristicSignature::change_threat(string type, int new_threat) {
	/* Will be implemented later */
    }
        
    
    void DatabaseHandler::load_database(ifstream is) {
	map<int, HeuristicSignature> temp_database();
	int id = 0;
	if (is.is_open()) {
	    while (is.good()) {
		string signature_string("");
		getline(is, signature_string);
		HeuristicSignature signature = parse_signature(signature_string);
		this->database.insert(pair<int, HeuristicSignature>(id, signature));
	    }
	}
    }
    
    HeuristicSignature DatabaseHandler::read_signature(int id) {
	//return this->database[id];
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
	string parameters_string = signature.substr(iter - signature.begin(), end_iter - iter);
	string wildcard_string("");
	map<string, int> parsed_threats;
	Wildcard wildcard;
	vector<string> parameters = split(parameters_string, ';');
	for (int i = 0; i < parameters.size(); ++i) {
	    vector<string> parsed_parameters = split(parameters[i], '=');
	    if (parsed_parameters[0] == "wildcard") {
		wildcard_string = parsed_parameters[1];
		wildcard = new Wildcard(wildcard_string);
	    }
	    if (parsed_parameters[0] == "type") {
		vector<string> types = split(parsed_parameters[i], ',');
		for (int j = 0; j < types.size(); ++j) {
		    vector<string> parsed_type = split(types[j], ':');
		    int type_threat = string_to_int(parsed_type[1]);
		    parsed_threats.insert(pair<string, int>(parsed_type[0], type_threat));
		}
	    }
	}
	HeuristicSignature result(wildcard, parsed_threats);
	return result;
    }

    map<int, HeuristicSignature>::iterator DatabaseHandler::begin() {
	map<int, HeuristicSignature>::iterator result = this->database.begin();
	return result;
    }

    map<int, HeuristicSignature>::iterator DatabaseHandler::end() {
	map<int, HeuristicSignature>::iterator result = this->database.end();
	return result;
    }

}	
