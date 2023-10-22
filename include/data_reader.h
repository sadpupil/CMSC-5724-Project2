//
// Created by dell on 2023/10/21.
//

#ifndef PROJECT2_DATA_READER_H
#define PROJECT2_DATA_READER_H

#include <string>
#include <vector>
#include "./data_instance.h"
using namespace std;

class data_reader {
private:
    string data_file_path;
    static vector<string> split_string(string str);
public:
    explicit data_reader(string path);
    vector<struct data_instance*> read_data();
};

#endif //PROJECT2_DATA_READER_H
