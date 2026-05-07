#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    void addList(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeList(int data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << slow->data << endl;
    }

    void mergeList(List &list) {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = list.head;
        list.head = nullptr;
    }

    void clearList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

};

int main() {
    List ob1;
    ob1.addList(10);
    ob1.addList(15);
    ob1.addList(3);
    ob1.addList(13);
    
    ob1.removeList(15);
        
    List ob2;
    ob2.addList(20);
    ob2.addList(25);
    ob2.addList(30);

    cout << "List 1: ";
    ob1.printList();
    cout << "List 2: ";
    ob2.printList();

    cout << "Middle element of List 1: ";
    ob1.findMiddle();
    cout << "Middle element of List 2: ";
    ob2.findMiddle();

    ob1.mergeList(ob2);
    cout << "Merged List: ";
    ob1.printList();

    ob1.clearList();
    ob2.clearList();

	return 0;
}