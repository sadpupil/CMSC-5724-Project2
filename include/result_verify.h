//
// Created by dell on 2023/10/21.
//

#ifndef PROJECT2_RESULT_VERIFY_H
#define PROJECT2_RESULT_VERIFY_H

#include <vector>
#include "./data_instance.h"
using namespace std;

double get_margin(vector<struct data_instance*>& data_set, vector<double>& w);

double get_empirical_err(vector<struct data_instance*>& data_set, vector<double>& w);

#endif //PROJECT2_RESULT_VERIFY_H
