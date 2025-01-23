#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
struct Node {
    char data;
    Node* next;
    Node(char x) {
        data = x;
        next = nullptr;
    }
};
Node* top = nullptr;
void push(char x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
}
char pop() {
    if (top == nullptr) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    char data = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return data;
}
char peek() {
    return top ? top->data : '\0';
}
bool isEmpty() {
    return top == nullptr;
}
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}
void reverse(char* e) {
    int len = strlen(e);
    for (int i = 0; i < len / 2; i++) {
        swap(e[i], e[len - i - 1]);
    }
}
void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            prefix[j++] = ch;
        } else if (ch == ')') {
            push(ch);
        } else if (ch == '(') {
            while (!isEmpty() && peek() != ')') {
                prefix[j++] = pop();
            }
            pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }
    while (!isEmpty()) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
    reverse(prefix);
}
struct NumNode {
    int data;
    NumNode* next;

    NumNode(int x) {
        data = x;
        next = nullptr;
    }
};
NumNode* numTop = nullptr;
void numPush(int x) {
    NumNode* newNode = new NumNode(x);
    newNode->next = numTop;
    numTop = newNode;
}
int numPop() {
    if (numTop == nullptr) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    int data = numTop->data;
    NumNode* temp = numTop;
    numTop = numTop->next;
    delete temp;
    return data;
}
bool numIsEmpty() {
    return numTop == nullptr;
}
int evaluatePrefix(char* prefix) {
    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch)) {
            numPush(ch - '0');
        } else {
            int op1 = numPop();
            int op2 = numPop();
            switch (ch) {
                case '+': numPush(op1 + op2); break;
                case '-': numPush(op1 - op2); break;
                case '*': numPush(op1 * op2); break;
                case '/': numPush(op1 / op2); break;
                case '^': numPush(pow(op1, op2)); break;
            }
        }
    }
    return numPop();
}
int main() {
    char infix[50], prefix[50];
    cout << "Enter the infix expression: ";
    cin >> infix;
    infixToPrefix(infix, prefix);
    cout << "Prefix Expression: " << prefix << endl;
    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;
return 0;
}
