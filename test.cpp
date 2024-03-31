//
// Created by Home on 3/28/2024.
//
#include <iostream>
#include "dsm.h"

using namespace std;

int main() {
    DSM dsm(5);
    dsm.set_element_name(0, "A");
    dsm.set_element_name(1, "B");
    dsm.set_element_name(2, "C");
    dsm.set_element_name(3, "D");
    dsm.set_element_name(4, "E");

    dsm.add_link("A", "B", 5.1);
    dsm.add_link("D", "C", 8.5);
    dsm.add_link("E", "A", 1.2);
    dsm.add_link("A", "C", 0.5);
    dsm.add_link("E", "C", 2);
    dsm.add_link("C", "B", 1);
    dsm.add_link("A", "D", 10.2);

   // cout << "Size of DSM is: " << dsm.size() << endl;
    cout << dsm.get_name(1) << " is the name of the index 1" << endl;
    cout << "Link weight between A and B is: " << dsm.link_weight("A", "C") << endl;
    cout << "Number of FROM_links of A is: " << dsm.count_from_links("A") << endl; //3
    cout << "Number of TO_links of C is: " << dsm.count_to_links("C") << endl;     //2
    cout << "Total number of links is: " << dsm.count_all_links() << endl;
    cout << endl;

    dsm.delete_link("A", "B");
    cout << "Link between A and B was deleted " << endl;
    dsm.add_link("A", "B", 1.8);
    cout << "New link between A and B was created " << endl;

    if (dsm.have_link("A", "B"))
        cout << "Between A and B exists a link" << endl;
    else
        cout << "Between A and B does not exist a link" << endl;
    dsm.add_link("A", "E", 6.8);
    cout << "Link between A and C has been added" << endl;

    return 0;
}
