#include <iostream>
using namespace std;

class Node {
    Node *next;
    int data;

public:
    Node(Node *next, int data) {
        this->next = next;
        this->data = data;
    }

    void addNode(Node *nextPtr, int data) {
        if (this->next == NULL) {
            this->next = new Node(nextPtr, data);
        } else {
            this->next->addNode(nextPtr, data);
        }
    }

    int findLongestWay() {
        if (this->next == NULL) {
            return this->data;
        }
        
        return this->data + this->next->findLongestWay();
    }

    void display() {
        cout << this->data << (this->next ? " -> " : "");
        if (this->next != NULL) {
            this->next->display();
        }
    }
};

int main() {
    Node ob1(NULL, 2);
    ob1.addNode(NULL, 5);
    ob1.addNode(NULL, 10);
    ob1.addNode(NULL, 20);

    ob1.display();
    cout << endl;

    int total = ob1.findLongestWay();
    cout << "The Longest Way: " << total << endl;

    return 0;
}
