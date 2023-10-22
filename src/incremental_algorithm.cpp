//
// Created by dell on 2023/10/21.
//

#include <vector>
#include "../include/data_instance.h"
#include "../include/perceptron.h"
#include "../include/incremental_algorithm.h"
using namespace std;

double incremental_algorithm::get_gamma() const {
    return gamma_guess;
}

void incremental_algorithm::set_gamma(double gamma) {
    incremental_algorithm::gamma_guess = gamma;
}

incremental_algorithm::incremental_algorithm()= default;

vector<double> incremental_algorithm::run_incremental_algorithm(vector<struct data_instance*>& data_set) {
    struct data_instance* first = data_set[0];
    int d = first -> dimension;
    double r = first -> radius, gamma_g = r;
    vector<double> w(d, 0.0);
    bool flag = false;
    while(!flag) {
        flag = run_perceptron(data_set, w, gamma_g, r);
        gamma_g /= 2;
    }
    set_gamma(gamma_g * 2);
    return w;
}