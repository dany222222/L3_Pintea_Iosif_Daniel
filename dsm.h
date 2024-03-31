//
// Created by Home on 3/28/2024.
//

#ifndef L3_PINTEA_IOSIF_DANIEL_DSM_H
#define L3_PINTEA_IOSIF_DANIEL_DSM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DSM {
private:
    string* element_names;
    float** adjacency_matrix;
    int size;

    int find_index(string name) const;

public:
    DSM(int elementCount); //constructor 1
    DSM(vector<string> element_names); //constructor 2
    ~DSM(); //destructor
    DSM(const DSM& other); //copy constructor

    int getSize();
    string get_name(int index);
    void set_element_name(int index, string name);
    void add_link(string from_element, string to_element, float weight);
    void delete_link(string from_element, string to_element);

    bool have_link(string from_element, string to_element);
    float link_weight(string from_element, string to_element);
    int count_to_links(string element_name);
    int count_from_links(string element_name);
    int count_all_links();
};

#endif //L3_PINTEA_IOSIF_DANIEL_DSM_H
