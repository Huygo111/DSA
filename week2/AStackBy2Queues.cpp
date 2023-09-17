#include <iostream>
using namespace std;

//Follow the below steps to implement the push(s, x) operation:
//Enqueue x to q2.
//One by one dequeue everything from q1 and enqueue to q2.
//Swap the queues of q1 and q2.
//Follow the below steps to implement the pop(s) operation:
//Dequeue an item from q1

struct Node{
    int data;
    Node *next;
};

// insert x at the tail of the queue
Node *enqueue (Node *head, int data){
    if (head == NULL){
        Node *head = new Node;
        head->data = data;
        head->next = NULL;
        return head;
    }
    else {
        Node *NewNode = new Node;
        NewNode->data = data;
        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = NewNode;
        NewNode->next = NULL;
        return head;
    }
}

// delete the first element of the queue
Node *dequeue(Node *head){
    if (head == NULL){
        return NULL;
    }
    Node *oldNode = head;
    head = head->next;

    delete oldNode;
    return head;
}

void print(Node *head){
    for (Node *p = head; p != NULL; p = p->next){
        cout << p->data <<  " ";
    }
    cout << endl;
}

Node *Push(Node *queue1, Node *queue2, int x){
    queue2 = enqueue(queue2, x);
    while(queue1 != NULL){
        queue2 = enqueue(queue2, queue1->data);
        queue1 = dequeue(queue1);
    }

    queue1 = queue2;
    queue2 = NULL;

    return queue1;
}

Node *Pop(Node *queue1){
    queue1 = dequeue(queue1);

    return queue1;
}

int main(){
    Node *queue1 = NULL;
    Node *queue2 = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        //int x; cin >> x;
        queue1 = enqueue(queue1, i);
    }
    print(queue1);

    // Test
    queue1 = Push(queue1, queue2, 7);
    queue1 = Push(queue1, queue2, 8);
    print(queue1);
    queue1 = dequeue(queue1);
    queue1 = dequeue(queue1);
    print(queue1);

    return 0;
}
