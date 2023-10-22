//
// Created by dell on 2023/10/21.
//

#ifndef PROJECT2_INCREMENTAL_ALGORITHM_H
#define PROJECT2_INCREMENTAL_ALGORITHM_H

#include <vector>
#include "./data_instance.h"
using namespace std;

class incremental_algorithm {
private:
    double gamma_guess = 0.0;
public:
    incremental_algorithm();
    vector<double> run_incremental_algorithm(vector<struct data_instance*>& data_set);
    double get_gamma() const;
    void set_gamma(double gamma);

};

#endif //PROJECT2_INCREMENTAL_ALGORITHM_H
