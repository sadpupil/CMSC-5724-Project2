//
// Created by dell on 2023/10/21.
//


#include <vector>
#include <limits>
#include <cmath>
#include "../include/vector_op.h"
#include "../include/data_instance.h"
#include "../include/result_verify.h"
using namespace std;

double get_margin(vector<struct data_instance*>& data_set, vector<double>& w) {
    double margin = numeric_limits<double>::max();
    for(const auto& data : data_set) {
        double tmp = abs(vector_dot_product(data -> coordinates, w)) / vector_magnitude(w);
        margin = min(margin, tmp);
    }
    return margin;
}

double get_empirical_err(vector<struct data_instance*>& data_set, vector<double>& w) {
    int n = data_set[0] -> num_of_points, wrong = 0;
    for(int i = 0; i < n; i++) {
        int label = data_set[i] -> label;
        if((label == 1 && vector_dot_product(data_set[i] -> coordinates, w) <= 0) ||
            (label == -1 && vector_dot_product(data_set[i] -> coordinates, w) >= 0)) {
            wrong++;
        }
    }
    return (double) (wrong / n);
}