/*
  -------------------------------------------------------------------------
  Name: analyzer.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Weight-based infection analyzer module.
  TODO: Make threat types difference
  -------------------------------------------------------------------------
*/

#include "dbhandler.h"


namespace heuron {
    
    int SUSPICIOUS_WEIGHT = 50;
    int INFECTED_WEIGHT = 100;
    
    // MAYBE NOT int, BUT string <ERROR>, <CLEAN> ...
    int weight_based_check(HeuristicSignature *sigarray) {
	/*
	  Infection check based on weights.
	  
	  Parameters:
	  HeuristicSignature *sigarray - array of signatures found in target

	  Result:
	  int result - ??? infected
	  0 - clear
	  -1 - suspicious
	  >0 - infected; return type of infection
	*/
	total_weight = 0;
	for(int i=0; i<len(sigarray); ++i) {
	    total_weight += sigarray[i].get_weigth(); // TODO: change !!!
	}
	if (total_weight >= INFECTED_WEIGHT) {
	    return 1;
	} else if (total_weight >= SUSPICIOUS_WEIGHT) {
	    return -1;
	}
	return 0;
    }
}
