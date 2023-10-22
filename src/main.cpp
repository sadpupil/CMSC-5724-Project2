//
// Created by dell on 2023/10/21.
//

#include <vector>
#include <string>
#include "../include/data_reader.h"
#include "../include/incremental_algorithm.h"
#include "../include/result_verify.h"
using namespace std;

string data_resource[] = {
        R"(data/dataset_1.txt)",
        R"(data/dataset_2.txt)",
        R"(data/dataset_3.txt)"
};
incremental_algorithm tool;

void print_result(vector<struct data_instance*>& data_set, vector<double>& w) {
    size_t len = w.size();
    printf("linear classifier: w[");
    for(size_t i = 0; i < len; i++) {
        printf("%lf", w[i]);
        if(i < len - 1) {
            printf(",");
        }
    }
    printf("]\n");
    printf("margin of the classifier: %0.2f\n", get_margin(data_set, w));
    printf("final gamma guess: %0.2f\n", tool.get_gamma());
    printf("empirical error: %0.2f\n\n", get_empirical_err(data_set, w));
}

int main() {
    int cnt = 1;
    for(const string& str : data_resource) {
        printf("\n** DataSet %d **\n", cnt);
        data_reader reader(str);
        vector<struct data_instance*> res = reader.read_data();
        vector<double> w = tool.run_incremental_algorithm(res);
        print_result(res, w);
        cnt++;
    }
    return 0;
}
