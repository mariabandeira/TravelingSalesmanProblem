#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include "solution.h"

void RVND(Solution &s);

bool bestImprovementSwap(Solution &s);

bool bestImprovement2Opt(Solution &s);

bool bestImprovementReinsertion(Solution &s);

bool bestImprovementOrOpt2(Solution &s);

bool bestImprovementOrOpt3(Solution &s);

Solution solve();

#endif // LOCAL_SEARCH_H