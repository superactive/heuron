/*
  -------------------------------------------------------------------------
  Name: dbhandler.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  This module consists routines to work with heuristic signatures database.
  -------------------------------------------------------------------------
*/

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

}	
