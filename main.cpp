#include "data.h"
#include <time.h>
#include <iostream>

#include "localSearch.h"
int main(){

    char *argv[2];

    argv[0] = (char *) "TSP";
    argv[1] = (char *) "instancias/eil51.tsp";

    srand(time(NULL));

    Data & data = Data::getInstance();

    data.read(2, argv);

    Solution s = solve();

    s.print();

  
    return 0;
}