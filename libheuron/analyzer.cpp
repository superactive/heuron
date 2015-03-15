/*
  -------------------------------------------------------------------------
  Name: analyzer.cpp
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Weight-based infection analyzer module.
  -------------------------------------------------------------------------
*/

#include <vector>
#include "dbhandler.h"
#include "analyzer.h"

using namespace std;

namespace heuron {
    
    // MAYBE NOT int, BUT string <ERROR>, <CLEAN> ...
    int weight_based_check(vector<HeuristicSignature> sigarray, string threat_type) {
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
	int total_weight = 0;
	for(int i = 0; i < sigarray.size(); ++i) {
	    total_weight += sigarray[i].get_threat(threat_type);
	}
	if (total_weight >= INFECTED_WEIGHT) {
	    return 1;
	} else if (total_weight >= SUSPICIOUS_WEIGHT) {
	    return -1;
	}
	return 0;
    }
}
