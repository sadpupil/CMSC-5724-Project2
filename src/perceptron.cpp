//
// Created by dell on 2023/10/21.
//

#include <vector>
#include <cmath>
#include "../include/vector_op.h"
#include "../include/data_instance.h"
using namespace std;

bool run_perceptron(vector<struct data_instance*>& data_set, vector<double>& w, double gamma_guess, double radius) {
    int most_itr = (int) (12 * pow(radius, 2) / pow(gamma_guess, 2));
    int rounds = 0;
    size_t len = data_set.size();
    while(rounds < most_itr) {
        int n = 0;
        for(size_t i = 0; i < len && n == 0; i++) {
            vector<double> p = data_set[i] -> coordinates;
            int l = data_set[i] -> label;
            double dot_product = vector_dot_product(w, p);
            double distance = abs(dot_product) / vector_magnitude(w);
            if((l == -1 && dot_product >= 0) || (l == 1 && dot_product <= 0) || (distance < gamma_guess / 2)) {
                // p is a violation point
                if(l == 1) {
                    // w = w + p
                    vector_add(w, p);
                }
                else {
                    // w = w - p;
                    vector_sub(w, p);
                }
                n++;
            }
        }
        if(n == 0) {
            return true;
        }
        rounds++;
    }
    return false;
}
