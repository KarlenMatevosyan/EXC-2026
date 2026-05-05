#include <iostream>
#include <algorithm> 
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

    int findShortestWay() {
        if (this->next == NULL) {
            return 0; 
        }

        int currentPairSum = this->data + this->next->data;

        if (this->next->next == NULL) {
            return currentPairSum;
        }

        int nextMinSum = this->next->findShortestWay();

        return (currentPairSum < nextMinSum) ? currentPairSum : nextMinSum;
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

    int shortest = ob1.findShortestWay();
    cout << "The Shortest Way: " << shortest << endl;

    return 0;
}
