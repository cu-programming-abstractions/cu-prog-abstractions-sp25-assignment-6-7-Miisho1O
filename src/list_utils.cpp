#include "list.h"
#include <stdexcept>
using namespace std;


int length(const LinkedList& list) {
    int count = 0;
    LinkedList temp = list;
    while (!temp.isEmpty()) {
        temp.removeFront();
        count++;
    }
    return count;
}

// Returns the sum of elements in the list
int sum(const LinkedList& list) {
    int total = 0;
    LinkedList temp = list;
    while (!temp.isEmpty()) {
        total += temp.removeFront();
    }
    return total;
}

// Returns true if the list contains the value k
bool contains(const LinkedList& list, int k) {
    LinkedList temp = list;
    while (!temp.isEmpty()) {
        if (temp.removeFront() == k) return true;
    }
    return false;
}

// Reverses the order of elements in the list
void reverse(LinkedList& list) {
    LinkedList reversed;
    while (!list.isEmpty()) {
        reversed.prepend(list.removeFront());
    }
    list = reversed;
}

// returns the nth element from the end of the list (1-based index)
// throws exception if n is invalid or too large
int nthFromEnd(const LinkedList& list, int n) {
    if (n <= 0) throw out_of_range("Invalid n: n must be positive");

    LinkedList temp1 = list;
    LinkedList temp2 = list;


    for (int i = 0; i < n; ++i) {
        if (temp1.isEmpty()) {
            throw out_of_range("Invalid n: n is larger than list length");
        }
        temp1.removeFront();
    }


    while (!temp1.isEmpty()) {
        temp1.removeFront();
        temp2.removeFront();
    }

    if (temp2.isEmpty()) throw out_of_range("Invalid n");

    return temp2.removeFront();
}
