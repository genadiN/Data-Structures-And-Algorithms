#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* head){
    if(head == NULL){
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

void splitAndPrint(Node* head , int p , int q){
    int n = 0;
    Node* temp;
    temp = head;

    while(temp != NULL){
        n +=1;
        temp = temp->next;
    }

    if(p + q > n){
        cout << "-1" << endl;
        return ;
    }
    temp = head;
    while(p > 1){
        temp = temp->next;
        p--;
    }

    Node* head2 = temp->next;
    temp->next = NULL;

    printList(head);
    cout << endl;
    printList(head2);
}

int main(){
  Node* head = new Node(1);
  head->next = new Node(3);
  head->next->next = new Node(5);
  head->next->next->next = new Node(6);
  head->next->next->next->next = new Node(7);
  head->next->next->next->next->next = new Node(2);

    int p = 2 , q = 4;
    splitAndPrint(head , p , q);
}
