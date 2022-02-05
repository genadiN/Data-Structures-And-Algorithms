#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int data;
    Node* previous;
    Node* next;
};


class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

   void my_push_back(int newElement) {
      Node* newNode = new Node();
      newNode->data = newElement;
      newNode->next = NULL;
      newNode->previous = NULL;
      if(head == NULL) {
        head = newNode;
      } else {
        Node* temp = head;
        while(temp->next != NULL)
          temp = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
      }
    }
    void gun() {
      if(head != NULL) {
        if(head->next == NULL) {
          head = NULL;
        } else {
          Node* temp = head;
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next;
          temp->next = NULL;
          delete lastNode;
        }
      }
    }

    void milen(){
        Node* temp = head;
        int counter = 0;
        while(temp != NULL){
            counter++;
            temp = temp->next;
        }
        temp = head;
        int p = 1 , mid = counter / 2;
        while(temp != NULL){
            if(p == mid){
                break;
            }
            p++;
            temp = temp->next;
        }
        Node* newTail = tail;
        while(head != temp ){
          head->next = nullptr;//1
          tail = head->previous;// 1 - previous
          head = head->next; // 2
          head->previous = nullptr; // 2 - previous
          tail->next = tail;
          temp = tail->previous;
        }
    }

    void printList() {
      Node* temp = head;
      if(temp != NULL) {
        while(temp != NULL) {
          cout<<temp->data<<" ";
          temp = temp->next;
        }
        cout<<endl;
      }else {
        cout << "0" ;
      }
    }
};

int main(){
    int n = 0 , number = 0 , counerGun = 0 , counterAdd = 0;
    cin >> n ;
    DoublyLinkedList node;
    string text = "";
    for(int i = 0 ; i < n ; i++){
        cin >> text;
        if(text == "add"){
            cin >> number;
            counterAdd++;
            node.my_push_back(number);
        }else if( text == "gun"){
            counerGun++;
            node.gun();
        }else if( text == "milen"){
            int middle = (counterAdd - counerGun) / 2 ;
            node.milen();
        }
    }
   node.printList();
return 0;
}
