#include <iostream>
using namespace std;

/*
enQueue(q, x):

While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.

deQueue(q):

If stack1 is empty then error
Pop an item from stack1

*/

struct Node{
    int data;
    Node *next;
};

// Remove First
Node *Pop(Node *head){
    if (head == NULL){
        return NULL;
    }
    Node *oldNode = head;
    head = head->next;

    delete oldNode;
    return head;
}

// Add First
Node *Push(Node *head, int x){
    if (head == NULL){
        Node* head = new Node;
        head->data = x;
        head->next = NULL;
        return head;
    }
    Node *newNode = new Node;
    newNode->next = head;
    newNode->data = x;
    head = newNode;
    return head;
}

void print(Node *head){
    for (Node *p = head; p != NULL; p = p->next){
        cout << p->data <<  " ";
    }
    cout << endl;
}

void enQueue(Node *stack1, Node *stack2, int x){
    while(stack1 != NULL){
        stack2 = Push(stack2, stack1->data);
        stack1 = Pop(stack1);
    }

    stack1 = Push(stack1, x);
    while(stack2 != NULL){
        stack1 = Push(stack1, stack2->data);
        stack2 = Pop(stack2);
    }
}

Node *deQueue(Node *stack1){
    stack1 = Pop(stack1);
    return stack1;
}

int main (){
    Node *stack1 = NULL;
    Node *stack2 = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        stack1 = Push(stack1, x);
    }
    print(stack1);

    // Test
    int x; cin >> x;
    enQueue(stack1, stack2, x);
    print(stack1);
    stack1 = deQueue(stack1);
    print(stack1);

    return 0;
}

