#include<iostream>
#include<assert.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void MoveNode(Node** destRef , Node** sourceRef){
    Node* newNode = *sourceRef;
    assert(newNode != NULL);

    /// Advance the source pointer
    *sourceRef = newNode -> next;

    ///Link the old destination off the new node
    newNode->next = *destRef;

    ///Move destination to print to the new node
    *destRef = newNode;
}

Node* sortMerge(Node* a , Node* b){
    Node dummy;

    Node* tail = &dummy;
    dummy.next = NULL;

    while(1){
        if( a == NULL){
            tail->next = b;
            break;
        }else if( b == NULL){
            tail->next = a;
            break;
        }
        if(a->data <= b->data){
            MoveNode(&(tail->next) , &a);
        }else{
            MoveNode(&(tail->next) , &b);
        }

        tail = tail->next;
    }
    return (dummy.next);
}

void push(Node** headRef , int newData){
    Node* newNode = new Node();

    newNode -> data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void printList(Node* node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

int main(){
    Node* res = NULL;
    Node* a = NULL;
    Node* b = NULL;

    push(&a , 15);
    push(&a , 10);
    push(&a , 5);

    push(&b , 20);
    push(&b , 3);
    push(&b , 2);

    res = sortMerge(a , b);

    cout << "Merged Linked list is:\n";
    printList(res);
}
