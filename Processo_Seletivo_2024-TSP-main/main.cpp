#include "data.h"
#include <time.h>
#include <iostream>
#include <string>
#include <cstring>
#include "localSearch.h"
using namespace std;

int main(){
    string instancePath;
    cout << "Digite o caminho da instancia (ex: instancias/eil101.tsp): ";
    getline(cin, instancePath);

    char *argv[2];

    argv[0] = (char *) "TSP";
    argv[1] = const_cast<char*>(instancePath.c_str());

    srand(time(NULL));

    Data & data = Data::getInstance();

    data.read(2, argv);

    Solution s = solve();

    s.print();

    return 0;
}