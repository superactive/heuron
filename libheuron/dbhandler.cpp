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
    
    HeuristicSignature::get_signature() {
	return this->signature;
    }
    
    HeuristicSignature::set_signature(string signature) {
	this->signature = signature;
    }
    
    HeuristicSignature::add_threat(string type, int threat) {
	/* Will be implemented later */
    }
    
    HeuristicSignature::change_threat(string type, int new_threat) {
	/* Will be implemented later */
    }
        
}	
