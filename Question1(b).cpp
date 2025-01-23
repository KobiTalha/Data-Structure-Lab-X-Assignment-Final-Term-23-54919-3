#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


struct Queue {
    Node *front, *rear;
    Queue() {
        front = rear = nullptr;
    }


    void enqueue(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }


    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }


    void reverse() {
        Node *prev = nullptr, *curr = front, *next = nullptr;
        rear = front;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        front = prev;
    }


    void print(bool reversed = false) {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue (Front to Rear): ";
    q.print();

    q.reverse();
    cout << "Queue (Rear to Front): ";
    q.print();

    return 0;
}
