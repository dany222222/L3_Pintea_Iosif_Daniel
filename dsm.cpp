//
// Created by Home on 3/28/2024.
//

#include "dsm.h"
#include <stdexcept>

// Constructor 1
DSM::DSM(int elementCount) {
    element_names = new string[elementCount];
    adjacency_matrix = new float*[elementCount];
    for (int i = 0; i < elementCount; ++i)
        adjacency_matrix[i] = new float[elementCount]();
    size = elementCount;
}

// Constructor 2
DSM::DSM(vector<string> element_names) {
    size = element_names.size();
    this->element_names = new string[size];
    for (int i = 0; i < size; ++i)
        this->element_names[i] = element_names[i];
    adjacency_matrix = new float*[size];
    for (int i = 0; i < size; ++i)
        adjacency_matrix[i] = new float[size]();
}

// Destructor
DSM::~DSM() {
    delete[] element_names;
    for (int i = 0; i < size; ++i)
        delete[] adjacency_matrix[i];
    delete[] adjacency_matrix;
}

// Copy constructor
DSM::DSM(const DSM& other) {
    size = other.size;
    element_names = new string[size];
    for (int i = 0; i < size; ++i)
        element_names[i] = other.element_names[i];
    adjacency_matrix = new float*[size];
    for (int i = 0; i < size; ++i) {
        adjacency_matrix[i] = new float[size];
        for (int j = 0; j < size; ++j)
            adjacency_matrix[i][j] = other.adjacency_matrix[i][j];
    }
}

// METODE
int DSM::find_index(string name) const {
    for (int i = 0; i < size; i++)
        if (element_names[i] == name)
            return i;
    return -1;
}

string DSM::get_name(int index) {
    if (index >= 0 && index < size)
        return element_names[index];
    else
        throw out_of_range("Index is out of range");
}

void DSM::set_element_name(int index, string name) {
    if (index >= 0 && index < size)
        element_names[index] = name;
    else
        throw out_of_range("Index is out of range");
}

void DSM::add_link(string from_element, string to_element, float weight) {
    int from_index = find_index(from_element);
    int to_index = find_index(to_element);
    if (from_index == -1) {
        // Resize element_names
        string* temp_names = new string[size + 1];
        for (int i = 0; i < size; ++i)
            temp_names[i] = element_names[i];
        temp_names[size] = from_element;
        delete[] element_names;
        element_names = temp_names;

        // Resize adjacency_matrix
        float** temp_matrix = new float*[size + 1];
        for (int i = 0; i <= size; ++i)
            temp_matrix[i] = new float[size + 1]();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                temp_matrix[i][j] = adjacency_matrix[i][j];
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
        adjacency_matrix = temp_matrix;

        from_index = size;
        size++;
    }

    if (to_index == -1) {
        // Resize element_names
        string* temp_names = new string[size + 1];
        for (int i = 0; i < size; ++i)
            temp_names[i] = element_names[i];
        temp_names[size] = to_element;
        delete[] element_names;
        element_names = temp_names;

        // Resize adjacency_matrix
        float** temp_matrix = new float*[size + 1];
        for (int i = 0; i <= size; ++i)
            temp_matrix[i] = new float[size + 1]();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                temp_matrix[i][j] = adjacency_matrix[i][j];
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
        adjacency_matrix = temp_matrix;

        to_index = size;
        size++;
    }

    adjacency_matrix[from_index][to_index] = weight;
}

void DSM::delete_link(string from_element, string to_element) {
    int from_index = find_index(from_element);
    int to_index = find_index(to_element);
    if (from_index != -1 && to_index != -1)
        adjacency_matrix[from_index][to_index] = 0.0;
}

bool DSM::have_link(string from_element, string to_element) {
    int from_index = find_index(from_element);
    int to_index = find_index(to_element);
    if (from_index != -1 && to_index != -1 && adjacency_matrix[from_index][to_index] != 0.0f)
        return true;
    return false;
}

float DSM::link_weight(string from_element, string to_element) {
    int from_index = find_index(from_element);
    int to_index = find_index(to_element);
    if (from_index != -1 && to_index != -1)
        return adjacency_matrix[from_index][to_index];
    return 0.0;
}

int DSM::count_to_links(string element_name) {
    int index = find_index(element_name);
    if (index != -1) {
        int count = 0;
        for (int i = 0; i < size; i++)
            if (adjacency_matrix[i][index] != 0.0)
                count++;
        return count;
    }
    return 0;
}

int DSM::count_from_links(string element_name) {
    int index = find_index(element_name);
    if (index != -1) {
        int count = 0;
        for (int j = 0; j < size; j++)
            if (adjacency_matrix[index][j] != 0.0)
                count++;
        return count;
    }
    return 0;
}

int DSM::count_all_links() {
    int count = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i != j && adjacency_matrix[i][j] != 0.0)
                count++;
    return count;
}
