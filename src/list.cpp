#include "list.h"
#include <stdexcept>
using namespace std;

LinkedList::LinkedList() = default;


LinkedList::LinkedList(const LinkedList& other) {
    head = deepCopy(other.head);
}


LinkedList& LinkedList::operator=(LinkedList rhs) {
    std::swap(head, rhs.head);
    return *this;
}

// frees all allocated memory
LinkedList::~LinkedList() {
    freeChain(head);
}

// Adds a new node to the front of the list
void LinkedList::prepend(int value) {
    head = new Node{value, head};
}

// Adds a new node to the end of the list
void LinkedList::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Removes the front node and returns  value
int LinkedList::removeFront() {
    if (isEmpty()) throw runtime_error("removeFront on empty list");
    int val = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return val;
}

// Checking if the list is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Prints the list in a readable format
void LinkedList::print(ostream& out) const {
    out << '[';
    for (Node* cur = head; cur; cur = cur->next) {
        out << cur->data;
        if (cur->next) out << " → ";
    }
    out << ']';
}

//creates a deep copy of the node chain with recursion
LinkedList::Node* LinkedList::deepCopy(Node* src) {
    if (!src) return nullptr;
    Node* newNode = new Node{src->data, deepCopy(src->next)};
    return newNode;
}

// Iteratively frees the entire node chain
void LinkedList::freeChain(Node* n) {
    while (n) {
            Node* next = n->next;
            delete n;
            n = next;
        }
}
