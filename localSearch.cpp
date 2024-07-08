#include "localSearch.h"
#include "stdlib.h"
#include <iostream>

void RVND(Solution &s){

    std::vector<int> NL = {1};  // NL = {1, 2, 3, 4} após implementar os movimentos de vizinhança
    bool improved = false;

    while(NL.empty() == false){
        int n = (rand() % NL.size());

        switch(NL[n]){
            case 1:
                improved = bestImprovementSwap(s);
                break;
            case 2:
                improved = bestImprovement2Opt(s);
                break;
            case 3:
                improved = bestImprovementReinsertion(s);
                break;
            case 4:
                improved = bestImprovementOrOpt2(s);
                break;
            case 5:
                improved = bestImprovementOrOpt3(s);
                break;    
            default:
                break;
        }

        if (improved){
        NL = {1}; // NL = {1, 2, 3, 4} após implementar os movimentos de vizinhança
        }

        else{
            NL.erase(NL.begin() + n);
        }
    
    }
}

bool bestImprovementSwap(Solution &s){
    Data & data = Data::getInstance();
    double delta, bestDelta = 0.0;
    int bestI, bestJ, i, j;
    bool improved = false;

    for (i = 1; i < data.n - 1; i++){
        for(j = i + 1; j < data.n - 1; j++){
            delta = s.evaluateSwap(i, j);
            if(delta < bestDelta){
                bestDelta = delta;
                bestI = i;
                bestJ = j;
                improved = true;
            }
        }
    }

    if(improved){
        s.swap(bestI, bestJ);
    }

    return improved;
}

bool bestImprovement2Opt(Solution &s){
    Data & data = Data::getInstance();
    double delta, bestDelta = 0.0;
    int bestI, bestJ, i, j;
    bool improved = false;

    for (i = 1; i < data.n - 1; i++){
        for(j = i + 1; j < data.n - 1; j++){
            delta = s.evaluate2Opt(i, j); 
            if(delta < bestDelta){
                bestDelta = delta;
                bestI = i;
                bestJ = j;
                improved = true;
            }
        }
    }

    if(improved){
        s.two_opt(bestI, bestJ);
    }

    return improved;
}

bool bestImprovementReinsertion(Solution &s){
    Data & data = Data::getInstance();
    double delta, bestDelta = 0.0;
    int bestI, bestJ, i, j;
    bool improved = false;

    for (i = 1; i < data.n - 1; i++){      
        j = i + 1;  
        
        if(j < data.n - 1) {
            delta = s.evaluateSwap(i, j);
            if(delta < bestDelta){
                bestDelta = delta;
                bestI = i;
                bestJ = j;
                improved = true;
            }
        }
    }

    if(improved){
        s.swap(bestI, bestJ);
    }

    return improved;
}

bool bestImprovementOrOpt2(Solution &s){
    Data & data = Data::getInstance();
    double delta, bestDelta = 0.0;
    int bestI, bestJ, i, j;
    bool improved = false;

    for (i = 1; i < data.n - 2; i++){
        j = i + 2;
        
        if(j < data.n - 1){
            delta = s.evaluateOrOpt2(i, j);
            if(delta < bestDelta){
                bestDelta = delta;
                bestI = i;
                bestJ = j;
                improved = true;
            }

        }    
    }

    if(improved){
        s.orOpt2(bestI, bestJ);
    }

    return improved;
}

bool bestImprovementOrOpt3(Solution &s){
    Data & data = Data::getInstance();
    double delta, bestDelta = 0.0;
    int bestI, bestJ, i, j;
    bool improved = false;

    for (i = 1; i < data.n - 3; i++){
        j = i + 3;
        
        if(j < data.n - 1){
            delta = s.evaluateOrOpt2(i, j);
            if(delta < bestDelta){
                bestDelta = delta;
                bestI = i;
                bestJ = j;
                improved = true;
            }

        }    
    }

    if(improved){
        s.orOpt3(bestI, bestJ);
    }

    return improved;
}

Solution solve(){
    Solution s = Solution();
    s.buildTrivial();
    std::cout << "Solucao inicial:" << std::endl;
    s.print();
    std::cout << "Solucao final:" << std::endl;
    RVND(s);
    return s;
}