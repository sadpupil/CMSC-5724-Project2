//
// Created by dell on 2023/10/21.
//

#ifndef PROJECT2_DATA_INSTANCE_H
#define PROJECT2_DATA_INSTANCE_H

#include <vector>

struct data_instance {
    int label;
    int dimension;
    int num_of_points;
    double radius;
    std::vector<double> coordinates;
};

#endif //PROJECT2_DATA_INSTANCE_H
