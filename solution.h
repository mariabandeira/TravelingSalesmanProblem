#ifndef SOLUTION_H
#define SOLUTION_H


#include "data.h"
#include <vector>

struct Solution
{
    std::vector<int> route;
    double cost;

    Solution(std::vector<int> route, double cost): route(route), cost(cost) {}
    Solution() :  route(std::vector<int>(Data::getInstance().n + 1)), cost(0) {}
    Solution(const Solution &s) : route(s.route), cost(s.cost) {}

    void buildTrivial();

    void print();

    void copy(const Solution &other);

    double evaluateSwap(const int i, const int j);

    double evaluate2Opt(const int i, const int j);

    double evaluateOrOpt2(const int i, const int j);

    double evaluateOrOpt3(const int i, const int j);

    void swap(const int i, const int j);

    void two_opt(const int i, const int j);

    void orOpt2(const int i, const int j);

    void orOpt3(const int i, const int j);

};


#endif