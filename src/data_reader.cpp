//
// Created by dell on 2023/10/21.
//

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include "../include/data_reader.h"
using namespace std;

data_reader::data_reader(string path) {
    this -> data_file_path = std::move(path);
}

vector<string> data_reader::split_string(string str) {
    vector<string> result;
    size_t len = str.length(), i = 0;
    string tmp;
    // avoid \n or EOF
    while(i < len) {
        if(str[i] != ',') {
            tmp += str[i];
        }
        else {
            result.push_back(tmp);
            tmp.clear();
        }
        i++;
    }
    result.push_back(tmp);
    return result;
}

vector<data_instance*> data_reader::read_data() {
    vector<data_instance*> result;
    int cnt = 0, num_of_points, dimension;
    double radius;
    ifstream file(this -> data_file_path);
    if(file.is_open()) {
        string line_data;
        while(getline(file, line_data)) {
            vector<string> content = split_string(line_data);
            size_t len = content.size();
            if(cnt == 0 && len == 3) {
                dimension = stoi(content[0]);
                num_of_points = stoi(content[1]);
                radius = stod(content[2]);
            }
            else {
                vector<double> coord(len - 1);
                for(size_t i = 0; i < len - 1; i++) {
                    coord[i] = stod(content[i]);
                }
                auto* new_data = new data_instance;
                new_data -> label = stoi(content[len - 1]);
                new_data -> dimension = dimension;
                new_data -> radius = radius;
                new_data -> num_of_points = num_of_points;
                new_data -> coordinates = coord;
                result.push_back(new_data);
            }
            cnt++;
        }
        file.close();
    }
    else {
        cout << "file open error" << endl;
    }
    return result;
}
