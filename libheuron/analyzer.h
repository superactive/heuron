/*
  -------------------------------------------------------------------------
  Name: analyzer.h
  Author: vurmux@gmail.com
  -------------------------------------------------------------------------
  Weight-based infection analyzer module.
  TODO: Make threat types difference
  -------------------------------------------------------------------------
*/

#include "dbhandler.h"

using namespace std;

namespace heuron {
    
    int SUSPICIOUS_WEIGHT = 50;
    int INFECTED_WEIGHT = 100;
    
    int weight_based_check(HeuristicSignature *sigarray);

}
