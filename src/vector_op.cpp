//
// Created by dell on 2023/10/21.
//


#include <vector>
#include <cmath>
#include "../include/vector_op.h"
using namespace std;

void vector_add(vector<double>& w, vector<double>& p) {
    int len = w.size();
    for(int i = 0; i < len; i++) {
        w[i] += p[i];
    }
}

void vector_sub(vector<double>& w, vector<double>& p) {
    int len = w.size();
    for(int i = 0; i < len; i++) {
        w[i] -= p[i];
    }
}

double vector_dot_product(vector<double>& w, vector<double>& p) {
    int len = w.size();
    double res = 0.0;
    for(int i = 0; i < len; i++) {
        res += w[i] * p[i];
    }
    return res;
}

double vector_magnitude(vector<double>& w) {
    double res = 0.0;
    for(const auto& v : w) {
        res += v * v;
    }
    return sqrt(res);
}