//
// Created by dell on 2023/10/21.
//

#ifndef PROJECT2_PERCEPTRON_H
#define PROJECT2_PERCEPTRON_H

#include <vector>
#include "./data_instance.h"
using namespace std;

bool run_perceptron(vector<struct data_instance*>& data_set, vector<double>& w, double gamma_guess, double radius);

#endif //PROJECT2_PERCEPTRON_H
