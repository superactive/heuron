/*
  -------------------------------------------------------------------------
  Name: dbhandler.cpp
  Author: kanzou@yandex.ru
  -------------------------------------------------------------------------
  This module consists routines to work with heuristic signatures database.
  -------------------------------------------------------------------------
  
  
*/

#include"dbhandler.h"
    
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
	
    }
    
    HeuristicSignature::change_threat(string type, int new_threat) {
	
    }
        
}	
